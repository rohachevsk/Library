#include <iostream>
#include "Library.h"
#include "Human.h"
#include "Book.h"
int main()
{
    Library myLibrary(100, 100);

    myLibrary.addBook("1984", "George Orwell");
    myLibrary.addBook("The Hobbit", "J.R.R. Tolkien");
    myLibrary.addHuman("John Doe", 101);
    myLibrary.addHuman("Jane Smith", 102);
    myLibrary.print();
}
