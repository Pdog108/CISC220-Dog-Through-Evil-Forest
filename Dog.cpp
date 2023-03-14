/*
 * Dog.cpp
 *
 *  Created on: Feb 21, 2022
 *      Author: Patrick Harris, Jake Ravett
 */

#include <iostream>
#include "Dog.hpp"
using namespace std;

Dog:: Dog(string n) {
	n = "n";
	strength = 50;
	x = 0;
	y = 0;
}

Dog::Dog() {
	name = "Fido";
	strength = 50;
	x = 0;
	y = 0;
}

bool Dog::changeStrength(int amt) {
  strength += amt;
  printDog();
  if (strength > 0) {
    return true;
  }
  else {
    die();
    return false;
  }
}

void Dog::die() {
    cout << "Oh No!! How could you let your dog die???" << endl;
}

void Dog:: printDog() {
  cout << name << endl;
  cout << strength << endl;
  }

  void Dog::won() {
  cout << "Hurray!! You kept your dog alive!!" << endl;
  }

  void Dog::reset() {
  strength = 20;
  x = 0;
  y = 0;
}
