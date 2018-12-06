#include <iostream>

class Integer {
private:
  int i = 0; // value
public:
  Integer(); // "constructor"
  void set(int newi); // "setter"
  int get(); // "getter"
  void print(); // print value
  Integer(const Integer& Obj);
  int compareInt(Integer aInteger);
  int compareIntRef(Integer& aInteger);
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

Integer::Integer(const Integer& Obj){
  i = Obj.i;
}

int Integer::compareInt(Integer aInteger){
  if(get() < aInteger.get())
    return -1;
  else if(get() == aInteger.get())
    return 0;
  else
    return 1;
}

int Integer::compareIntRef(Integer& aInteger){
  if(get() < aInteger.get())
    return -1;
  else if(get() == aInteger.get())
    return 0;
  else
    return 1;
}

int main(int argc, const char *argv[]) {
  Integer myint1 {Integer()};
  myint1.set(5);
  myint1.print();

  Integer myint2 {Integer()};
  myint2.set(-7);
  myint2.print();

  Integer myint3 {Integer()};
  myint3.set(-8);
  myint3.print();

  Integer myint4 {myint3};
  myint4.print();

  int result = myint4.compareInt(myint2);

  if(result == -1)
    std::cout << "Myint4 is smaller" << std::endl;
  else if (result == 0)
    std::cout << "Myint4 is equal" << std::endl;
  else
    std::cout << "Myint4 is larger" << std::endl;

  int result2 = myint4.compareIntRef(myint2);

  if(result2 == -1)
    std::cout << "Myint4 is smaller" << std::endl;
  else if (result2 == 0)
    std::cout << "Myint4 is equal" << std::endl;
  else
    std::cout << "Myint4 is larger" << std::endl;

return 0;
}
