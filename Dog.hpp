/*
 * Dog.hpp
 *
 *  Created on: Feb 21, 2022
 *      Author: Patrick Harris, Jake Ravett
 */
#include <iostream>
#include <string.h>
using namespace std;

#ifndef DOG_HPP_
#define DOG_HPP_

class Dog {

 friend class Board;//by making the Board a friend of this //class, the
 //Dog class is allowing the board class and objects to access //all of the dog class' private fields

 string name; //for the dog's name
 int strength; //for the dog's current strenght
 int x; //the x coordinate of where the dog is currently on the board
 int y; //the y coordinate of where the dog is currently on the board


public:
 Dog(string n);
 /* constructor, sets the name to be whatever name *gets passed in
 */

 Dog();
 //constructor

 bool changeStrength(int amt);
   /*changeStrength modifies the strength property *by whatever amt is (basically adding here)
   * It then calls printDog method to print out *current information about the dog.
   * It also checks to make sure that the dog *object's strength is >0.
   * If the dog object's strength is 0 or less, it *calls the die method.
   * It returns true if the strength is still >0 *and false otherwise.
   */
 void die();
   //This method just prints out a sad pathetic //death of a dog message
 void printDog();
   /* this method just prints out the basic *information about the dog - its
   *name and its current strength.
   */
 void won();
   /* just a message about the user's incredible *prowess in successfully navigating the
   * sweet little puppy dog through the evil *forest to the other side
   */
 void reset();
   // this method just resets the strength
};

#endif /* DOG_HPP_ */
