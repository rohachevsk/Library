#include <iostream>
#include "Library.h"
#include "Human.h"
#include "Book.h"
int main()
{
    Library myLibrary(100, 100);

    myLibrary.addBook();
    myLibrary.addHuman();
    myLibrary.issueBook("The Hobbit", 101);
    myLibrary.print();
}
