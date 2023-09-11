/*
Project: Guessing Game
Description: Randomly generates a number and tells the user whether their guess is higher or lower than the chosen value.
Author: Ashvika Singhal

The 3 Rules for this Class (but there's actually 5):
1. no global variables
2. no strings
3. include <iostream> not stdio 
4. don't use mouse
5. try not to use break/continue
*/

#include <iostream>
using namespace std;

int main() {

  //initializations
  srand(time(NULL));
  int guesscount = 0;
  int userguess = 0;

  //generate random number
  int randnum = 0;
  randnum = rand() % 101;
  
  //boolean for the loop
  bool playing = true;

  cout << "Guess a number from 0 to 100." << endl;

  while (playing == true) {

    cin >> userguess;
    guesscount++;

    if (userguess > randnum) { //indicates if user's guess is too high
      cout << "too high" << endl;
    }

    else if (userguess < randnum) { //indicates if user's guess is too low
      cout << "too low" << endl;
    }

    else if (userguess == randnum) { //yay number has been guessed
      cout << "You guessed the number congratulations." << endl;
      cout << "guesscount: " << guesscount << endl; //# of guesses
      cout << "type y if u want to play again, type n if ur done"<< endl;
      char input = 'a';
      cin >> input;

      
      if (input == 'y') {
        playing = true;
	//setting up next game if user decides to play again
        randnum = rand() % 101;
        guesscount = 0;
        userguess = 0;
        cout << "Guess a number from 0 to 100." << endl;
      } 
      
      else if (input == 'n') {
        playing = false; //end the program if they are not playing again
      }
    }
  }
}
