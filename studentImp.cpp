#include "Student.h"

#include <iostream>

using namespace std;

int student::counter=1;


#pragma region constructors and destructors

//default constructor
student::student(){
	//default quiz capacity
	const int defQuizCap=3;

	//assigns ID & increments static variable counter
	ID=counter;
	++counter;

	quizCapacity=defQuizCap;
	quizScore=new float[quizCapacity];
	quizTaken=0;

	GPA=-1;
}

student::student(int quizCap, int GPAPassed){
	ID=counter;
	++counter;

	quizCapacity=quizCap;
	quizScore=new float[quizCapacity];
	quizTaken=0;

	GPA=GPAPassed;
}

//copy constructor
student::student(const student & CFrom){
	ID=CFrom.ID;

	quizCapacity=CFrom.quizCapacity;
	quizTaken=CFrom.quizTaken;
	quizScore=new float[quizCapacity];

	//copy data from array
	for (int c=0;c<quizTaken;++c){
		quizScore[c]=CFrom.quizScore[c];
	}

	GPA=CFrom.GPA;
}

//destructor
student::~student(){
	delete[] quizScore;
}

#pragma endregion constructors and destructors

void student::addQuizScore(int Score){
	//if capacity in array available and score is sensible
	if (quizCapacity>quizTaken){
		if (Score>0){
			quizScore[quizTaken]=Score;
			++quizTaken;
		}
		else cout<<"Score is invalid";
	}
	else cout<<"array is full";
}

void student::SetGPA(float GPApassed){
	if (GPApassed>=0 && GPApassed<=4){
		GPA=GPApassed;
	}
	else cout<<"Invalid GPA";
}

float student::getGPA() const { return GPA; }

void student::print() const{
	cout<<endl<<"ID= "<<ID;
	cout<<endl<<"GPA= "<<GPA;
	cout<<endl<<"quizes Taken= "<<quizTaken;
	cout<<endl<<"quiz scores: "<<endl;
	
	for (int c=0;c<quizTaken;++c){
		cout<<quizScore[c]<<" ";
	}
}

bool student::compare(student B){
	if (GPA>B.GPA){
		return 1;
	}
	else return 0;
}
//takes parameters index to store score on and score
void student::updateScore(int index, int score){
	if (index>=0 && index<=quizTaken){
		if (score>0){
			quizScore[index]=score;
		}
		else cout<<"invalid quiz score";
	}
	else cout<<"invalid index";
}