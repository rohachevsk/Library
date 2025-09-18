#include "Human.h"

Human::Human(char* s, int i, char b, int bC)
{
	name = new char[strlen(s) + 1];
	strcpy_s(name, strlen(s) + 1, s);
	id = i;
	borrowedBooks[3] = b;
	booksCount = bC;
}

Human::~Human()
{
	delete[] name;
}

const char* Human::getName()
{
	return name;
}
