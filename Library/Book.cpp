#include "Book.h"

Book::Book(const char* n, const char* a, bool i,int id)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	autor = new char[strlen(a) + 1];
	strcpy_s(autor, strlen(a) + 1, a);
	isIn = i;
	id = i;
}

Book::~Book()
{
	delete[] name;
	delete[] autor;
}

const char* Book::getName()
{
	return name;
}

const char* Book::getAutor()
{
	return autor;
}
