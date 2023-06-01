#include <stdio.h>
#include <assert.h>

int add(int x, int y) {
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  return x / y;
}

int equal(int x, int y) {
  return x == y;
}

int eval(char op, int left, int right) {
  switch(op) {
    case '+': return add(left, right);
    case '-': return subtract(left, right);
    case '*': return multiply(left, right);
    case '/': return divide(left, right);
    case '=': return equal(left, right);
    default: return 0;
  }
}
