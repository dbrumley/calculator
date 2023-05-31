#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "calculator.h"

// An example of a typical unit test. 
// Unit tests try only a single case at a time.
int unit_tests() {
  assert(add(1, 2) == 3);
  return 0;
}

// Mayhem allows you to test properties over all inputs
// This example, the basic math cancellation property
// (a * b) / a = b 
int property_tests() {
  int a, b;
  if(scanf("%d %d", &a, &b) != 2) return 0;

  if(a == 0) return 0; // division is undefined on 0

  int result = divide(multiply(a, b), a);
  assert(result == b);
  return result;
}

// Mayhem checks multiple inputs, which means you have 
// improved confidence over limited hard-coded unit tests.
int mayhem_tests(int verbose) {
  int left, right, result;
  char op;

  if(scanf("%d %d %c", &left, &right, &op) != 3) {
    printf("Not enough inputs given\n");
    return -1;   
  }
  result = eval(left, right, op);
  if(verbose) {
    printf("%d %c %d = %d\n", left, op, right, result);
  }
  return result;
}


// DEMO PURPOSES: a small driver to switch
// on and off different types of testing
int main(int argc, char *argv[]) {
  int mflag = 0;
  int uflag = 0;
  int pflag = 0;
  int verbose = 0;
  char c;
  
  opterr = 0;

  while ((c = getopt (argc, argv, "upmv")) != -1) {
    switch(c) {
      case 'u': uflag = 1; break; // unit tests
      case 'p': pflag = 1; break; // property tests
      case 'm': mflag = 1; break; // mayhem tests
      case 'v': verbose = 1; break; // verbose
    }
  }

  if(uflag) { unit_tests(); } // do unit test
  if(pflag) { property_tests(); }  // do property test
  if(mflag) { mayhem_tests(verbose); } // do mayhem tests

  return 0;
}
