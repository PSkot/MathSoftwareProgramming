#include <stdio.h>
void swap2(int* a, int* b); // Function prototype
int main(void) {
int a = 1, b = 3;
swap2(&a,&b);
printf("a = %d and b = %d\n",a,b);
return 0;
}
void swap2(int* a, int* b) {
int c = *a; // Store value of *a in c
*a = *b; // Overwrite *a with *b
*b = c; // Overwrite *b with c
return;
}
