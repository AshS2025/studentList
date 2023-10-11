/*
Project: Student List
Description: allows user to store and manipulate students in an expandable list
Author: Ashvika Singhal
Completion Date: 10/11/2023
 */


#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip> //for setprecision command

using namespace std;

//student struct
//each student is composed of a first name, last name, id, and gpa
//4 things are a package deal
struct Student {
  char name[20];
  char lastname[20];
  int id;
  float gpa;

};

void addStudent (vector<Student*>&students);//add students to list
void deleteStudent (vector<Student*>&students);//delete student from list
void printStudents (vector<Student*>&students);//print all students in the list

//main function. instructions + allows users to choose whether to add delete or print students.
int main() {

  vector<Student*> students;

  //general instructions bc i'm cool like that
  cout << "How to use this program:" << endl;
  cout << "type 'ADD' to add student to list" << endl;
  cout << "type 'PRINT' to print all students in list" << endl;
  cout << "type 'DELETE' to delete a student from list" << endl;
  cout << "type 'QUIT' to quit program" << endl;
  cout << "after each action type 'y' to exit program or 'n' to keep going" << endl;
  cout << '\n' << endl;
  
  bool stillGoing = true; 
  while (stillGoing == true){ //while loop ensures program doesn't die after one action
  char input[7];
  cout << "type 'ADD' or 'PRINT' or 'DELETE' or 'QUIT'" << endl;

  //reading in an input and using string-compare to match it to a command
  cin >> input;

  if (strcmp(input, "ADD") == 0){
    addStudent(students);
  }
  if (strcmp(input, "DELETE") == 0){
    deleteStudent(students);
  }
  if (strcmp(input, "PRINT") == 0){
    printStudents(students);
  }
  if (strcmp(input, "QUIT") == 0){
    stillGoing = false; //QUIT ends the while loop thus ending the program
  }
  
  cout << '\n' << endl; //spacing bc otherwise my eyes hurt
  }
  
}

//creates a new student pointer to add to the vector
//dereferences the pointer to add in the components of the struct
//puts the pointer value into the vector and then gets rid of the memory allocation for the created pointer
//ADDS STUDENT TO THE LIST
void addStudent(vector<Student*>&students){
  Student* add = new Student();
  cout << "enter first name"<< endl;
  cin >> (*add).name;
  cout << "enter last name"<< endl;
  cin >> (*add).lastname;
  cout << "enter student id" << endl;
  cin >> (*add).id;
  cout << "enter gpa (two decimal places)" << endl;
  cin >> (*add).gpa;
  students.push_back(add);
}


//deletes the student whose id matches the inputted id
void deleteStudent (vector<Student*>&students){
  int findId;
  cout << "type the id of the student you want to delete" << endl;
  cin >> findId;
  for (vector<Student*>:: iterator it = students.begin(); it != students.end(); it++){
    if ((*it)->id == findId){ //delete, erase, break
      delete *it;    
      students.erase(it);
      break;
        }
  }

}

//walks through the vector, dereferences each pointer, prints the student structs
void printStudents (vector<Student*>&students){
  cout << '\n' << endl;
  for (vector<Student*>:: iterator it = students.begin(); it != students.end(); it++){
    cout << (*it)->name << " " << (*it)->lastname << ", " << (*it)->id << ", " << setprecision(3) << (*it)->gpa << endl;
  }
  cout << '\n' << endl; //line spaces are for my sanity
}
