// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum
#include <stdio.h>

int main() {
  int sumOfSquares = 0;
  int squareOfSum = 0;

  for (int i = 1; i <= 100; i++) {
    sumOfSquares += (i * i);
    squareOfSum += i;
  }

  squareOfSum *= squareOfSum;

  printf("Sum of Squares: %d\nSquare of the Sum: %d\nDiff: %d\n", sumOfSquares, squareOfSum, squareOfSum - sumOfSquares);

  return 0;
}