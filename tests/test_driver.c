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
void property_tests(int a, int b) {
  if(a == 0) return; // division is undefined on 0

  int result = divide(multiply(a, b), a);
  assert(result == b);
  return;
}

// Mayhem checks multiple inputs, which means you have 
// improved confidence over limited hard-coded unit tests.
int mayhem_tests(int verbose) {
  int left, right, result;
  char op;

  if(scanf("%c %d %d", &op, &left, &right) != 3) {
    printf("Not enough inputs given\n");
    return -1;   
  }

  switch(op) {
    case '+': result = add(left, right); break;
    case '-': result = subtract(left, right); break;
    case '*': result = multiply(left, right); break;
    case '/': result = divide(left, right); break;
    case '=': result =  (left == right); break;
    default:  property_tests(left, right);
  }

  if(verbose) {
    printf("%d %c %d = %d\n", left, op, right, result);
  }
  return result;
}


// DEMO PURPOSES: a small driver to switch
// on and off different types of testing
int main(int argc, char *argv[]) {
  int mflag = 1;
  int uflag = 0;
  int verbose = 0;
  
  if(argv[1][0] == 'v') { verbose = 1; } 
  if(argv[1][0] == 'u') { uflag = 1; } 

  if(mflag) { mayhem_tests(verbose); } // do mayhem tests
  if(uflag) { unit_tests(); } // do unit test

  return 0;
}
