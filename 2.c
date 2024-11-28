// Consider the terms in the fibonacci sequence whos values do not exceed 4 million
// Find the sum of the even valued terms
#include <stdio.h>

int main() {
  int a = 1;
  int b = 2;

  int sum = 2;
  while (a < 4000000) {
    int tmp = b;
    b = a + b;
    a = tmp;

    if (b % 2 == 0) {
      sum += b;
    }
  }

  printf("Result: %d\n", sum);

  return 0;
}