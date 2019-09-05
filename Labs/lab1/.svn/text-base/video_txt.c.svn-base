#include <minix/drivers.h>
#include <sys/video.h>
#include <sys/mman.h>

#include <assert.h>
#include <stdio.h>

#include "vt_info.h"

#include "video_txt.h"

/* Private global variables */

static char *video_mem;		/* Address to which VRAM is mapped */

static unsigned scr_width;	/* Width of screen in columns */
static unsigned scr_lines;	/* Height of screen in lines */

void vt_fill(char ch, char attr) {

	char *endereco;		//apontador do endereço
	endereco = video_mem;	//fica a apontar para o inicio

	int y;
	int x;

	for (y = 0; y < scr_lines; y++)
	{
		for (x = 0; x < scr_width; x++)
		{
			//row 1, col1, ++, row1, col1, ++, row1, col2, ++
			//char vem primeiro que o do atributo, por isso
			*endereco = ch;
			endereco++;
			*endereco = attr;
			endereco++;
		}
	}
}

void vt_blank() {

	  //igual a vt_fill, mas o caracter é vazio
		char *endereco;		//apontador do endereço
		endereco = video_mem;

		int y;
		int x;

		for (y = 0; y < scr_lines; y++)
		{
			for (x = 0; x < scr_width; x++)
			{
				//row 1, col1, ++/ row1, col1, ++/ row1, col2, ++/ etc
				//char vem primeiro que o do atributo, por isso
				*endereco = 0x00;
				endereco++;
				*endereco = 0x00;
				endereco++;
			}
		}
}

int vt_print_char(char ch, char attr, int r, int c) {
  
	char *endereco;		//apontador do endereço
	endereco = (video_mem + r*2*scr_width) + 2*c;	//fica a apontar para o sitio

	*endereco = ch;
	endereco++;
	*endereco = attr;
	endereco++;

	return 0;
}

int vt_print_string(char *str, char attr, int r, int c) {

	char *endereco;		//apontador do endereço
	endereco = (video_mem + r*2*scr_width) + 2*c;	//fica a apontar para o sitio

	int x;
	for (x=0;x<strlen(str);x++)
	{
	*endereco = str[x];
	endereco++;
	*endereco = attr;
	endereco++;
	}

	return 0;
}

int vt_print_int(int num, char attr, int r, int c) {

	char *endereco;		//apontador do endereço
	endereco = (video_mem + r*2*scr_width) + 2*c;	//fica a apontar para o sitio

	if (num < 0)
	{*endereco = 0x2D;
	endereco++;
	*endereco = attr;
	endereco++;
	num=-num;}

	int x = num;
	int tam = 1;
	while(x>=10)
	{
		x= x/10;
		tam++;
	}
	endereco = endereco + 2*tam-2;
	int z, resto;
	endereco++;
	for (z=0;z<tam;z++)
	{
	resto = num%10;
	num = num/10;
	*endereco = attr;
		endereco--;
	*endereco = resto+ '0';
	endereco--;

	}
	return 0;
}


int vt_draw_frame(int width, int height, char attr, int r, int c) {

  char *endereco;		//apontador do endereço
	endereco = (video_mem + r*2*scr_width) + 2*c;	//fica a apontar para o inicio

  //topo

	*endereco = UL_CORNER;
	endereco++;
	*endereco = attr;
	endereco++;

	int a;
	for (a=0; a < width; a++)
	{
		*endereco = HOR_BAR;
		endereco++;
		*endereco = attr;
		endereco++;

	}

	*endereco = UR_CORNER;
	endereco++;
	*endereco = attr;
	endereco++;

	//lado esquerdo
	endereco = (video_mem + (r+1)*2*scr_width) + 2*c;

	int b;
	for (b=0; b < heigh; b++)
		{
			*endereco = VERT_BAR;
			endereco++;
			*endereco = attr;
			endereco= endereco + 2*scr_width;
		}

	//lado direito
	endereco = (video_mem + (r+1)*2*scr_width) + 2*c + 2*width;

	int c;
		for (c=0; c < heigh; c++)
			{
				*endereco = VERT_BAR;
				endereco++;
				*endereco = attr;
				endereco = endereco + 2*scr_width;
			}

	//baixo

	endereco = (video_mem + r*2*scr_width + heigh*scr_width) + 2*c;

	*endereco = LL_CORNER;
	endereco++;
	*endereco = attr;
	endereco++;

	int d;
	for (d=0; d < width; d++)
	{
		*endereco = HOR_BAR;
		endereco++;
		*endereco = attr;
		endereco++;
	}

	*endereco = LR_CORNER;
	endereco++;
	*endereco = attr;
	endereco++;

	return 0;
}

/*
 * THIS FUNCTION IS FINALIZED, do NOT touch it
 */

char *vt_init(vt_info_t *vi_p) {

  int r;
  struct mem_range mr;

  /* Allow memory mapping */

  mr.mr_base = (phys_bytes)(vi_p->vram_base);
  mr.mr_limit = mr.mr_base + vi_p->vram_size;

  if( OK != (r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &mr)))
	  panic("video_txt: sys_privctl (ADD_MEM) failed: %d\n", r);

  /* Map memory */

  video_mem = vm_map_phys(SELF, (void *)mr.mr_base, vi_p->vram_size);

  if(video_mem == MAP_FAILED)
	  panic("video_txt couldn't map video memory");

  /* Save text mode resolution */

  scr_lines = vi_p->scr_lines;
  scr_width = vi_p->scr_width;

  return video_mem;
}
