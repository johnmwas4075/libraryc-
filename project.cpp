#include <iostream>
#include <string>
#include <vector>

using namespace std;

//book storage
class Book {
private:
    string name;
    string title;
    string author;
    bool isBorrowed;
	bool isAvailable;
public:
    Book(string n, string t, string a) : name(n), title(t), author(a),isBorrowed(false){}

    void input() {
        cout << "Input the name, title and author: " << endl;
        cin >> name >> title >> author;
    }

    void display() const {
    
        cout << name << " " << title << " " << author << endl;
    }
    string getName() const { return name; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }
    bool getIsBorrowed() const { return isBorrowed; }
    void setIsBorrowed(bool status) { isBorrowed = status; }
};

//user storage
class User {
private:
    string name;
    string admno;
    string libno;

public:
    User(string n, string t, string a) : name(n), admno(t), libno(a) {} //store the values in a constructor

    void input() {
        cout << "Input the name, admno and libno: " << endl;
        cin >> name >> admno >> libno;
    }

    void display() const {
        cout << name << " " << admno << " " << libno << endl;
    }

	string getname() const {return name;}
	string getadmno() const {return admno;}
	string getlibno() const {return libno;}
};
//activities to be done in the library

class Library {
private:
    vector<Book> books;
    vector<User> users;
    vector<Book> borrowedBooks; // vector for borrowed books
    vector<Book> returnedBooks; // vector for returned books

public:
    void addBook(const Book& book) { //adds a new book
        books.push_back(book);
    }

    void showBooks() const { //displays all the books
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].display();
        }
    }

    void addUser(const User& user) { //adds a new user
        users.push_back(user);
    }

    void showUsers() const { //displays all the users
        for (size_t i = 0; i < users.size(); ++i) {
        	
            users[i].display();
        }
    }
    void searchBook(const string& searchTerm) const {
        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getName() == searchTerm || books[i].getTitle() == searchTerm || books[i].getAuthor() == searchTerm) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No book found with the search term: " << searchTerm << endl;
        }
    }
    void searchUser(const string& searchTerm) const {
        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (users[i].getname() == searchTerm || users[i].getadmno() == searchTerm || users[i].getlibno() == searchTerm) {
                users[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No user found with the search term: " << searchTerm << endl;
        }
    }
    void borrowBook(const string& searchTerm) {
        for (size_t i = 0; i < books.size(); ++i) {
            if ((books[i].getName() == searchTerm || books[i].getTitle() == searchTerm || books[i].getAuthor() == searchTerm) && !books[i].getIsBorrowed()) {
                books[i].setIsBorrowed(true);
                cout << "Book borrowed successfully." << endl;
                return;
            }
        }
        cout << "Book not available for borrowing." << endl;
    }

    void returnBook(const string& searchTerm) {
        for (size_t i = 0; i < books.size(); ++i) {
            if ((books[i].getName() == searchTerm || books[i].getTitle() == searchTerm || books[i].getAuthor() == searchTerm) && books[i].getIsBorrowed()) {
                books[i].setIsBorrowed(false);
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found or already returned." << endl;
    }
 
};
	


int main() {
    string name, title, author,searchTerm;
    int choice;
    Library library;

    while (true) {
         cout << "Input the choice you want"<<endl;
         cout<<"1: add a book"<<endl;
		 cout<<"2: show all books"<<endl;
		 cout<<"3: add a user"<<endl;
		 cout<<"4: show users"<<endl;
         cout<<"5: search book by name, title or author"<<endl;
		 cout<<"6: search person by name, admno or lib no"<<endl;
		 cout<<"7: borrow a book"<<endl;
		 cout<<"8: return a book"<<endl;
		 cout<<"0: exit"<<endl;
         cin >> choice;

        if (choice == 1) {
            cout << "Input the name, title and author: " << endl;
            cin >> name >> title >> author;
            Book newBook(name, title, author);
            library.addBook(newBook);
		}else if(choice==3){
			cout << "Input the name, title and author: " << endl;
            cin >> name >> title >> author;
            User addUser(name, title, author);
            library.addUser(addUser);
        } else if (choice == 2) {
            library.showBooks();
		} else if (choice == 4) {
            library.showUsers();
       } else if (choice == 5) {
            cout << "Enter the name, title or author to search: ";
            cin >> searchTerm;
            library.searchBook(searchTerm); 
       } else if (choice == 6) {
            cout << "Enter the name, title or author to search: ";
            cin >> searchTerm;
            library.searchUser(searchTerm);     
	   }else if (choice == 7) {
            cout << "Enter the name, title or author of the book to borrow: ";
            cin >> searchTerm;
            library.borrowBook(searchTerm);
        } else if (choice == 8) {
            cout << "Enter the name, title or author of the book to return: ";
            cin >> searchTerm;
            library.returnBook(searchTerm); 			
		}else if (choice == 0) {
            break;
		}else {
		  cout << "Invalid choice. Please enter 1, 2, 3, 4, or 0." << endl;
        }
    }

    return 0;
}