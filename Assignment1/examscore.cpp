//<examscore.cpp> should include two method, addExamScore, and removeExamScore.

#include "examscore.h"
#include <vector>
#include <iostream>
using namespace std;

void addExamScore(vector<int> &scoreArr){
	int grade;
	cout<<"Enter the exam score you want to add: ";
        cin>>grade;
        scoreArr.push_back(grade);
	cout<<"Exam score added."<<endl<<endl;;
}

void removeExamScore(vector<int> &scoreArr){
	if(scoreArr.size()>0){
		scoreArr.pop_back();
		cout<<"Exam score removed."<<endl<<endl;
	}
	else{
		cout<<"There are no more scores left in the list to remove."<<endl<<endl;
	}
}


