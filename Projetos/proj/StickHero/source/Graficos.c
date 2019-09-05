#include "Graficos.h"

// Variaveis Globais
Imagem* pa;	//0
Imagem* pb;	//1
Imagem* pc;	//2
Imagem* pd;	//3
Imagem* pe;	//4
Imagem* pf; //5
Imagem* pg; //6
Imagem* ph; //7
Imagem* pi; //8
Imagem* JogadorA;	//pos inicial
Imagem* JogadorB;
Imagem* JogadorC;
Imagem* Nuvens;
Imagem* Oceano;
Imagem* Ervas;
//Numeros jogo a,b,c,... porque com 0,1,2 da erro
Imagem* numerosJogoa;
Imagem* numerosJogob;
Imagem* numerosJogoc;
Imagem* numerosJogod;
Imagem* numerosJogoe;
Imagem* numerosJogof;
Imagem* numerosJogog;
Imagem* numerosJogoh;
Imagem* numerosJogoi;
Imagem* numerosJogoj;
Imagem* nFundo;
//Numeros Score
Imagem* numeroSa;
Imagem* numeroSb;
Imagem* numeroSc;
Imagem* numeroSd;
Imagem* numeroSe;
Imagem* numeroSf;
Imagem* numeroSg;
Imagem* numeroSh;
Imagem* numeroSi;
Imagem* numeroSj;



void inicializaimagens()
{
pa = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat0.bmp");
pb = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat1.bmp");
pc = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat2.bmp");
pd = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat3.bmp");
pe = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat4.bmp");
pf = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat5.bmp");
pg = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat6.bmp");
ph = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat7.bmp");
pi = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/plataformas/plat8.bmp");
JogadorA = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/jogador/jogador1.bmp");
JogadorB = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/jogador/jogador2.bmp");
JogadorC = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/jogador/jogador3.bmp");
Nuvens = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/fundo/nuvens.bmp");
Ervas = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/fundo/erva.bmp");
Oceano = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/fundo/oceanoo.bmp");
//Numeros Jogo
numerosJogoa = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/0.bmp");
numerosJogob = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/1.bmp");
numerosJogoc = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/2.bmp");
numerosJogod = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/3.bmp");
numerosJogoe = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/4.bmp");
numerosJogof = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/5.bmp");
numerosJogog = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/6.bmp");
numerosJogoh = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/7.bmp");
numerosJogoi = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/8.bmp");
numerosJogoj = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/9.bmp");
nFundo=LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosJogo/nFundo.bmp");
//Numeros score
numeroSa = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/0.bmp");
numeroSb = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/1.bmp");
numeroSc = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/2.bmp");
numeroSd = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/3.bmp");
numeroSe = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/4.bmp");
numeroSf = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/5.bmp");
numeroSg = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/6.bmp");
numeroSh = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/7.bmp");
numeroSi = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/8.bmp");
numeroSj = LoadBitmapFile("/home/lcom/lcom1516-t6g10/proj/StickHero/resources/numerosscore/9.bmp");

}

void apagaImagens()
{
	apagaImagem(pa);
	apagaImagem(pb);
	apagaImagem(pc);
	apagaImagem(pd);
	apagaImagem(pe);
	apagaImagem(pf);
	apagaImagem(pg);
	apagaImagem(ph);
	apagaImagem(pi);
	apagaImagem(JogadorA);
	apagaImagem(JogadorB);
	apagaImagem(JogadorC);
	apagaImagem(Nuvens);
	apagaImagem(Oceano);
	apagaImagem(Ervas);
	apagaImagem(numerosJogoa);
	apagaImagem(numerosJogob);
	apagaImagem(numerosJogoc);
	apagaImagem(numerosJogod);
	apagaImagem(numerosJogoe);
	apagaImagem(numerosJogof);
	apagaImagem(numerosJogog);
	apagaImagem(numerosJogoh);
	apagaImagem(numerosJogoi);
	apagaImagem(numerosJogoj);
	apagaImagem(nFundo);
	apagaImagem(numeroSa);
	apagaImagem(numeroSb);
	apagaImagem(numeroSc);
	apagaImagem(numeroSd);
	apagaImagem(numeroSe);
	apagaImagem(numeroSf);
	apagaImagem(numeroSg);
	apagaImagem(numeroSh);
	apagaImagem(numeroSi);
	apagaImagem(numeroSj);
}


