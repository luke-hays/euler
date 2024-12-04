#include <stdio.h>
#include <ctype.h>

const int BIG_NUM_LENGTH = 1000;
const int WINDOW_SIZE = 13;

int main() {
  FILE *file = fopen("big_num.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int digits[BIG_NUM_LENGTH];
  int i = 0;
  int ch;

  while ((ch = fgetc(file)) != EOF) {
    if (isdigit(ch)) {
      digits[i] = ch - '0';
      i++;
    }
  }

  fclose(file);

  unsigned long long max_product = 0;
  int right = WINDOW_SIZE-1;
  while (right < BIG_NUM_LENGTH) {
    unsigned long long product = 1;
    int containsZero = 0;

    for (int i = right; i > right - WINDOW_SIZE; i--) {
      if (digits[i] == 0) {
        containsZero = 1;
        break;
      }
      product *= digits[i];
    }

    if (containsZero) {
      right++;
      continue;
    }

    if (product > max_product) {
      max_product = product;
    }

    right++;
  }

  // Need to remember to use the correct formatter
  printf("Result: %llu\n", max_product);

  return 0;
}

# 2147483647