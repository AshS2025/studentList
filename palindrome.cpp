/*
Project Description: Checks whether or not the letters in a user input form a palindrome
Date: 9/19/2023
Author: Ashvika Singhal
 */


#include <iostream>
#include <cstring>

using namespace std;

int main(){

  //read in input and delete null character
char input[81];
cin.getline(input, 80);


 //converting to lowercase
 for (int i = 0; i < strlen(input); i++){
 input[i] = tolower(input[i]);
 }

 //deleting punctuation
 for (int i = 0; i < strlen(input); i++){
   int result = isalpha (input[i]);
   if (result == 0) {
     for (int j = 1; j < strlen(input) - i; j++){
       input [i+j-1] = input [i+j];
     }
     input[strlen(input)-1] = '\0';
     i = i-1;
     }
   
 }

 //reverses the input array and puts it in a new array called backwards
 char backward[(strlen(input))];
 int backIndex = 0;

 for (int i = strlen(input) -1; i >= 0; i--){
		 if (input[i] != '\0'){
		   char a = input[i];
		   backward[backIndex] = a;
		   backIndex++;
		 }
	       }


 //checking if the arrays are the same
 int checkCount = 0;

 for (int i = 0; i < strlen(input); i++){
   if (input[i] == backward[i]){
     checkCount++;   
   }
   if (checkCount == strlen(input)){
     cout << "Palindrome" << endl;
   }
 }

 if (checkCount != strlen(input)){
   cout << "Not a Palindrome" << endl;
 }
 
 return 0;

}


//ideas for reversal of array from sophia you