//Sai do modo grafico
int video_exit(void)
{
  struct reg86u reg86;

  reg86.u.b.intno = 0x10; /* BIOS video services */

  reg86.u.b.ah = 0x00;    /* Set Video Mode function */
  reg86.u.b.al = 0x03;    /* 80x25 text mode*/

  if( sys_int86(&reg86) != OK )
  {
      printf("\tvg_exit(): sys_int86() failed \n");
      return 1;
  } else
      return 0;
}

//Inicia em modo grafico
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
	range.mr_limit = range.mr_base + h_res* v_res*bits_per_pixel/8;

	if((r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &range)) != OK)
		panic("video_txt: sys_privctl failed: %d\n", r);

	video_mem = vm_map_phys(SELF, (void *)range.mr_base, h_res* v_res*bits_per_pixel/8);
	if(video_mem == MAP_FAILED){
		panic("video_txt couldn't map video memory");
		return NULL;}

	return video_mem;
}

int drawnPixel(unsigned long x, unsigned long y, unsigned long color)
{

	if(x < 0 || x >= h_res || y < 0 || y >= v_res)
		return -1;

	else
	{
		*(video_mem + y*h_res*2 + x*2) = color;
		*(video_mem + y*h_res*2 + x*2+1) = color;

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
    	   drawnPixel(x, y, cor);
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
		drawnPixel(x, y1, cor);
		y1++;
	}
}

int drawLine(unsigned short xi, unsigned short yi, unsigned short xf, unsigned short yf, unsigned long color)
{
	if(xi < 0 || xi >= h_res || yi < 0 || yi >= v_res || xf < 0 || xf >= h_res || yf< 0 || yf >= v_res )
		return -1;

	if(xi==xf)//linha vertical
		drawnVerticalLine(xi, yi, yf, color);

	bresenham(xi, yi, xf, yf, color);
	return 0;
}



void drawn_Imagem_to_Buf(Imagem* img, int x, int y)
{
	unsigned int altura = img->BMP_info.altura;
	unsigned int largura = img->BMP_info.largura;


	int i;
	//Se a largura for par
	if (largura % 2 != 0)
	{
		for (i = 0; i < altura; i++)
		{
			int pos = y + altura - 1 - i;

			if (pos < 0 || pos >= H_RES)
				continue;

			unsigned char* bufferStartPos = next + x * BYTES_PER_PIXEL
												 + pos * H_RES * BYTES_PER_PIXEL;

			memcpy(bufferStartPos, img->Data + (i + i * largura) * BYTES_PER_PIXEL,	largura * BYTES_PER_PIXEL);
		}
	}
	//Se a largura for impar
	else
	{
		for (i = 0; i < altura; i++)
		{
			int pos = y + altura - 1 - i;

			if (pos < 0 || pos >= H_RES)
				continue;
			unsigned char* bufferStartPos = next + x * BYTES_PER_PIXEL
												 + pos * H_RES * BYTES_PER_PIXEL;

			memcpy(bufferStartPos, img->Data + i * largura * BYTES_PER_PIXEL, largura * BYTES_PER_PIXEL);
		}
	}

}

void drawn_aumenta_barra(unsigned int tamanho)
{
	drawLine(BARRA_X_I, BARRA_Y_I-tamanho, BARRA_X_I, BARRA_Y_I, 0);
	drawLine(BARRA_X_I+1, BARRA_Y_I-tamanho, BARRA_X_I+1, BARRA_Y_I, 0);
	drawLine(BARRA_X_I+2, BARRA_Y_I-tamanho, BARRA_X_I+2, BARRA_Y_I, 0);
	drawLine(BARRA_X_I+3, BARRA_Y_I-tamanho, BARRA_X_I+3, BARRA_Y_I, 0);
}

