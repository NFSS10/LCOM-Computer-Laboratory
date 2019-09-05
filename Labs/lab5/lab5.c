#include <minix/syslib.h>
#include <minix/drivers.h>
#include <stdio.h>
#include <machine/int86.h>

#include "test5.h"
#include "video_gr.h"
#include "i8042.h"
#include "pixmap.h"

static int proc_args(int argc, char *argv[]);
static unsigned long parse_ulong(char *str, int base);
static long parse_long(char *str, int base);
static void print_usage(char *argv[]);

int main(int argc, char **argv) {

	/* Initialize service */

	sef_startup();

	/////////////////////////////////////
	//Teste XPM
	////////////////////////////////////

	//test_xpm(5, 5, cross);
	//test_xpm(0, 0, penguin);
	//test_xpm(50,50, penguin);
	//////////////////////////////////
	//////////////////////////////////



	printf("LAB5-VIDEO CARD\n");
	// sys_enable_iop(SELF);
	if ( argc == 1 ) {
		print_usage(argv);
		return 0;
	} else {
		proc_args(argc, argv);
	}
	return 0;

}

static void print_usage(char *argv[]) {
  printf("Usage: one of the following:\n"
	 "\t service run %s -args \"init  <mode> <delay>\" \n"
	 "\t service run %s -args \"square <x> <y> <size> <color>\" \n"
	 "\t service run %s -args \"line <xi> <yi> <xf> <yf> <color>\" \n"
	 "\t service run %s -args \"xpm <xi> <yi> <image index>\" \n"
	 "\t service run %s -args \"move <xi> <yi> <indice> <hor> <delta> <time>\" \n"
	 "\t service run %s -args \"controller \" \n",
	 argv[0], argv[0], argv[0], argv[0], argv[0], argv[0]);
}

