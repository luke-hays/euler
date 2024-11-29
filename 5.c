// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>
#include <stdint.h>

// Some observations:
// It must be divisible by 20.
// Since 20 is a mulitple of 10 we don't need to check 10. Similarly we don't need to check 5, 4, or 2
// We need to check primes: 3, 7, 11, 13, 17, 19
// We can also cover multiples of 16 and 8 by incrementing our checks by 80
int main() {
  for(unsigned int i = 80; i <= UINT32_MAX; i+=80) {
    int found = 1;
    for (int j = 3; j <= 20; j += 2) {
      if (i % j != 0) {
        found = 0;
        break;
      }
    }

    if (found) {
      printf("Result: %d\n", i);
      break;
    }
  }

  return 0;
}