void drawn_barra_horizontal(unsigned int tamanho)
{
	//do inico ate a plataforma
	drawLine(0, BARRA_Y_I, 80, BARRA_Y_I, 0);
	drawLine(0, BARRA_Y_I+1, 80, BARRA_Y_I+1, 0);
	drawLine(0, BARRA_Y_I+2, 80, BARRA_Y_I+2, 0);
	drawLine(0, BARRA_Y_I+3, 80, BARRA_Y_I+3, 0);

	//original, da plataforma ate o tamanho que obteve
	drawLine(BARRA_X_I, BARRA_Y_I, BARRA_X_I+tamanho, BARRA_Y_I, 0);
	drawLine(BARRA_X_I, BARRA_Y_I+1, BARRA_X_I+tamanho, BARRA_Y_I+1, 0);
	drawLine(BARRA_X_I, BARRA_Y_I+2, BARRA_X_I+tamanho, BARRA_Y_I+2, 0);
	drawLine(BARRA_X_I, BARRA_Y_I+3, BARRA_X_I+tamanho, BARRA_Y_I+3, 0);
}


void drawn_jogo_i(unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos)
{

	Imagem* plataforma_Antiga;
	Imagem* plataforma_Nova;

	plataforma_Antiga = escolhePlataforma(n_plat_antiga);
	plataforma_Nova = escolhePlataforma(plat_ale);

	unsigned int posPlat;
	if (larg(n_plat_antiga) > 100) //se for uma plataforma grande
		{
		plataforma_Antiga = pg;	//a plataforma = plataforma com o tamanho exato 100 pixeis
		posPlat = 0;
		}
	else
		//SE NAO, ou seja, tudo o resto <= 100
		posPlat = 100 - larg(n_plat_antiga);

	drawn_fundo_buf(Pontos);
	drawn_Imagem_to_Buf(JogadorA, J_X, J_Y);
	drawn_Imagem_to_Buf(plataforma_Antiga, posPlat, P_Y);
	drawn_Imagem_to_Buf(plataforma_Nova, x_ale, P_Y);
	memcpy(video_mem, next, sizeof(next));	//mete no ecra o que tinha desenhado
	//Desenha a linha de acordo com o estado anterior 80, porque e o maximo que precisa para a plataforma mais pequena
	drawLine(0, BARRA_Y_I, 80, BARRA_Y_I, 0);
	drawLine(0, BARRA_Y_I +1, 80, BARRA_Y_I + 1, 0);
	drawLine(0, BARRA_Y_I + 2, 80, BARRA_Y_I + 2, 0);
	drawLine(0, BARRA_Y_I + 3, 80, BARRA_Y_I + 3, 0);
}

void drawn_jogo_estado(unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos)
{

	Imagem* plataforma_Antiga;
	Imagem* plataforma_Nova;

	plataforma_Antiga = escolhePlataforma(n_plat_antiga);
	plataforma_Nova = escolhePlataforma(plat_ale);


	unsigned int posPlat;
	if (larg(n_plat_antiga) > 100) //se for uma plataforma grande
		{
		plataforma_Antiga = pg;	//a plataforma = plataforma com o tamanho exato 100pixeis
		posPlat = 0;
		}
	else//SE NAO, ou seja, tudo o resto <= 100
		posPlat = 100 - larg(n_plat_antiga);



	drawn_fundo_buf(Pontos);
	drawn_Imagem_to_Buf(plataforma_Antiga, posPlat, P_Y);
	drawn_Imagem_to_Buf(plataforma_Nova, x_ale, P_Y);
	memcpy(video_mem, next, sizeof(next));	//mete no ecra o que tinha desenhado
	//Desenha a linha de acordo com o estado anterior 80, porque e o maximo que precisa para a plataforma mais pequena
	drawLine(0, BARRA_Y_I, 80, BARRA_Y_I, 0);
	drawLine(0, BARRA_Y_I +1, 80, BARRA_Y_I + 1, 0);
	drawLine(0, BARRA_Y_I + 2, 80, BARRA_Y_I + 2, 0);
	drawLine(0, BARRA_Y_I + 3, 80, BARRA_Y_I + 3, 0);
}

