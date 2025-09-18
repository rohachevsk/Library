#pragma once
#include <iostream>
using namespace std;
class Book
{
	char* name;
	char* autor;
	bool isIn;
	int id;
public:
	Book(const char* n, const char* a, bool i,int id);
	~Book();
	const char* getName();
	const char* getAutor();
	void Isin();

};

