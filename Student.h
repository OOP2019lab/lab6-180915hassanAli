#pragma once

class student{

private:
	static int counter;
	int ID;

	float *quizScore;
	int quizCapacity;
	int quizTaken;
	float GPA;

public:
	student();

	student(int,int);

	student(const student &);

	~student();


	void addQuizScore(int);

	void SetGPA(float);

	float getGPA() const;

	void print() const;

	bool compare(student);

	void updateScore(int,int);
};