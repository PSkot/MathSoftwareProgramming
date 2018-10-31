#include "Header.h"

Length_t add(Length_t input_1, Length_t input_2);
int show(Length_t output);

int main(int argc, char const *argv[]) {

  Length_t input_1 = {.yards = 3, .feet = 1, .inches = 2};
  Length_t input_2 = {.yards = 5, .feet = 0, .inches = 11};

  Length_t result = add(input_1, input_2);

  show(result);

  return 0;
}


int show(Length_t output){
  return
  printf("Total yards: %d\nTotal feet: %d\nTotal inches: %d\n",
        output.yards, output.feet, output.inches);
}


Length_t add(Length_t arg1, Length_t arg2){

  int yards, feet, inches, total_inches;

  int total_inches_1 = arg1.yards*36 + arg1.feet*12 + arg1.inches;
  int total_inches_2 = arg2.yards*36 + arg2.feet*12 + arg2.inches;

  total_inches = total_inches_1 + total_inches_2;
  yards = total_inches/36;
  feet = (total_inches%36)/12;
  inches = total_inches - feet*12 - yards*36;

  Length_t result = {.yards = yards, .feet = feet, .inches = inches};

  return result;

}
