#include <iostream> 
#include <string>
#include "animal.h"
#include "childAnimal.h"
using namespace std ;
int main() {
  // 3.2 
  // Animal a("Lion", Green);
  // Dog a("Dog", Green, "Vin");
  // a.speak() ;
  // a.eat() ;

  // 3.3.1
  // Animal *animalPtr = new Dog("Lassie", White, "Andy");
  // animalPtr->speak();
  // animalPtr->move();
  // animalPtr = NULL;
  // delete animalPtr; 

  // 3.3.3
  // Dog dogi("Lassie", White, "Andy"); 
  // Mammal *aniPtr = &dogi ;
  // Mammal &aniRef = dogi ;
  // Mammal aniVal = dogi ;
  // aniPtr->speak() ; 
  // aniRef.speak() ;
  // aniVal.speak() ;


  // 3.3.4
  Mammal *mArr[3]; 
  mArr[0] = new Dog("Lassie", White, "Andy");
  mArr[1] = new Cat("Lace", Black, "Vin");
  mArr[2] = new Lion("Peter", Brown, "Ali");

  cout << "Select the animal to send to Zoo :"  << endl;
  cout << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit"  << endl;
  int temp;
  cin >> temp;
  if(temp == 1){
    mArr[0]->move();
    mArr[0]->speak();
    mArr[0]->eat();
  }
  else if(temp == 2){
    mArr[1]->move();
    mArr[1]->speak();
    mArr[1]->eat();
  }
  else if(temp == 3){
    mArr[2]->move();
    mArr[2]->speak();
    mArr[2]->eat();
  }
  else if(temp == 4){
    for (int i = 0 ; i < 3; i++){
      mArr[i]->move();
      mArr[i]->speak();
      mArr[i]->eat();
    }
  }
  else{
    cout << "Quiting...." << endl;
    return 0;
  }

  cout << "Program exiting .... "<< endl ;
  return 0; 
}



