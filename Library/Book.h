#pragma once
#include <iostream>
using namespace std;
class Book
{
	char* name;
	char* author;

public:
	Book(const char* n, const char* a);
	~Book();
	const char* getName();
	const char* getAuthor();
	bool isIn;
	int id;
};

