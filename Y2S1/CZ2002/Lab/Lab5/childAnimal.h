#ifndef _CHILDANIMALS_
#define _CHILDANIMALS_

#include "animal.h"
#include <iostream>
#include <string>
using namespace std ;
// enum COLOR { Green, Blue, White, Black, Brown } ;

class Dog: public Mammal{
  public: 
    Dog(string n, COLOR c, string o) : Mammal(n,c), owner(o){cout << "constructing Dog object " << endl ;}

    ~Dog() {cout << "destructing Dog object " << endl ; }

    void speak() const {
      cout << "Woof" << endl ;
    }

    void move(){
      cout << "Move Dog" << endl ;
    }
  private :
    string owner;
};

class Cat: public Mammal{
  public: 
    Cat(string n, COLOR c, string o) : Mammal(n,c), owner(o){cout << "constructing Cat object " << endl ;}

    ~Cat() {cout << "destructing Cat object " << endl ; }

    void speak() const {
      cout << "Meow" << endl ;
    }

    void move(){
      cout << "Move Cat" << endl ;
    }
  private :
    string owner;
};

class Lion: public Mammal{
  public: 
    Lion(string n, COLOR c, string o) : Mammal(n,c), owner(o){cout << "constructing Lion object " << endl ;}

    ~Lion() {cout << "destructing Dog object " << endl ; }

    void speak() const {
      cout << "Roar" << endl ;
    }

    void move(){
      cout << "Move Lion" << endl ;
    }
  private :
    string owner;
};

#endif // _CHILDANIMALS_