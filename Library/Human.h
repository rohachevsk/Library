#pragma once
#include <iostream>
using namespace std;
class Human
{
	char* name;
	int id;
	char borrowedBooks[3];
	int booksCount;
public:
	Human(char* s, int i,char b,int bC);
	~Human();
	const char* getName();
};

