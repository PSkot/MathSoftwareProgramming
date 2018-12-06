#include <stdio.h>


static int count = 0;
unsigned long fibonacci(unsigned long n);

int main(int argc, char const *argv[]) {

  unsigned long n = 10;


  for (unsigned long i = 0; i < n; i++) {
    fibonacci(i);
    printf("Count of function calls: %d\n", count);
    count = 0;
  }
  return 0;
}

unsigned long fibonacci(unsigned long n) {
  count++;
  if ( n == 0 )
    return 0;

  else if ( n == 1 )
    return 1;

  else
    return fibonacci(n-1) + fibonacci(n-2);
}
