#include "Header.h"

Length add(Length arg1, Length arg2){

  int yards, feet, inches, total_inches, total_inches_1, total_inches_2;

  int total_inches_1 = arg1.yards*36 + arg1.feet*12 + arg1.inches;
  int total_inches_2 = arg1.yards*36 + arg1.feet*12 + arg1.inches;

  total_inches = total_inches_1 + total_inches_2;
  yards = total_inches/36;
  feet = (total_inches%36)/12;
  inches = total_inches - feet*12 - yards*36;

  return
  {
    yards;
    feet;
    inches;
  };

}
