#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_BOOKS = 1000;

struct Book
{
    int ID;
    string Name;
    string Author;
    bool isBorrowed;
};

int readInt(string message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void show_menu(int& choice)
{
    cout << "\n===== Library System =====\n\n";
    cout << "[1] : Add Book\n";
    cout << "[2] : Show Books\n";
    cout << "[3] : Search Book\n";
    cout << "[4] : Borrow Book\n";
    cout << "[5] : Return Book\n";
    cout << "[6] : Exit\n";
    cout << "Choose: ";

    choice = readInt("");
}

void addBook(int& books, Book library[])
{
    int number;

    cout << "\nHow many books do you want to add: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Number of books must be greater than 0.\n";
        return;
    }

    if (books + number > MAX_BOOKS)
    {
        cout << "You cannot add more than " << MAX_BOOKS << " books.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = books; i < books + number; i++)
    {
        cout << "\nEnter Book ID: ";
        cin >> library[i].ID;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Book Name: ";
        getline(cin, library[i].Name);

        cout << "Enter Author Name: ";
        getline(cin, library[i].Author);

        library[i].isBorrowed = false;
    }

    books += number;

    cout << "\nBooks added successfully.\n";
}

void show_books(int books, const Book library[])
{
    cout << "\n===== BOOKS =====\n";

    if (books == 0)
    {
        cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < books; i++)
    {
        cout << "\nBook ID: " << library[i].ID << endl;
        cout << "Book Name: " << library[i].Name << endl;
        cout << "Author: " << library[i].Author << endl;

        if (library[i].isBorrowed)
            cout << "Status: Borrowed\n";
        else
            cout << "Status: Available\n";

        cout << "-----------------\n";
    }
}

void search_books(int books, const Book library[])
{
    if (books == 0)
    {
        cout << "\nNo books available.\n";
        return;
    }

    int search;

    cout << "\n===== Search =====\n";

    while (true)
    {
        search = readInt("Enter Book ID: ");

        for (int i = 0; i < books; i++)
        {
            if (search == library[i].ID)
            {
                cout << "\nBook ID: " << library[i].ID << endl;
                cout << "Book Name: " << library[i].Name << endl;
                cout << "Author: " << library[i].Author << endl;

                if (library[i].isBorrowed)
                    cout << "Status: Borrowed\n";
                else
                    cout << "Status: Available\n";

                cout << "-----------------\n";
                return;
            }
        }

        cout << "Book not found. Try again.\n";
    }
}

void borrowBook(int books, Book library[])
{
    if (books == 0)
    {
        cout << "\nNo books available.\n";
        return;
    }

    int search = readInt("\nEnter Book ID: ");

    for (int i = 0; i < books; i++)
    {
        if (search == library[i].ID)
        {
            if (!library[i].isBorrowed)
            {
                library[i].isBorrowed = true;

                cout << "Book borrowed successfully.\n";
                cout << "Book Name: " << library[i].Name << endl;
            }
            else
            {
                cout << "Book is already borrowed.\n";
            }

            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook(int books, Book library[])
{
    if (books == 0)
    {
        cout << "\nNo books available.\n";
        return;
    }

    int search = readInt("\nEnter Book ID: ");

    for (int i = 0; i < books; i++)
    {
        if (search == library[i].ID)
        {
            if (library[i].isBorrowed)
            {
                library[i].isBorrowed = false;

                cout << "Book returned successfully.\n";
                cout << "Book Name: " << library[i].Name << endl;
            }
            else
            {
                cout << "Book is already available.\n";
            }

            return;
        }
    }

    cout << "Book not found.\n";
}

int main()
{
    Book library[MAX_BOOKS];

    int books = 0;
    int choice;

    do
    {
        show_menu(choice);

        switch (choice)
        {
        case 1:
            addBook(books, library);
            break;

        case 2:
            show_books(books, library);
            break;

        case 3:
            search_books(books, library);
            break;

        case 4:
            borrowBook(books, library);
            break;

        case 5:
            returnBook(books, library);
            break;

        case 6:
            cout << "\nGood Bye!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}