void drawn_Fundo_to_Buf(Imagem* img, int x, int y, unsigned int coordx, unsigned int tamImg)
{

	unsigned int altura = img->BMP_info.altura;
	unsigned int largura = 1024;


int j;
	for (j = 0; j < altura; j++)
	{
		int pos = y + altura - 1 - j;

		if (pos < 0 || pos >= H_RES)
			continue;

		unsigned char* bufferStartPos = next + x * BYTES_PER_PIXEL
				+ pos * H_RES * BYTES_PER_PIXEL;

		memcpy(
				bufferStartPos, //Inicio onde vai escrever a imagem
				img->Data + (coordx*BYTES_PER_PIXEL+ (-j-j)*2)+(j + j * tamImg) * BYTES_PER_PIXEL, //linha da imagem de fundo ser copiada
				largura * BYTES_PER_PIXEL);//num de bytes a ser copiados
		coordx++;
	}
	return;


}

void atualiza_fundo_ervas()
{
	coordErvas = coordErvas + ERVA_VEL;
}

void atualiza_fundo()
{
	if ((contador % 2) == 0)
	{
		coordNuvens = coordNuvens + NUVENS_VEL;
	}

	if (coordNuvens >= NUVENS_R)
		coordNuvens = 1024;
	if (coordErvas >= ERVA_R)
		coordErvas = 0;

}

void drawn_fundo_buf(int Pontos)
{
	drawn_Imagem_to_Buf(Oceano, 0, 454);
	drawn_Fundo_to_Buf(Nuvens, 0, 0, coordNuvens, 4096);
	drawn_Fundo_to_Buf(Ervas, 0, 698, coordErvas, 2048);

	printScore(Pontos);
}

void quedaJogador(unsigned int posicao, unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos)
{
	int y = J_Y;
	while (y < (698 - 63))
	{
		atualiza_fundo();
		y=y+VEL_QUEDA;
		drawn_jogo_estado(x_ale, plat_ale, n_plat_antiga, Pontos);
		drawn_Imagem_to_Buf(JogadorA, posicao, y);
		memcpy(video_mem, next, sizeof(next));
		usleep(17);
	}
}

unsigned int percorrer_barra(unsigned int posicao, unsigned int estado, unsigned int cont, unsigned int x_ale, unsigned int plat_ale, unsigned int n_plat_antiga, int Pontos)
{
	if ((cont % MOV_V) == 0)
	{
		switch (estado)
		{
		case 0:
			drawn_jogo_estado(x_ale, plat_ale, n_plat_antiga, Pontos);
			drawn_Imagem_to_Buf(JogadorA, posicao, J_Y);
			break;
		case 1:
			drawn_jogo_estado(x_ale, plat_ale, n_plat_antiga, Pontos);
			drawn_Imagem_to_Buf(JogadorB, posicao, J_Y);
			break;
		case 2:
			drawn_jogo_estado(x_ale, plat_ale, n_plat_antiga, Pontos);
			drawn_Imagem_to_Buf(JogadorC, posicao, J_Y);
			break;
		case 3:
			drawn_jogo_estado(x_ale, plat_ale, n_plat_antiga, Pontos);
			drawn_Imagem_to_Buf(JogadorB, posicao, J_Y);
			break;
		default:
			break;
		}
		memcpy(video_mem, next, sizeof(next));

		estado++;
		if(estado > 3)
			estado=0;
		return estado;
	}
	return estado;
}

