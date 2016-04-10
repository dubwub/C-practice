#include <iostream>

class Animal {
public:
  virtual void speak() {};

  virtual ~Animal() {}
};

class Tiger : public virtual Animal {
public:
  void speak() {std::cout << "i'm a tiger" << std::endl;}
};

class Lion : public virtual Animal {
public:
  //void speak() {std::cout << "i'm a lion" << std::endl;}
};

class Liger : public Tiger, public Lion {
  //public:
  //void speak();
};

int main () {
  Liger* l = new Liger();
  Lion* lion = l;
  lion->speak();

  delete l;
}
