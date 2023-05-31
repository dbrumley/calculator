#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "calculator.h"

typedef struct stack {
  int data;
  struct stack *next;
} stack_t;

void stackdebug(int stack[], int i) {
  int j = 0;
  printf("  i: %d [", i);
  for(j = 0; j < i; j++) {
    printf(" %d,", stack[j]);
  }
  printf("] \n");
}

int main(int argc, char *argv[]) {
  int i = 0, integer = 0;
  int left, right;
  char op;
  int stack[10];
  char buf[128];
  char *token;

  read(0, buf, sizeof(buf));
  buf[sizeof(buf)-1] = 0;  // ensure null termination
  buf[strcspn(buf, "\n")] = 0; // remove newline

  token = strtok(buf, " ");
  while(token) {
    op = token[0]; // Check if +, -, *, /, or =. Else assume integer.
    switch(op) {
      case '+': 
        assert(i >= 2); 
        right = stack[--i];
        left = stack[--i];
        stack[i++] = add(left, right);
        break;

      case '-': 
        assert(i >= 2); 
        right = stack[--i];
        left = stack[--i];
        stack[i++] = subtract(left, right);
        break;

      case '*': 
        assert(i >= 2); 
        right = stack[--i];
        left = stack[--i];
        stack[i++] = multiply(left, right);
        break;
      
      case '/': 
        assert(i >= 2); 
        right = stack[--i];
        left = stack[--i];
        stack[i++] = divide(left, right);
        break;

      case '=': 
        assert(i >= 2); 
        right = stack[--i];
        left = stack[--i];
        assert(left == right);
        stack[i++] = left;
        break;

      default:
        integer = 0; // If sscanf says it's not an integer, default to value 0.
        sscanf(token, "%d", &integer);
        stack[i] = integer; i++;
        break;
    }
    token = strtok(NULL, " ");
  }
  printf("Final result: %d\n", stack[0]);
  return 0;
}