Imagem *escolhePlataforma(unsigned int n)
{
	switch (n) {
	case 0:
		return pa;
		break;
	case 1:
		return pb;
		break;
	case 2:
		return pc;
		break;
	case 3:
		return pd;
		break;
	case 4:
		return pe;
		break;
	case 5:
		return pf;
		break;
	case 6:
		return pg;
		break;
	case 7:
		return ph;
		break;
	case 8:
		return pi;
		break;
	}
}

void move_plataforma_antiga(unsigned int posI_plat_antiga, unsigned int n_plat_antiga, int Pontos)
{
	Imagem *plataforma_Antiga;
	unsigned int posJogador;
	posJogador=posI_plat_antiga + larg(n_plat_antiga) - JOG_L;

	plataforma_Antiga=escolhePlataforma(n_plat_antiga);


	//movimento
	while(posI_plat_antiga>150)
	{
		//Fundo
		atualiza_fundo_ervas();
		atualiza_fundo();
		drawn_fundo_buf(Pontos);
		//Plataforma e jogador
		drawn_Imagem_to_Buf(plataforma_Antiga, posI_plat_antiga, P_Y);
		drawn_Imagem_to_Buf(JogadorA, posJogador, J_Y);

		memcpy(video_mem, next, sizeof(next));//Mosta no ecra

		//barra antes da plataforma
		drawLine(0, BARRA_Y_I,   posI_plat_antiga, BARRA_Y_I,   0);
		drawLine(0, BARRA_Y_I+1, posI_plat_antiga, BARRA_Y_I+1, 0);
		drawLine(0, BARRA_Y_I+2, posI_plat_antiga, BARRA_Y_I+2, 0);
		drawLine(0, BARRA_Y_I+3, posI_plat_antiga, BARRA_Y_I+3, 0);



		posI_plat_antiga = posI_plat_antiga - P_MOV_ANTIGA;
		posJogador = posI_plat_antiga + larg(n_plat_antiga) - JOG_L;
		usleep(17);
	}
	//alinha

	if (larg(n_plat_antiga) > 100) //se for uma plataforma grande
		{
		plataforma_Antiga = pg;	//a plataforma = plataforma com o tamanho exato 100pixeis
		posI_plat_antiga=0;
		}
		else							//SE NAO, ou seja, tudo o resto <= 100
		posI_plat_antiga = 100 - larg(n_plat_antiga);


	atualiza_fundo_ervas();
	atualiza_fundo();
	drawn_fundo_buf(Pontos);
	drawn_Imagem_to_Buf(plataforma_Antiga, posI_plat_antiga, P_Y);
	drawn_Imagem_to_Buf(JogadorA, J_X, J_Y);

	memcpy(video_mem, next, sizeof(next));//Mostra no ecra

	//barra antes da plataforma
	if(larg(n_plat_antiga) < 100)
	{
	drawLine(0, BARRA_Y_I, posI_plat_antiga, BARRA_Y_I, 0);
	drawLine(0, BARRA_Y_I + 1, posI_plat_antiga, BARRA_Y_I + 1, 0);
	drawLine(0, BARRA_Y_I + 2, posI_plat_antiga, BARRA_Y_I + 2, 0);
	drawLine(0, BARRA_Y_I + 3, posI_plat_antiga, BARRA_Y_I + 3, 0);
	}
}

