#include "avgarray.h"

int main(int argc, char const *argv[]){
double *pNumbers = NULL;            //Pointer to numbers storage area
unsigned int count = 0;             //Number of numbers entered
int CAP_INCR = 10;

//Allocate initial memory
size_t capacity = 10;
pNumbers = (double*)calloc(capacity, sizeof(double));

if(!pNumbers)
{
  printf("Not enough memory. Terminating program\n");
  return 1;
}

//Enter numbers
double *pTemp = NULL;

printf("Please enter your numbers.\n>");

  /* code */
double number = 0.0;
while(scanf("%lf", &number) == 1){
  if(count == capacity)
  {
    capacity += CAP_INCR;
    pTemp = (double*)realloc(pNumbers, capacity*sizeof(double));
    if(!pTemp)
    {
      printf("Memory reallocation failed.\n");
      free(pNumbers);
      pNumbers = NULL;
      return 2;
    }
    pNumbers = pTemp;
  }
  pNumbers[count++] = number;
  printf(">");
}

  printf("Your average value is %.2lf\n", avgarray(pNumbers, count));
  return 0;

}
