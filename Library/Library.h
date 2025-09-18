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

	
};

