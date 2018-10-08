#include <stdio.h>

int main(void){
  const unsigned int MIN_SIZE = 1;
  unsigned int row = 0;
  unsigned int column = 0;

  printf("Please enter values for the number of columns and rows, respectively:\n");
  scanf("%u%u", &row, &column);

  if(row < MIN_SIZE)
  {
    printf("%u below %u, setting to %u\n", column, MIN_SIZE, MIN_SIZE);
    column = MIN_SIZE;
  }
  if(row < MIN_SIZE)
  {
    printf("%u below %u, setting to %u\n", row, MIN_SIZE, MIN_SIZE);
    row = MIN_SIZE;
  }

  //Output rows
  for(unsigned int i = 0 ; i < column ; ++i)
    printf("\t%u", i+1);

  //Output columns and calculations
  for(unsigned int j = 0 ; j < row ; ++j){
    printf("\n%u", j+1);
      for(unsigned int i = 0 ; i < column ; ++i){
        printf("\t%u", (i+1)*(j+1));
      }
  }

  printf("\n");

  return 0;

}
