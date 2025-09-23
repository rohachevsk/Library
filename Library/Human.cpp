#include "Human.h"
#include "Library.h"
Human::Human(const char* s, int i, int b, int bC)
{
	name = new char[strlen(s) + 1];
	strcpy_s(name, strlen(s) + 1, s);
	id = i;
	this->borrowedBooks = b;
	this->booksCount = bC;
}

Human::~Human()
{
	delete[] name;
}

int Human::getBooksCount()
{
	return booksCount;
}

const char* Human::getName()
{
	return name;
}

int Human::getId()
{
	return id;
}

int Human::getBorrowedBooks()
{
	return borrowedBooks;
}

void Human::setBorrowedBooks(int value)
{
	borrowedBooks = value;
}