static int proc_args(int argc, char *argv[]) {

  unsigned long color;
  short delta;
  unsigned short mode, delay, x, y, xi, xf, yi, yf, time, hor, size, index;
  char **xpm;

  /* check the function to test: if the first characters match, accept it */
  if (strncmp(argv[1], "init", strlen("init")) == 0)
  {
	  if( argc != 4 )
	  {
		  printf("video: wrong no of arguments for test of test_init) \n");
		  return 1;
	  }
	  if((mode = parse_ulong(argv[2], 16)) == ULONG_MAX)
		return 1;
	  if((delay = parse_ulong(argv[3], 10)) == ULONG_MAX)
	  	return 1;

	  printf("video:: test_init(%d, ", mode);
	  printf("%d) \n" , delay);
	  test_init(mode, delay);
	  return 0;

  }
  else if (strncmp(argv[1], "square", strlen("square")) == 0)
  {
	  if( argc != 6 )
	  {
		  printf("video: wrong no of arguments for test of test_square() \n");
		  return 1;
	  }
	  if ((x = parse_ulong(argv[2], 10)) == ULONG_MAX)
	 	  	return 1;
	  if ((y = parse_ulong(argv[3], 10)) == ULONG_MAX)
	  		return 1;
	  if ((size = parse_ulong(argv[4], 10)) == ULONG_MAX)
	 		return 1;
	  if ((color = parse_ulong(argv[5], 16)) == ULONG_MAX)
	 	  	return 1;
	
	  printf("video:: test_square(%d, ", x);
	  printf ("%d, ", y);
	  printf ("%d, ", size);
	  printf ("%d)\n", color);
	  test_square(x,y, size, color);
	  return 0;

  }
  else if (strncmp(argv[1], "line", strlen("line")) == 0) {
	  if( argc != 7 ) {
		  printf("video: wrong no of arguments for test of test_line() \n");
		  return 1;
	  }
	  if ((xi = parse_ulong(argv[2], 16)) == ULONG_MAX)
	  		return 1;
	  if ((yi = parse_ulong(argv[3], 16)) == ULONG_MAX)
	  		return 1;
	  if ((xf = parse_ulong(argv[4], 16)) == ULONG_MAX)
	  		return 1;
	  if ((yf = parse_ulong(argv[5], 16)) == ULONG_MAX)
	  		return 1;
	  if ((color = parse_ulong(argv[6], 16)) == ULONG_MAX)
	  		return 1;
	  printf("video:: test_line(%d, ", xi);
	  printf("%d, ",yi);
	  printf("%d, ",xf);
	  printf("%d, ",yf);
	  printf("%d)\n",color);
	  test_line(xi,yi,xf,yf,color);
	  return 0;

  } else if (strncmp(argv[1], "xpm", strlen("xpm")) == 0) {
	  if( argc != 5 ) {
		  printf("video: wrong no of arguments for test of test_xpm() \n");
		  return 1;
	  }
	  if( (xi = parse_ulong(argv[2], 10)) == ULONG_MAX)
		return 1;
	  if( (yi = parse_ulong(argv[3], 10)) == ULONG_MAX)
		return 1;
	  if( (index = parse_ulong(argv[4], 10)) == ULONG_MAX)
		return 1;
	  switch (index)
	  {
	  case 0:
		  xpm = pic1;
		  break;
	  case 1:
		  xpm = pic2;
		  break;
	  case 2:
		  xpm = cross;
		  break;
	  case 3:
		  xpm = pic3;
		  break;
	  case 4:
		  xpm = penguin;
		  break;
	  default:
		  break;
	  }

	  printf("video:: test_xpm(%d, ", xi);
	  printf("%d, ", yi);
	  printf("%X)\n", xpm);
	  test_xpm(xi, yi, xpm);
	return 0;
  }
  else if (strncmp(argv[1], "move", strlen("move")) == 0) {

  		if (argc != 8) {
  			printf("video: wrong no of arguments for test of test_move() \n");
  			return 1;
  		}

  		if ((xi = parse_ulong(argv[2], 10)) == ULONG_MAX)
  			return 1;
  		if ((yi = parse_ulong(argv[3], 10)) == ULONG_MAX)
  			return 1;
  		if ((hor = parse_ulong(argv[5], 10)) == ULONG_MAX)
  			return 1;
  		if ((delta = parse_ulong(argv[6], 10)) == ULONG_MAX)
  			return 1;
  		if ((time = parse_ulong(argv[7], 10)) == ULONG_MAX)
  			return 1;
  		if( (index = parse_ulong(argv[4], 10)) == ULONG_MAX)
  			return 1;
  		switch (index)
  		  {
  		 case 0:
  			  xpm = pic1;
  			  break;
  		  case 1:
  			  xpm = pic2;
  			  break;
  		  case 2:
  			  xpm = pic3;
  			  break;
  		  case 3:
  			  xpm = cross;
  			  break;
  		  case 4:
  			  xpm = penguin;
  			  break;
  		  default:
  			  break;
  			 }

  		printf("video:: test_move(%d, ", xi);
  		printf ("%d, ", yi);
  		printf ("%d, ", xpm);
  		printf ("%d, ", hor);
  		printf ("%d, ", delta);
  		printf ("%d)", time);
  		test_move(xi,yi,xpm,hor,delta,time);

  		return 0;
  	}
  else
	  if (strncmp(argv[1], "controller", strlen("controller")) == 0) {

 		if (argc != 2) {
 			printf("video: wrong no of arguments for test of test_controller() \n");
 			return 1;
 		}

 		printf("video:: test_controller()\n");
 		test_controller();
 		return 0;
 	}
  else {
	  printf("video:: non valid function \"%s\" to test\n", argv[1]);
	  return 1;
  }
}

static unsigned long parse_ulong(char *str, int base) {
  char *endptr;
  unsigned long val;

  val = strtoul(str, &endptr, base);

  if ((errno == ERANGE && val == ULONG_MAX )
	  || (errno != 0 && val == 0)) {
	  perror("strtol");
	  return ULONG_MAX;
  }

  if (endptr == str) {
	  printf("video: parse_ulong: no digits were found in %s \n", str);
	  return ULONG_MAX;
  }

  /* Successful conversion */
  return val;
}

static long parse_long(char *str, int base) {
  char *endptr;
  unsigned long val;

  val = strtol(str, &endptr, base);

  if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
	  || (errno != 0 && val == 0)) {
	  perror("strtol");
	  return LONG_MAX;
  }

  if (endptr == str) {
	  printf("video: parse_long: no digits were found in %s \n", str);
	  return LONG_MAX;
  }

  /* Successful conversion */
  return val;
}
