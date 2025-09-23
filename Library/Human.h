#pragma once
#include <iostream>
using namespace std;
class Human
{
	char* name;
	
public:
	int id;
	int borrowedBooks = 3;
	int booksCount = 0;
	Human(const char* s, int i, int b, int bC);
	~Human();
	int getBooksCount();
	const char* getName();
	int getId();
	int getBorrowedBooks();
	void setBorrowedBooks(int value);
};

