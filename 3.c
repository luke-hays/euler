// The prime factors of 13195 are 5, 7, 13, and 29
// What is the largest prime factor of the number 600851475143?

const long LARGE_NUMBER = 600851475143;

#include <stdio.h>

// Most basic algorithm to find a prime factorization
// Runs in O(sqrt(n)) time (pseudo-polynomial)
void trial_division(long n) {
  // Divide by each possible divisor d.
  // It is impossible for all prime factors of a composite number n to be > sqrt(n)
  // So we only need to test divisors 2 <= d <= sqrt(n)
  long factor;
  for (long divisor = 2; divisor * divisor <= n; divisor++) {
    // Try to divide n by successive primes
    while (n % divisor == 0) {
      n /= divisor;
      printf("%d\n", divisor);
    }
  }
  if (n > 1) {
    printf("%d\n", n);
  }
}

int main() {
  // How do we programmatically find prime factors?
  trial_division(LARGE_NUMBER);
  return 0;
}