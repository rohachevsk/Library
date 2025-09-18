#include "Library.h"

Library::Library(int cB, int cH)
{
    countOfBooks = cB;
    countOfHumans = cH;
    book = new Book*[countOfBooks];
    human = new Human * [countOfHumans];
}

Library::~Library()
{
    for (int i = 0; i < countOfBooks; ++i)
    {
        delete book[i];
    }
    delete[] book;
    for (int i = 0; i < countOfHumans; ++i)
    {
        delete human[i];
    }
    delete[] human;
}
