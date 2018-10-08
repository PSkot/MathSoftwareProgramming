#include <stdio.h>

int main(void){

  float C = 0.0f, F = 0.0f;
  int selection = 0;

  printf("Please select a conversion. Type 1 for Celcius to Fahrenheit");
  printf(" or 2 for Fahrenheit to Celsius\n");

  scanf("%d", &selection);

  printf("Please specify the value to be converted:\n");

  if(selection == 1){
    scanf("%f", &C);
    printf("%.2f degrees Celcius corresponds to %.2f degrees Fahrenheit\n", C, 1.8*C+32);
  }
  else if(selection == 2){
    scanf("%f", &F);
    printf("%2.f degrees Fahrenheit corresponds to %.2f degrees Celcius\n", F, (F-32)*5/9);
  }
  else
    printf("Incorrect value selected. Terminating program\n");

  return 0;

}
