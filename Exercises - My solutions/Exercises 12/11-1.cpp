#include <iostream>

class Integer {
private:
  int i; // value
public:
  Integer(); // "constructor"
  void set(int newi); // "setter"
  int get(); // "getter"
  void print(); // print value
};

Integer::Integer() {
std::cout << "Integer constructor called" << std::endl;
}

void Integer::set(int newi) {
i = newi;
}

int Integer::get() {
return i;
}

void Integer::print() {
std::cout << "The value of i is: " << i << std::endl;
}

int main(int argc, const char *argv[]) {
Integer myint1 {Integer()};
myint1.set(5);
myint1.print();

Integer myint2 {Integer()};
myint2.set(2);
myint2.print();

Integer myint3 {Integer()};
myint3.set(-8);
myint3.print();

Integer myint4 {Integer()};

return 0;
}
