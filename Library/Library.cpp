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

void Library::addBook()
{
    char name[50];
    char author[50];
    cout << "Enter book name: " << endl;
    cin.getline(name, 50);
    cout << "Enter author name: " << endl;
	cin.getline(author, 50);
	Book* b = new Book(name, author, true, countOfBooks + 1);
    book[countOfBooks] == b;
    countOfBooks++;
}

void Library::addHuman()
{
	char name[50];
	cout << "Enter human name: " << endl;
	cin.getline(name, 50);
	Human* h = new Human(name, countOfHumans + 1, ' ', 0);
    human[countOfHumans] == h;
	countOfHumans++;
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
            return;
        }
    }
    cout << "Author not found: " << n << endl;
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
void Library::issueBook()
{
    char name[50];
    int id;
    cout << "Enter book name: " << endl;
    cin.getline(name, 50);
    cout << "Enter your id: " << endl;
    cin >> id;
    cin.ignore();
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