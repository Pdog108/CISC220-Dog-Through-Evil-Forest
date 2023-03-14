/*
 * Board.cpp
 *
 *  Created on: Feb 21, 2022
 *      Author: Patrick Harris, Jake Ravett
 */
#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board(char diff, bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}

Board::Board(bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}

Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	mydog.name = name;
	wallStrength = 6;
	InitAll();
}

void Board::InitAll() {
	bool keepPlaying = true;
	while (keepPlaying) {
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size + 1;
		starty = 0;
		endx = rand() % size + 1;
		endy = size-1;
		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
		/*cout << "Done adding" << endl;*/
		printBoard();
		mydog.printDog();
		playGame();
		cout << "Play again? (Y/Yes/N/No)" << endl;
		string s = "no";
		cin>>s;
		if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
			keepPlaying = true;
			mydog.reset();
	}
	else {
		cout <<"Thanks for playing!" << endl;
		keepPlaying = false;
		}
	}
}

void Board::playGame() {
	bool play = true;
	while (play) {
	cout << "Move (u, d, l, r) "<<endl;
	char c;
	cin >> c;
	play = moveDog(c);
	printBoard();
	}
}

/* (5 pts) code for the addFood method goes here */
 void Board::addFood() {
	 /* cout << "This is the beginning of the addFood function" << endl; */
	 int total = 0;
	 if(level == 'e') {
     //Easy level
     total = size;
   }
    else if(level == 'm') {
     //medium level
     total = size - 2;
   }
   else if (level == 'h') {
     //hard level
     total = size - 4;
   }
   int foodPlaced = 0;
   int x;
   int y;
   while(foodPlaced < total) {
    //places a random amount of food on the board
     x = rand()%20;
     y = rand()%20;
     /*cout << x << endl;*/
     /*cout << y << endl;*/
     /*cout << "|" << board[x][y] <<"|" << endl;*/
     if(board[x][y] == ' ') {
       board[x][y] = 'F';
       foodPlaced++;
     }
  }
   /*cout << "End of addFood" << endl;*/
}

/* (5 pts) code for the addTraps method goes here */
void Board::addTraps() {
	/* cout << "This is the beginning of the addTraps method" << endl; */
	int total = 0;
	if (level == 'e') {
	  total = 6;
	  }
	else if (level == 'm') {
	  total = 8;
	  }
	else if (level == 'h') {
	  total = 10;
	  }
	int trapPlaced = 0;
	  int x;
	  int y;
	  while(trapPlaced < total) {
		//places a random amount of traps on the board
		x = rand()%20;
		y = rand()%20;
		if(board[x][y] == ' ') {
		  board[x][y] = 'T';
		  trapPlaced++;
		}
	  }
	  /* cout << "This is the end of the addTraps method" << endl; */
	}

/* (8 pts) code for the boardConfig method goes here */
void Board::boardConfig() {
for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (y==0 || y==19) { //If at the top or bottom of grid
				board[y][x] = '-';
			}
			else if (x==0 || x==19) { //If at left or right of grid
				board[y][x] = '|';
			}
			else {
				board[y][x] = ' ';
			}
		}
	}

	//Determines the wall's length based on difficulty
	int wallLength;
	if (level == 'e') {
		wallLength = 9;
	}
	else if (level == 'm') {
		wallLength = 13;
	}
	else {
		wallLength = 16;
	}

	//Adds 10 walls
	for (int i = 0; i < 10; i++) { //Loops through ten walls
		int direction = rand()%2; //Whether going vertical (1) or horizontal (0)
		int row = rand()%8 * 2 + 2; //Chooses a random row or column, even numbers only
		int slabCounter = 0; //How many slabs each wall has

		for (int j = 1; j < size-1; j++) {//Builds each individual slab of wall
			int buildSlab = rand()%3; //Whether should build a slab or not
			if (direction) {
				if (buildSlab) {
					board[j][row] = '|';
					slabCounter++;
				}
			} else {
				if (buildSlab) {
					board[row][j] = '-';
					slabCounter++;
				}
			}
			if (slabCounter >= wallLength) {
				break;
			}
		}
	}

	board[startx][starty] = '>'; //Places entrance
	board[endx][endy] = 'E'; //Places exit
	board[mydog.x][mydog.y] = 'D'; //Places dog
  }


/* (8 pts) code for the printBoard method goes here */
void Board::printBoard() {
	/* cout << "This is the beginning of the printBoard method" << endl; */
	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
	/* cout << "This is the end of the printBoard method" << endl; */
}

/* (12 pts) code for the moveDog method goes here */
bool Board::moveDog(char c) {
	/* cout << "This is the beginning of the moveDog method" << endl; */
	if (mydog.strength <= 0) {
		mydog.die();
		return false;
	}
	int x = mydog.x;
	int y = mydog.y;
	//cout << x << endl; checking coordinates of x location
	//cout << y << endl; checking location coordinates of y location
	board[mydog.x][mydog.y] = ' ';
	bool move = false;
	bool alive = true;
	//if alive then that is set to true
	switch(c) {
	  case 'u':
	  //for moving up
	  x -= 1;
	  mydog.printDog();
	  break;
	  case 'd':
	  //for moving down
	  x += 1;
	  mydog.printDog();
	  break;
	  case 'l':
	  // for moving left
	  y -= 1;
	  mydog.printDog();
	  break;
	  case 'r':
	  //moving right
	  y += 1;
	  mydog.printDog();
	  break;
	  }
	  char next = board[x][y];
	  if ((x > 19 || x < 0) || (y > 19 || y < 0)) {
	    cout << endl << "Wrong Way!" << endl;
	  }
	  else if (next == 'T') {
	    int dmg = (rand() % 16) + 2;
	    cout << endl << mydog.name << " you hit a trap and lost " << dmg << " health!" << endl;
	    alive = mydog.changeStrength(dmg * -1);
	    move = true;
	  }
	  else if (next == 'F') {
	    int dmg = (rand() % 16) + 2;
	    cout << endl << mydog.name << " you ate some food and gained " << dmg <<" health!" << endl;
	    alive = mydog.changeStrength(dmg);
	    move = true;
	  }
	  else if(next == 'E') {
	    mydog.won();
	    return false;
	    //game is over so you are no longer alive which is why alive is set to false
	  }
	  else if (next == '|' || next == '-') {
	    string res;
	    cout << "Do you want to knock down that wall? (Y or N?)" << endl;
	    cin >> res;
	    if (res == "Y" || res == "y") {
	      alive = mydog.changeStrength(-6);
	      //here the user responds yes and so the dog knocks down the wall, moves to that spot and the dog's strength then decreases by 6
	      move = true;
	    }
	  }
  	  else {
		move = true;
	  }
	    if(move) {
	    	alive = mydog.changeStrength(-2);
	    	mydog.x = x; //updates the x position of the dog
	    	mydog.y = y; //updates the y position of the dog
	    	move = true;
	    }
	    board[mydog.x][mydog.y] = 'D';
        mydog.printDog();
	    return alive;
	    /* cout << "This is the end of the moveDog method" << endl; */
}
