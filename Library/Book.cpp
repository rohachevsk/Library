#include "Book.h"

Book::Book(const char* n, const char* a, bool is, int i)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1,n);
	author = new char[strlen(a) + 1];
	strcpy_s(author, strlen(a) + 1, a);
	isIn = is;
	id = i;
}
Book::~Book()
{
	delete[] name;
	delete[] author;
}

const char* Book::getName()
{
	return name;
}

const char* Book::getAuthor()
{
	return author;
}

void Book::setID(int i)
{
	id = i;
}
