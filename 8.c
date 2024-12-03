#include <stdio.h>
#include <ctype.h>

const int BIG_NUM_LENGTH = 1000;
const int WINDOW_SIZE = 4;

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

  // product of 13 digits will result in a large number that overflows. Best to probably create a multiply function for large numbers
  // Will also need a way to compare the large number
  // Not a complete solution, can handle a size 4 window though
  int max_product = 0;
  int right = WINDOW_SIZE-1;
  while (right < BIG_NUM_LENGTH) {
    int product = 1;
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

  printf("Result: %d\n", max_product);

  return 0;
}
