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
  Integer add(Integer Obj);
  Integer subtract(Integer Obj);
  Integer multiply(Integer Obj);
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

Integer Integer::add(Integer Obj){
  Integer result;
  result.set(get()+Obj.get());
  return result;
}

Integer Integer::subtract(Integer Obj){
  Integer result;
  result.set(get()*Obj.get());
  return result;
}

Integer Integer::multiply(Integer Obj){
  Integer result;
  result.set(get()*Obj.get());
  return result;
}


int main(int argc, const char *argv[]) {

Integer I1 = Integer(); I1.set(4);
Integer I2 = Integer(); I2.set(5);
Integer I3 = Integer(); I3.set(6);
Integer I4 = Integer(); I4.set(7);
Integer I5 = Integer(); I5.set(8);

(I1.multiply(I2).multiply(I2).multiply(I2)).add(I3.multiply(I2).multiply(I2)).add(I4.multiply(I2)).add(I5).print();

return 0;
}
