#include "Student.h"

#include <iostream>

using namespace std;

//int main(){
//	student s1;
//
//	s1.addQuizScore(10);
//	s1.addQuizScore(3);
//	s1.addQuizScore(7);
//	s1.addQuizScore(1);
//
//	s1.print();
//
//	cout<<endl<<endl;
//
//	student s2(4,2);
//
//	s2.addQuizScore(9);
//	s2.addQuizScore(4);
//	s2.addQuizScore(6);
//
//	s2.print();
//
//	cout<<endl<<endl;
//
//	student s3=s1;
//
//	s1.updateScore(1,3);
//
//	s3.updateScore(10,3);
//
//	cout<<endl<<"comparing s1 and s3: ";
//	cout<<s1.compare(s3);
//
//	s3.SetGPA(3);
//
//	cout<<endl<<endl;
//
//	s1.print();
//
//	cout<<endl<<endl;
//
//	s3.print();
//
//	system("PAUSE");
//}
/*
*Specify when and why copy constructor was invoked?
1. in the line student s3=s1;

2. in the line cout<<s1.compare(s3).
as s3 is passed by value, a new copy of s3 is created in the scope of compare

*Specify when and why the destructor was invoked?

2. as s3 was passed by value in cout<<s1.compare(s3)
when the scope ended outside of the method, the destructor was called
 2. outside the scope of main, s1, s2, s3 were destroyed

*/
