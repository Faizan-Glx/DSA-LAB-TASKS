#include<iostream>
using namespace std;

template<typename T>
int linearSearch(T arr[], int size, T key) {

	for (int i = 0; i <size; i++) {
		if (arr[i] == key)
			return i;
	}

	return 0;
}

template<typename T>
void bubblesort(T arr[], int size) {
	for (int i = 0;i < size-1;i++) {
		for (int j = 0;j < size - i - 1;j++) {
			if (arr[j + 1] < arr[j]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

class item {
public:
	virtual void display() = 0;
};

class Book:public item {
	string name;
	string author;
	int pages;

public:
	Book() {};
	Book(string n, string a, int y) :name(n), author(a), pages(y) {};

	void display() {
		cout << "Book: " << name<< "  Author: " << author<< "  Pages: " << pages << endl;
	}

	bool operator==(Book b) {
		return name == b.name;
	}

	bool operator<(Book b) {
		return pages < b.pages;
	}
};

class Newspaper : public item{
	string name;
	string date;
	string edition;

public:
	Newspaper() {};
	Newspaper(string n, string d, string e) :name(n), date(d), edition(e) {};

	void display() {
		cout << "Newspaper: " << name<< "  Date: " << date<< "  Edition: " << edition << endl;
	}
	bool operator==(Newspaper n) {
		return name == n.name;
	}

	bool operator<(Newspaper n) {
		return edition < n.edition;
	}
};

class Library {
	Book books[20];
	Newspaper newspapers[20];
	int bcount = 0;
	int ncount = 0;

public:

	void addBook(Book b) {
		books[bcount] = b;
		bcount++;
	}

	void addNewspaper(Newspaper n) {
		newspapers[ncount] = n;
		ncount++;
	}

	void displayCollection() {
		cout << "===Books===" << endl;
		for (int i = 0;i < bcount;i++) {
			books[i].display();
		}

		cout << endl;
		cout << "===Newspapers===" << endl;
		for (int i = 0;i < ncount;i++) {
			newspapers[i].display();
		}

	}

	void sortBooksByPages() {
		bubblesort(books, bcount);
	}
	
	void sortNewspapersByEdition() {
		bubblesort(newspapers, ncount);
	}

	Book* searchBookByTitle(string title) {

		Book b(title, "", 0);

		int index = linearSearch(books, bcount, b);

		if (index != -1)
			return &books[index];

		return nullptr;
	}

	Newspaper* searchNewspaperByName(string name) {

		Newspaper n(name, "", "");

		int index = linearSearch(newspapers, ncount, n);

		if (index != -1)
			return &newspapers[index];

		return nullptr;
	}

};



	int main() {
	// Create book objects
	
	Book book1("To Kill a Mockingbird", "Harper Lee", 324);
	Book book2("The Catcher in the Rye", "J.D. Salinger", 277);
	// Create newspaper objects
	
	Newspaper newspaper1("The Times", "2024-10-12", "Weekend Edition");
	Newspaper newspaper2("Washington Post", "2024-10-13", "Morning Edition");
	// Create a library object
	Library library;
	/* Add books and newspapers to the library*/
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);
	// Display the entire collection
	cout << "Before Sorting:\n";
	library.displayCollection();
//	// Sort books by pages and newspapers by edition
	library.sortBooksByPages();
	library.sortNewspapersByEdition();
	cout << "\nAfter Sorting:\n";
	library.displayCollection();
//	// Search for a book by title
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}
//	// Search for a newspaper by name
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}
	return 0;
}