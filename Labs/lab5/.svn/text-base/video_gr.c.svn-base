#include <minix/syslib.h>
#include <minix/drivers.h>
#include <machine/int86.h>
#include <sys/mman.h>
#include <sys/types.h>
#include "video_gr.h"


#include "vbe.h"

/* Constants for VBE 0x105 mode */

/* The physical address may vary from VM to VM.
 * At one time it was 0xD0000000
 *  #define VRAM_PHYS_ADDR    0xD0000000 
 * Currently on lab B107 is 0xF0000000
 * Better run my version of lab5 as follows:
 *     service run `pwd`/lab5 -args "mode 0x105"
 */
#define VRAM_PHYS_ADDR	0xE0000000
#define H_RES             1024
#define V_RES		  768
#define BITS_PER_PIXEL	  8

/* Private global variables */

static char *video_mem;		/* Process address to which VRAM is mapped */

static unsigned h_res;		/* Horizontal screen resolution in pixels */
static unsigned v_res;		/* Vertical screen resolution in pixels */
static unsigned bits_per_pixel; /* Number of VRAM bits per pixel */

int video_exit() {
  struct reg86u reg86;

  reg86.u.b.intno = 0x10; /* BIOS video services */

  reg86.u.b.ah = 0x00;    /* Set Video Mode function */
  reg86.u.b.al = 0x03;    /* 80x25 text mode*/

  if( sys_int86(&reg86) != OK ) {
      printf("\tvg_exit(): sys_int86() failed \n");
      return 1;
  } else
      return 0;
}

int drawPixel(unsigned long x, unsigned long y, unsigned long color) {

	if(x < 0 || x >= h_res || y < 0 || y >= v_res)
		return -1;

	else
	{
		*(video_mem + y*h_res + x) = color;

		return 0;
	}
}

//algoritmo de bresenham alterado para funcionar com as nossas funçoes
void bresenham(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, unsigned long cor)
{
       int slope;
       int dx, dy, incE, incNE, d, x, y;
       // Onde inverte a linha x1 > x2
       if (x1 > x2){
           bresenham(x2, y2, x1, y1, cor);
            return;
       }
       dx = x2 - x1;
       dy = y2 - y1;

       if (dy < 0){
           slope = -1;
           dy = -dy;
       }
       else{
          slope = 1;
       }
       // Constante de Bresenham
       incE = 2 * dy;
       incNE = 2 * dy - 2 * dx;
       d = 2 * dy - dx;
       y = y1;
       for (x = x1; x <= x2; x++){
    	   drawPixel(x, y, cor);
           if (d <= 0){
             d += incE;
           }
           else{
             d += incNE;
             y += slope;
           }
       }
 }

void drawnVerticalLine(unsigned short x, unsigned short y1, unsigned short y2, unsigned short cor)
{
	while(y1!=y2)
	{
		drawPixel(x, y1, 2);
		y1++;
	}
}

int drawLine(unsigned short xi, unsigned short yi,
		unsigned short xf, unsigned short yf, unsigned long color)
{
	if(xi < 0 || xi >= h_res || yi < 0 || yi >= v_res || xf < 0 || xf >= h_res || yf< 0 || yf >= v_res )
		return -1;

	if(xi==xf)//linha vertical
		drawnVerticalLine(xi, yi, yf, color);

	bresenham(xi, yi, xf, yf, color);
	return 0;
}


void *video_init(unsigned short mode)
{
	int r;
	h_res=H_RES;
	v_res=V_RES;
	bits_per_pixel=BITS_PER_PIXEL;
	struct mem_range range;
	struct reg86u reg86;

	reg86.u.b.intno = 0x10; /* BIOS video services */
	reg86.u.b.ah = 0x4f;    /* Set Video Mode function */
	reg86.u.b.al = 0x02;    /* 80x25 text mode*/
	//reg86.u.w.ax = 0x4F02; /*VBE call, function 02 -- set VBE mode*/
	reg86.u.w.bx = (1<<14)|mode; /*set bit 14: linear framebuffer*/

	if( sys_int86(&reg86) != OK ) {
		printf("set_vbe_mode: sys_int86() failed \n");
		}

	range.mr_base = (phys_bytes)(VRAM_PHYS_ADDR);
	range.mr_limit = range.mr_base + h_res* v_res;

	if((r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &range)) != OK)
		panic("video_txt: sys_privctl failed: %d\n", r);

	video_mem = vm_map_phys(SELF, (void *)range.mr_base, h_res* v_res);
	if(video_mem == MAP_FAILED){
		panic("video_txt couldn't map video memory");
		return NULL;}

	return video_mem;
}

void drawXPM(unsigned short xi, unsigned short yi, char *xpm[])
{
	int width, height;

	char *place;
	// get the pixmap from the XPM
	place = (char*)read_xpm(xpm,
			&width,
			&height);

	//printf("w %d",width);
	//printf("h %d", height);
	//ciclos para cobrir os pixeis (altura x largura da imagem)
	unsigned int i;
	unsigned int j;
	int indice=0;
	for(i=0; i< width; i++)
	{
		for(j=0; j<height; j++)
		{
			drawPixel(xi+j, yi+i, (int)place[indice]);
			indice++;
		}
	}
}

void getSprite(Sprite *sp, unsigned short xi, unsigned short yi, char *xpm[], unsigned short hor, double pxPrInt)
{
		char *place;
		int xpm_width;
		int xpm_height;

		place = (char*)read_xpm(xpm, &xpm_width, &xpm_height);

		//printf("before %d\n", xi);
		sp->x = (double)xi;
		if(sp->x != 0)
			//printf("after %d\n", sp->x);
		sp->y = (double)yi;
		sp->width = xpm_width;
		sp->height = xpm_height;
		if (hor)
		{
			sp->yspeed = 0;
			sp->xspeed = (double)pxPrInt;
			//printf("SPEED: %d\n", sp->xspeed);
		}
		else
		{
			sp->xspeed = 0;
			sp->yspeed = (double)pxPrInt;
		}
		sp->map = place;
}

int drawSp(Sprite *sp)
{
	unsigned int i;
	unsigned int j;
	int indice=0;

	for(i=0; i< sp->width; i++)
	{
		for(j=0; j<sp->height; j++)
		{
			if (drawPixel(sp->x+j, sp->y+i, sp->map[indice]))
			{
				//printf("x %d \n", sp->x);
				//printf("y %d \n", sp->y);
				printf("Mas coordenadas!\n");
				return -1;
			}
			indice++;
		}
	}
	return  0;
}

int deleteSp(Sprite *sp)
{
	unsigned int i;
	unsigned int j;

	for(i=0; i< sp->width; i++)
	{
		for(j=0; j<sp->height; j++)
		{
			if (drawPixel(sp->x+j, sp->y+i, 0))
			{
				//printf("x %d \n", sp->x);
				//printf("y %d \n", sp->y);
				printf("Mas coordenadas!\n");
				return -1;
			}
		}
	}
	return  0;
}
