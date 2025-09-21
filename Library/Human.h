#pragma once
#include <iostream>
using namespace std;
class Human
{
	char* name;
	int id;
	int borrowedBooks = 3;
public:
	Human(char* s, int i,int b,int bC);
	~Human();
	int getBooksCount();
	const char* getName();
	int getId();
	int booksCount;
};

