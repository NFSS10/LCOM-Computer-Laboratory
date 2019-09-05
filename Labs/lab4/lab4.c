#include <minix/syslib.h>
#include <minix/drivers.h>
#include <stdio.h>

#include "test4.h"
#include "mouse.h"
#include "i8042.h"

static int proc_args(int argc, char *argv[]);
static unsigned long parse_ulong(char *str, int base);
static long parse_long(char *str, int base);
static void print_usage(char *argv[]);

int main(int argc, char **argv) {

	/* Initialize service */

	sef_startup();

	printf("LAB4-MOUSE\n");

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
	 "\t service run %s -args \"packet <numberOfPackets>\" \n"
	 "\t service run %s -args \"async <time>\" \n"
	 "\t service run %s -args \"config\" \n"
	 "\t service run %s -args \"gesture <lenght> <tol>\" \n",
	 argv[0], argv[0], argv[0], argv[0]);
}

static int proc_args(int argc, char *argv[]) {

  unsigned long numberOfPackets, time, length, tol;

  /* check the function to test: if the first characters match, accept it */
  if (strncmp(argv[1], "packet", strlen("packet")) == 0)
  {
	  if( argc != 3 )
	  {
		  printf("mouse: wrong no of arguments for test of test_packet() \n");
		  return 1;
	  }
	  if((numberOfPackets = parse_ulong(argv[2], 10)) == ULONG_MAX)
		return 1;

	  printf("mouse:: test_packet(%d)\n", numberOfPackets); /* Actually, it was already invoked */
	  test_packet(numberOfPackets);
	  return 0;

  }
  else if (strncmp(argv[1], "async", strlen("async")) == 0)
  {
	  if( argc != 3 )
	  {
		  printf("mouse: wrong no of arguments for test of test_async() \n");
		  return 1;
	  }
	  if( (time = parse_ulong(argv[2], 10)) == ULONG_MAX )
		  return 1;
	
	  printf("mouse:: test_async(%d)\n", time);
	  test_async(time);
	  return 0;

  }
  else if (strncmp(argv[1], "conf", strlen("conf")) == 0) {
	  if( argc != 2 ) {
		  printf("mouse: wrong no of arguments for test of test_config() \n");
		  return 1;
	  }
	  printf("mouse:: test_config()\n");
	  test_config();
	  return 0;

  } else if (strncmp(argv[1], "gesture", strlen("gesture")) == 0) {
	  if( argc != 4 ) {
		  printf("mouse: wrong no of arguments for test of test_gesture() \n");
		  return 1;
	  }
	  if( (length = parse_ulong(argv[2], 10)) == ULONG_MAX)
		return 1;
	if( (tol = parse_ulong(argv[3], 10)) == ULONG_MAX)
		return 1;

	  printf("mouse:: test_gesture(%d", length);
	  printf(", %d)", tol); 
	  test_gesture(length, tol);
	return 0;
  } else {
	  printf("mouse:: non valid function \"%s\" to test\n", argv[1]);
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
	  printf("mouse: parse_ulong: no digits were found in %s \n", str);
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
	  printf("mouse: parse_long: no digits were found in %s \n", str);
	  return LONG_MAX;
  }

  /* Successful conversion */
  return val;
}
