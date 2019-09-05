#include <minix/drivers.h>

#include "test3.h"

static int proc_args(int argc, char *argv[]);
static unsigned long parse_ulong(char *str, int base);
static long parse_long(char *str, int base);
static void print_usage(char *argv[]);

int main(int argc, char **argv) {

  /* Initialize service */
  sef_startup();

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
	 "\t service run %s -args \"test_scan <ass>\" \n"
	 "\t service run %s -args \"test_leds <size> <array>\" \n"
	 "\t service run %s -args \"test_timed_scan <time>\" \n"
	 "\t TODOS OS ARGUMENTOS SAO EM DECIMAL\n",
	 argv[0], argv[0], argv[0]);
}

static int proc_args(int argc, char *argv[]) {

  unsigned long num, element, time, sizeOfArray;

  /* check the function to test: if the first characters match, accept it */
  if (strncmp(argv[1], "test_scan", strlen("test_scan")) == 0) {
	  if( argc != 3 ) {
		  printf("keyboard: wrong no of arguments for test of test_scan() \n");
		  return 1;
	  }
	  if( (num = parse_ulong(argv[2], 10)) == ULONG_MAX )
		  return 1;
	  printf("keyboard:: test_scan(%lu)\n", num);
	  kbd_test_scan(num);
	  return 0;
  } else if (strncmp(argv[1], "test_timed_scan", strlen("test_timed_scan")) == 0) {
	  if( argc != 3 ) {
		  printf("keyboard: wrong no of arguments for test of kbd_test_timed_scan() \n");
		  return 1;
	  }
	  if( (time = parse_ulong(argv[2], 10)) == ULONG_MAX )
		  return 1;
	  printf("keyboard:: kbd_test_timed_scan(%lu)\n",
			  time);
	  kbd_test_timed_scan(time);
	  return 0;
  } else if (strncmp(argv[1], "test_leds", strlen("test_leds")) == 0) {
	  if( argc < 4 ) {
		  printf("keyboard: wrong no of arguments for test of kbd_test_leds() \n");
		  return 1;
	  }
	  if( (sizeOfArray = parse_ulong(argv[2], 10)) == ULONG_MAX )
		  return 1;

	  unsigned short array[sizeOfArray];

	  unsigned int i;
	  for(i=0;i < sizeOfArray;i++){
	  	if( (element = parse_ulong(argv[3+i], 10)) == ULONG_MAX )
	  		return 1;
	  	array[i] = element;}

	  printf("keyboard:: kbd_test_leds(%lu,[",
			  sizeOfArray);
	  for (i = 0; i<sizeOfArray;i++)
		  printf("%d ", array[i]);
	  printf ("])\n");
	  kbd_test_leds(sizeOfArray, array);
	  return 0;
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
	  printf("timer: parse_ulong: no digits were found in %s \n", str);
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
	  printf("timer: parse_long: no digits were found in %s \n", str);
	  return LONG_MAX;
  }

  /* Successful conversion */
  return val;
}