void move_plataforma_nova(unsigned int posFinal, unsigned int n_Plat_Nova, unsigned int n_Plat_Antiga, int Pontos)
{
	unsigned int posInicial;
	posInicial = H_RES - larg(n_Plat_Nova);

	Imagem* plataforma_Nova;
	Imagem* plataforma_Antiga;

	plataforma_Antiga = escolhePlataforma(n_Plat_Antiga);
	plataforma_Nova = escolhePlataforma(n_Plat_Nova);


	unsigned int posPlat_antiga;
	if (larg(n_Plat_Antiga) > 100) //se for uma plataforma grande
		{
		plataforma_Antiga = pg;	//a plataforma = plataforma com o tamanho exato 100pixeis
		posPlat_antiga = 0;
	}
	else	//SE NAO, ou seja, tudo o resto <= 100
	{
		posPlat_antiga = 100 - larg(n_Plat_Antiga);
	}

	while(posInicial > posFinal)
	{
		//Fundo
		atualiza_fundo_ervas();
		atualiza_fundo();
		drawn_fundo_buf(Pontos);

		drawn_Imagem_to_Buf(plataforma_Antiga, posPlat_antiga, P_Y);	//Plataforma antiga
		drawn_Imagem_to_Buf(plataforma_Nova, posInicial, P_Y);	 //Plataforma Nova com posicao atualizada
		drawn_Imagem_to_Buf(JogadorA, J_X, J_Y);		//Jogador

		memcpy(video_mem, next, sizeof(next)); //mostra no ecra

		if(larg(n_Plat_Antiga) < 100)
		{
			drawLine(0, BARRA_Y_I, 80, BARRA_Y_I, 0);
			drawLine(0, BARRA_Y_I + 1, 80, BARRA_Y_I + 1, 0);
			drawLine(0, BARRA_Y_I + 2, 80, BARRA_Y_I + 2, 0);
			drawLine(0, BARRA_Y_I + 3, 80, BARRA_Y_I + 3, 0);
		}

		posInicial = posInicial - P_MOV_NOVA;
		usleep(17);
	}


}


Imagem* chooseNumberGame(int number)
{
	switch(number)
	{
	case 0:
		return numerosJogoa;
		break;
	case 1:
		return numerosJogob;
		break;
	case 2:
		return numerosJogoc;
		break;
	case 3:
		return numerosJogod;
		break;
	case 4:
		return numerosJogoe;
		break;
	case 5:
		return numerosJogof;
		break;
	case 6:
		return numerosJogog;
		break;
	case 7:
		return numerosJogoh;
		break;
	case 8:
		return numerosJogoi;
		break;
	case 9:
		return numerosJogoj;
		break;
	}
}

void printScore(int score)
{
	Imagem* img = nFundo;
	drawn_Imagem_to_Buf(img, 457, 100);

	int size = floor(log10(abs(score))) + 1;
	int x = 500 + 18 * (size - 1);

	if (score == 0) {
		Imagem* number = chooseNumberGame(0);
		drawn_Imagem_to_Buf(number, 500, 110);

		return;
	}

	while (size != 0) {
		int aux = score % 10;
		score = score / 10;
		Imagem* number = chooseNumberGame(aux);

		drawn_Imagem_to_Buf(number, x, 110);

		x -= 34;
		size--;
	}
}


 void drawMenu(Imagem* img, Mouse* m)
{
	drawn_Imagem_to_Buf(img, 0, 0);
	drawn_Imagem_to_Buf(m->sprite, m->x, m->y);

	memcpy(video_mem, next, sizeof(next));
}

 void drawHours(unsigned long* data, Imagem* img) {

	long hor = data[4];
	long min = data[2];
	long seg = data[0];

	drawn_Imagem_to_Buf(img, 0, 0);

	int n = 0;
	int x = 605;
	// Mostra os segundos
	Imagem * temp;
	while (n != 2) {
		int numero = seg % 10;
		seg = seg / 10;
		temp = chooseNumber(numero);
		drawn_Imagem_to_Buf(temp, x, 250);
		n++;
		x -= 38;
	}
	// Mostra os minutos
	n = 0;
	x = 517;
	while (n != 2) {
		int numero = min % 10;
		min = min / 10;
		temp = chooseNumber(numero);
		drawn_Imagem_to_Buf(temp, x, 250);
		n++;
		x -= 38;
	}
	// Mostra as horas
	n = 0;
	x = 433;
	while (n != 2) {
		int numero = hor % 10;
		hor = hor / 10;
		temp = chooseNumber(numero);
		drawn_Imagem_to_Buf(temp, x, 250);
		n++;
		x -= 38;
	}
	memcpy(video_mem, next, sizeof(next));
}

