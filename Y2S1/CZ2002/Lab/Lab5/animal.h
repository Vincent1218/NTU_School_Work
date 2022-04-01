#ifndef _ANIMALS_
#define _ANIMALS_

#include <iostream>
#include <string>
using namespace std ;
enum COLOR { Green, Blue, White, Black, Brown } ;

class Animal {
  public :
    Animal() : _name("unknown") {
      cout << "constructing Animal object "<< _name << endl ;
    } 
    Animal(string n, COLOR c) : _name(n),_color(c){
      cout << "constructing Animal object "<< _name << " " << _color << endl ;
    } 
    ~Animal() {
      cout << "destructing Animal object "<< _name << endl ; 
    }
    virtual void speak() const {
      cout << "Animal speaks "<< endl ;
    }
    virtual void move() = 0;


  private :
        string _name;
        COLOR _color ;
};

class Mammal: public Animal{
  public: 
    Mammal(){cout << "Default constructing Mammal object " << endl ;}
    Mammal(string n, COLOR c) : Animal(n,c){cout << "constructing Mammal object " << endl ;}

    ~Mammal() {cout << "destructing Mammal object " << endl ;}

    void eat() const {
      cout << "Mammal eat " << endl ;
    }
    void move()  {
      cout << "Mammal move " << endl ;
    }
};

#endif // _ANIMALS_