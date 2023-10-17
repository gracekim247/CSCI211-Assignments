//<main.cpp> should contain all the other function, 
//and also call the add and remove function that are in <examscore.cpp>

#include <iostream>
#include <vector>
#include "examscore.h"

using namespace std;

int main() {
	// Create a vector to store exam scores as integers
	vector<int> scores;
       
	while (true) {
		//display the menu-driven interface
		cout<<"Choose from the following choices: "<<endl;
		cout<<"1. Add an exam score to the list."<<endl;
		cout<<"2. Remove the last exam score from the list."<<endl;
		cout<<"3. Display the current number of exam scores in the list."<<endl;
		cout<<"4. Exit the program."<<endl;

		//ask the user to choose from the menu
		cout<<"Enter the number of the option you want to choose from the menu: ";
		int ans;
		cin>>ans;
		

		// use if and else statements to check if the user input is one of the valid options
		if(ans>=1 && ans<=4){
			//use "switch" statement to implement the functions of each option
			switch (ans){
				case 1: {
						addExamScore(scores);
						break;
					}
				case 2: {
						removeExamScore(scores);
						break;
					}
				case 3: {
						int size;
						size = scores.size();
						cout<<"There are "<<size<<" scores in the list."<<endl<<endl;
						break;
					}
				case 4:{
						cout<<"The program will now exit."<<endl<<endl;
						exit(0);
					}
			}
		}
		else{
			cout<<"Your input is invalid. Please enter a valid option (1-4)."<<endl<<endl;
			continue;
		}
	}
	return 0;
}