void drawOption(unsigned int option)
{
	switch (option)
	{
	case 1:
		drawLine(320, 215, 700, 215, 255);
		drawLine(700, 215, 700, 285, 255);
		drawLine(320, 285, 700, 285, 255);
		drawLine(320, 215, 320, 285, 255);
		break;
	case 2:
		drawLine(300, 300, 725, 300, 255);
		drawLine(725, 300, 725, 365, 255);
		drawLine(300, 365, 725, 365, 255);
		drawLine(300, 300, 300, 365, 255);
		break;
	case 3:
		drawLine(385, 380, 640, 380, 255);
		drawLine(640, 380, 640, 445, 255);
		drawLine(385, 445, 640, 445, 255);
		drawLine(385, 380, 385, 445, 255);
		break;
	case 4:
		drawLine(420, 460, 600, 460, 255);
		drawLine(600, 460, 600, 525, 255);
		drawLine(420, 525, 600, 525, 255);
		drawLine(420, 460, 420, 525, 255);
		break;
	default:
		break;
	}
}

void drawOptionScore(int opcao)
{
	if (opcao == 1) {
		drawLine(350, 465, 670, 465, 255);
		drawLine(670, 465, 670, 540, 255);
		drawLine(350, 540, 670, 540, 255);
		drawLine(350, 465, 350, 540, 255);
	}
}

Imagem* chooseNumber(int number)
{
	switch(number)
	{
	case 0:
		return numeroSa;
		break;
	case 1:
		return numeroSb;
		break;
	case 2:
		return numeroSc;
		break;
	case 3:
		return numeroSd;
		break;
	case 4:
		return numeroSe;
		break;
	case 5:
		return numeroSf;
		break;
	case 6:
		return numeroSg;
		break;
	case 7:
		return numeroSh;
		break;
	case 8:
		return numeroSi;
		break;
	case 9:
		return numeroSj;
		break;
	}
}

void drawScoreMenu(Mouse* m, Imagem* menu2)
{
	drawn_Imagem_to_Buf(menu2, 0, 0);

	int score = loadScore();
	int size = floor(log10(abs(score))) + 1;
	int x = 500 + 19 * (size - 1);

	if (score == 0)
	{
		Imagem* number = chooseNumber(0);
		drawn_Imagem_to_Buf(number, 500, 250);
		drawn_Imagem_to_Buf(m->sprite, m->x, m->y);
		memcpy(video_mem, next, sizeof(next));

		return;
	}

	while (size != 0) {
		int aux = score % 10;
		score = score / 10;
		Imagem* number = chooseNumber(aux);

		drawn_Imagem_to_Buf(number, x, 250);

		x -= 40;
		size--;
	}

	drawn_Imagem_to_Buf(m->sprite, m->x, m->y);

	memcpy(video_mem, next, sizeof(next));

}

void drawOptionEnd(int opcao)
{
	if (opcao == 1) {
		drawLine(300, 425, 720, 425, 255);
		drawLine(720, 425, 720, 560, 255);
		drawLine(300, 560, 720, 560, 255);
		drawLine(300, 425, 300, 560, 255);
	}
}

void drawEndMenu(Mouse* m, MenuFinal* menu)
{
	int score = menu->score;
	drawn_Imagem_to_Buf(menu->sprite, 0, 0);

	int size = floor(log10(abs(score))) + 1;
	int x = 500 + 19 * (size - 1);

	if (score == 0) {
		Imagem* number = chooseNumber(0);
		drawn_Imagem_to_Buf(number, 500, 250);
		drawn_Imagem_to_Buf(m->sprite, m->x, m->y);
		memcpy(video_mem, next, sizeof(next));

		return;
	}

	while (size != 0) {
		int aux = score % 10;
		score = score / 10;
		Imagem* number = chooseNumber(aux);

		drawn_Imagem_to_Buf(number, x, 250);

		x -= 40;
		size--;
	}

	drawn_Imagem_to_Buf(m->sprite, m->x, m->y);

	memcpy(video_mem, next, sizeof(next));

}
