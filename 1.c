// Find the sum of all the multiples of 3 or 5 below 1000
#include <stdio.h>

int main() { 
 	// An integer a is a multiple of b if a = b * n for some integer n
  // Or we can say that an integer a is divisible by b if the result is an integer

  int sum = 0;
  for(int i = 1; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  
  printf("Result: %d\n", sum);

	return 0;
}
