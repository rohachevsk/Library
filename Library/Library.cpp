#include "Library.h"
#include "Book.h"
#include "Human.h"
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

void Library::addBook(const char* name, const char* author)
{
    if (countOfBooks < 100)
    {
        book[countOfBooks] = new Book(name, author, true, countOfBooks + 1);
        countOfBooks++;
    }
}

void Library::addHuman(const char* name, int id)
{
    if (countOfHumans < 10)
    {
        human[countOfHumans] = new Human(name, id, ' ', 0);
        countOfHumans++;
    }
}

int Library::getBooksCount()
{
    return countOfBooks;
}

int Library::getHumansCount()
{
    return countOfHumans;
}

Book* Library::searchBookByName(const char* n)
{
	cout << "Searching for book: " << n << endl;
    for(int i = 0; i < countOfBooks; i++)
    {
        if (strcmp(book[i]->getName(), n) == 0)
        {
            cout << "Book found: " << book[i]->getName() << " by " << book[i]->getAuthor() << endl;
            return book[i];
        }
	}
    cout << "Book not found: " << n << endl;
    return nullptr;
}

int Library::searchBookByAuthor(const char* n)
{
	cout << "Searching for author: " << n << endl;
    for (int i = 0; i < countOfBooks; i++)
    {
        if (strcmp(book[i]->getAuthor(), n) == 0)
        {
			cout << "Author found: " << book[i]->getAuthor() << "(Book :" << book[i]->getName() << ")" << endl;
            return i;
        }
    }
    cout << "Author not found: " << n << endl;
    return -1;
}
Human* Library::SearchHumanById(int id)
{
    for (int i = 0; i < countOfHumans; i++)
    {
        if (human[i]->getId() == id)
        {
            cout << "Human found: " << human[i]->getName() << endl;
            return human[i];
        }
    }
    cout << "Human with id " << id << " not found" << endl;
    return nullptr;
}
void Library::issueBook(const char* name, int id)
{
    Book* foundBook = searchBookByName(name);
    Human* foundHuman = SearchHumanById(id);
    if (foundBook != nullptr)
    {
        if (foundBook->isIn == true)
        {
            if (foundHuman->getBooksCount() < 3)
            {
				foundBook->isIn = false;
				foundBook->id = foundHuman->getId();
                foundHuman->booksCount++;
                cout << "Book issued successfully!" << endl;
            }
            else 
            {
                cout << "You have reached the maximum number of borrowed books" << endl;
			}
        }
        else
        {
            cout << "Book is already issued" << endl;
		}
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void Library::returnBook(const char* bookName, int id)
{
    Book* foundBook = searchBookByName(bookName);
    Human* foundHuman = SearchHumanById(id);

    if (foundBook && foundHuman)
    {
        if (!foundBook->isIn && foundBook->getId() == id)
        {
            foundBook->isIn = true;
            foundBook->setID(-1);
            foundHuman->setBorrowedBooks(foundHuman->getBorrowedBooks() - 1);
            cout << "Book returned successfully" << endl;
        }
        else
        {
            cout << "This book was not issued to this patron." << endl;
        }
    }
    else
    {
        cout << "Book or patron not found." << endl;
    }

}

void Library::print()
{
    cout << "Books in library:" << endl;
    for (int i = 0; i < countOfBooks; i++)
    {
        cout << "- " << book[i]->getName() << endl;
    }

    cout << "\nHumans in library:" << endl;
    for (int i = 0; i < countOfHumans; i++)
    {
        cout << "- " << human[i]->getName() << endl;
    }
}
