#include "Coordinates.h"

double area(coords input);
coords scan(void);
BARYCEN barycentric(coords t);

int main(int argc, char const *argv[]) {

  double tri_area = 0;
  coords tri_coords = scan();
  tri_area = area(tri_coords);
  BARYCEN bar_coords = barycentric(tri_coords);

  printf("The area of the triangle is: %.2lf square units\n", tri_area);

  printf("The barycentric coordinates are: %.2f, %.2f, %.2f\n", bar_coords.l_1, bar_coords.l_2, bar_coords.l_3);

  if(bar_coords.l_1 < 0 || bar_coords.l_2 < 0 || bar_coords.l_3 < 0)
    printf("The coordinates are outside of the triangle\n");
  else
    printf("The coordinates are inside the triangle\n");

  return 0;
}

double area(coords input){

  return (input.x_1*input.y_2+input.x_2*input.y_3+input.x_3*input.y_1-input.x_1*input.y_3-input.x_2*input.y_1-input.x_3*input.y_2)/2;

}

coords scan(){

  coords output;

  printf("Please enter x1 and y1\n");
  scanf("%d", &output.x_1);
  scanf("%d", &output.y_1);

  printf("Please enter x2 and y2\n");
  scanf("%d", &output.x_2);
  scanf("%d", &output.y_2);

  printf("Please enter x3 and y3\n");
  scanf("%d", &output.x_3);
  scanf("%d", &output.y_3);

  return output;

}

BARYCEN barycentric(coords t){

  int x, y = 0;
  double lambda_1, lambda_2, lambda_3 = 0.0;
  printf("Please input coordinates:\n");
  scanf("%d", &x);
  scanf("%d", &y);

  lambda_1 = (double)((t.y_2-t.y_3)*(x-t.x_3)+(t.x_3-t.x_2)*(y-t.y_3))/((t.y_2-t.y_3)*(t.x_1-t.x_3)+(t.x_3-t.x_2)*(t.y_1-t.y_3));
  lambda_2 = (double)((t.y_2-t.y_1)*(x-t.x_3)+(t.x_1-t.x_3)*(y-t.y_3))/((t.y_2-t.y_3)*(t.x_1-t.x_3)+(t.x_3-t.x_2)*(t.y_1-t.y_3));
  lambda_3 = 1 - lambda_1 - lambda_2;

  BARYCEN lambdas = {.l_1 = lambda_1, .l_2 = lambda_2, .l_3 = lambda_3};
  return lambdas;

}
