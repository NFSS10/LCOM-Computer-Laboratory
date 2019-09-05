#include "Utilidades.h"

int startGame()
{
	video_init(0x117);
	srand (time(NULL));
	if (kbd_subscribe_int()) { //Subescreve
		printf("kdb_subscribe_int falhou");
		return 1;
	}
	if (timer_subscribe_int()) { //Subescreve
		printf("timer_subscribe_int falhou");
		return 1;
	}
	if (mouse_subscribe_int()) { //Subescreve
		printf("mouse_subscribe_int falhou");
		return 1;
	}
	rtc_write_bcd_to_binary();
	inicializaimagens();

	return 0;
}

int endGame()
{
	if (kdb_unsubscribe_int()) // Unsubscribe Keyboard
	{
		printf("kbd_unsubscribe_int falhou");
		return 1;
	}

	if (timer_unsubscribe_int()) // Unsubscribe timer
	{
		printf("timer_unsubscribe_int falhou");
		return 1;
	}

	if (mouse_unsubscribe_int()) // Unsubscribe mouse
	{
		printf("mouse_unsubscribe_int falhou");
		return 1;
	}

	apagaImagens();
	video_exit();

	return 0;
}

int saveScore(unsigned int score)
{
	FILE *filescore;
	filescore = fopen("/home/lcom/lcom1516-t6g10/proj/StickHero/source/score", "r+");

	if (filescore == NULL) {
		printf("Erro na abertura do ficheiro!\n");
		return 1;
	}

	int i = 0;
	fscanf (filescore, "%d", &i);

	fseek(filescore, 0, SEEK_SET);

	if(score>i)
		fprintf(filescore, "%d", score);
	else
		fprintf(filescore, "%d", i);

	fclose(filescore);
	return 0;
}

int loadScore()
{
	FILE *filescore;
	filescore = fopen("/home/lcom/lcom1516-t6g10/proj/StickHero/source/score","r");

	if (filescore == NULL) {
		printf("Erro na abertura do ficheiro!\n");
		return 1;
	}

	int i;
	fscanf(filescore, "%d", &i);
	fseek(filescore, 0, SEEK_SET);
	fclose(filescore);

	return i;
}
