#include "Student.h"

#include <iostream>

using namespace std;

void printArr(student * arr, int size){
	for (int c=0;c<size;++c){
		arr[c].print();
		cout<<endl;
	}
}

void printArr(student ** arr, int size){
	for (int c=0;c<size;++c){
		arr[c]->print();
		cout<<endl;
	}
}

void AddScore(student & Stu, int * Score, int Size){
	for (int c=0;c<Size;++c){
		Stu.addQuizScore(Score[c]);
	}
}

student ** GPAaboveThres(student * arr, int size, int thres, int & TempCount){
	int counter=0;

	for (int c=0;c<size;++c){
		if (arr[c].getGPA()>2) ++counter;
	}

	student ** Temp=new student*[counter];

	for (int c=0;c<size;++c){
		if (arr[c].getGPA()>2){
			Temp[TempCount]=new student(arr[c]);
			++TempCount;
		}
	}

	return Temp;
}

void sortArr(student * arr, int size){

	bool swap=0;
	int n=size;

	for (int c=0;c<size;++c){

		--n;
		swap=0;

		for (int a=0;a<n;++a){
			if (arr[c].getGPA()<arr[c+1].getGPA()){
				student Temp=arr[c];
				arr[c]=arr[c+1];
				arr[c+1]=Temp;
				
				swap=1;
			}
		}

		if (swap==0) break;

	}

}

#define arrStaticSize 3
int main(){
#pragma region static array
	cout<<"\n\n\nStatic Array ";

#pragma region declaration and initiation
	student arrStatic[arrStaticSize]= { student(3,2), student(3,3), student(4,2.33)};

	int StaticScore[10];
	StaticScore[0]=1;
	StaticScore[1]=4;
	StaticScore[2]=10;

	AddScore(arrStatic[0],StaticScore,3);

	StaticScore[0]=10;
	StaticScore[1]=4;
	StaticScore[2]=9;

	AddScore(arrStatic[1],StaticScore,3);

	StaticScore[0]=9;
	StaticScore[1]=8;
	StaticScore[2]=7;

	AddScore(arrStatic[2],StaticScore,3);

	printArr(arrStatic ,arrStaticSize);    
#pragma endregion declaration and initiation


	cout<<"\n\nStudents above 2 GPA array";

	int TempCount=0;
	student ** Temp=GPAaboveThres(arrStatic,3,2,TempCount);

	printArr(Temp,TempCount);

	delete[] Temp;
	Temp=nullptr;

	cout<<"\n\n sorted array";
	sortArr(arrStatic,arrStaticSize);
	printArr(arrStatic,arrStaticSize);

#pragma endregion static array



#pragma region dynamic array
	cout<<"\n\n\nDynamic Array ";

#pragma region declaration and initiation
	student * arrDyn=new student [4];
	for (int c=0;c<3;++c){
		arrDyn[c]= arrStatic[c];
	}
	student dum(4,1);
	dum.addQuizScore(2); dum.addQuizScore(3);

	arrDyn[3]=dum;

	printArr(arrDyn,4);  
#pragma endregion declaration and initiation


	cout<<"\n\nStudents above 2 GPA array";

	TempCount=0;
	Temp=GPAaboveThres(arrDyn,3,2,TempCount);

	printArr(Temp,TempCount);

	delete[] Temp;
	Temp=nullptr;

	cout<<"\n\n sorted array";
	sortArr(arrDyn,4);
	printArr(arrDyn,4);
 
#pragma endregion dynamic array



	system("pause"); 
}
#undef arrStaticSize