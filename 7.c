// Sieve of Eratosthenes
// By no means a finished solution but its a start
#include <stdio.h>

int main() {
  const int LIMIT = 1000000;
  const int NUM = 10001;
  int primes[LIMIT];

  for (int i = 0; i < LIMIT; i++) {
    primes[i] = i;
  }

  int primeCount = 0;

  for (int i = 2; i < LIMIT; i++) {
    // If this is a composite number, skip it
    if (primes[i] == 0) continue;

    primeCount += 1;
    if (primeCount == NUM) {
      printf("Result: %d\n", i);
      break;
    }

    // Check every multiple of the smallest number
    int j = i + i;
    while (j < LIMIT) {
      primes[j] = 0;
      j += i;
    }
  }

  return  0;
}