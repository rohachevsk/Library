#pragma once
#include <iostream>
#include "Book.h"
#include "Human.h"
using namespace std;
class Library
{
	Book** book;
	Human** human;
	int countOfBooks;
	int countOfHumans;
public:
	Library(int cB, int cH);
	~Library();
	void addBook(const char* name, const char* author);
	void addHuman(const char* name, int id);
	int getBooksCount();
	int getHumansCount();
	Book* searchBookByName(const char* n);		
	int searchBookByAuthor(const char* n);
	Human* SearchHumanById(int id);
	void issueBook(const char* name, int id);
	void returnBook(const char* bookName, int id);
	void print();
	
	
};

