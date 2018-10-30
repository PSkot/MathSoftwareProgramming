#include "Header.h"

int main(int argc, char const *argv[]) {

  struct Length input_1 = {.yards = 3, .feet = 1, .inches = 2};
  struct Length input_2 = {.yards = 5, .feet = 0, .inches = 11};

  Length result = add(input_1, input_2);

  show(result);

  return 0;
}
