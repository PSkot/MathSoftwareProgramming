#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int age;
  string name;

  cout << "Enter your name, please:\n";
  cin >> name;
  cout << "Enter your age, please:\n";
  cin >> age;
  cout << "Hello, " << name << "! Welcome to C++, you " << age << " year old bastard!\n";

  return 0;
}
