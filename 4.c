#include <stdio.h>
#include <stdbool.h>

int check_for_palindrome(int x, int y) {
    char buffer[33];
    int left = 0;
    int right = -1;

    sprintf(buffer, "%d", x * y); // Convert integer into a string

    for (int i = 0; i <= 33; i++) {
      if (buffer[i] == '\0') {
        right = i-1;
        break;
      }
    }

    bool found_palindrome = true;
    while (left < right) {
      if (buffer[left] != buffer[right]) {
        found_palindrome = false;
        break;
      }

      left++;
      right--;
    }

    if (found_palindrome) {
      printf("Palindrome: %8s | x: %d | y: %d | diff: %d\n", buffer, x, y, x - y);
      return x * y;
    }

    return 0;
}

// There's 
int main() {
  const int LOWER = 900;
  const int UPPER = 999;

  int max = 0;
  for (int i = LOWER; i <= UPPER; i++) {
    for (int j = LOWER; j <= UPPER; j++) {
      int product = check_for_palindrome(i, j);
      if (product > max) {
        max = product;
      }
    }
  }

  printf("%d\n", max);

  return 0;
}