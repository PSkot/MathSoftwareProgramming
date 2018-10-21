#include <stdio.h>
#include <stdlib.h>
#define VALS 6

int main(void)
  {
  double *temperatures = NULL, *Temp = NULL;
  int n = 0;
  int i = 0;
  int j = 0;
  double avg = 0.0;

  //Allocate memory for first day
  size_t N = 1;
  temperatures = (double*)calloc(N*VALS, sizeof(double));

  if(!temperatures)
  {
    printf("Not enough memory. Terminating program\n");
    return EXIT_FAILURE;
  }



printf("Please enter your temperatures for:\nDay 1:\n1>");
  double number = 0.0;
  while(scanf("%lf", &number) == 1){

    if (n == N)
    {
      N = N + 1;
      Temp = (double*)realloc(temperatures, N*VALS*sizeof(double));
      if(!Temp){
        printf("Memory reallocation failed.\n");
        free(temperatures);
        temperatures = NULL;
        return 2;
      }
      temperatures = Temp;
    }

    for(i = 0; i < VALS; ++i){
      if(i != 0)
        {
        printf("%d>", i+1);
        scanf("%lf", &number);
        }
      temperatures[i+n*VALS] = number;
      }
      ++n;
      printf("Day %d:\n1>", n+1);
    }

  for(i = 0; i < VALS; ++i){
    printf("\tV%d", i+1);
  }

  printf("\tAvg\n");
  for (i = 0; i < n; ++i){
    printf("Day %d", i+1);
    for(j = 0; j < VALS; ++j)
    {
      printf("\t%.1lf", temperatures[j+i*VALS]);
      avg += temperatures[j+i*VALS];
    }
  avg /= VALS;
  printf("\t%.1lf\n", avg);
  avg = 0.0;
  }

  free(temperatures);
  temperatures = NULL;
  return 0;

}
