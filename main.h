#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Library.h"
#include "Patron.h"



Patron user;

void handleAddAuthor(Library& library) {
  int id = library.get_authors()->size() + 1;
  std::cout << "Enter author name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Enter author nationality: ";
  std::string nationality;
  std::cin >> nationality;
  std::cout << "Enter author aliases (Place a comma between each): ";
  std::string aliases;
  std::cin >> aliases;
  std::vector<std::string> aliasesVector;
  std::stringstream ss(aliases);
  std::string alias;
  while (getline(ss, alias, ',')) {
    aliasesVector.push_back(alias);
  }
  Author author(id, name, nationality, aliasesVector);
  library.add_author(author);
}
void handleAddAuthor(Library& library, std::string name) {
  int id = library.get_authors()->size() + 1;
  std::cout << "Enter author nationality: ";
  std::string nationality;
  std::cin >> nationality;
  std::cout << "Enter author aliases (Place a comma between each): ";
  std::string aliases;
  std::cin >> aliases;
  std::vector<std::string> aliasesVector;
  std::stringstream ss(aliases);
  std::string alias;
  while (getline(ss, alias, ',')) {
    aliasesVector.push_back(alias);
  }
  Author author(id, name, nationality, aliasesVector);
  library.add_author(author);
}

void handleAddGenre(Library& library) {
  int id = library.get_genres()->size() + 1;
  std::cout << "Enter genre name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Is the genre fictional? (Y/N)";
  std::string fictionalString;
  std::cin >> fictionalString;
  bool isFictional = (fictionalString == "Y");
  std::cout << "Is the genre restricted? (Y/N)";
  std::string restrictedString;
  std::cin >> restrictedString;
  bool isRestricted = (restrictedString == "Y");
  Genre genre(id, name, isRestricted, isFictional);
  library.add_genre(genre);
}

void handleAddGenre(Library& library, std::string name) {
  int id = library.get_genres()->size() + 1;
  std::cout << "Is the genre fictional? (Y/N)";
  std::string fictionalString;
  std::cin >> fictionalString;
  bool isFictional = (fictionalString == "Y");
  std::cout << "Is the genre restricted? (Y/N)";
  std::string restrictedString;
  std::cin >> restrictedString;
  bool isRestricted = (restrictedString == "Y");
  Genre genre(id, name, isRestricted, isFictional);
  library.add_genre(genre);
}

void handleDeleteAuthor(Library& library) {
  std::cout << "Enter author name: ";
  std::string name;
  std::cin >> name;
  library.remove_author(name);
}

void displayAdminMainMenu() {
  std::cout << "Library Management System\n";
  std::cout << "1. Add Book\n";
  std::cout << "2. Remove Book\n";
  std::cout << "3. Update Book\n";
  std::cout << "4. Search Book\n";
  std::cout << "5. Generate Report\n";
  std::cout << "6. Add Patron\n";
  std::cout << "7. Remove Patron\n";
  std::cout << "8. Update Patron\n";
  std::cout << "9. Exit\n";
}

void displayPatronMainMenu() {
  std::cout << "Library Management System\n";
  std::cout << "1. Search Book\n";
  std::cout << "2. Check Out Book\n";
  std::cout << "3. Return Book\n";
  std::cout << "4. Search Author\n";
  std::cout << "5. Search Genre\n";
  std::cout << "6. Generate Report\n";
  std::cout << "7. Update own information\n";
  std::cout << "8. Exit\n";
}

// code for addbook, removebook, etc
void handleAddBook(Library& library) {
  Book book;
  std::string title, author, genre;
  bool isRestricted, isFictional;

  std::cout << "Enter the title of the book: ";
  std::cin >> title;
  book.set_name(title);

  std::cout << "Enter the author of the book: ";
  std::cin >> author;
  bool authorExists = false;

  std::vector<Author>* authors = library.get_authors();
  for (size_t i = 0; i < authors->size(); ++i) {
    if (authors->at(i).get_name() == author) {
      authorExists = true;
      break;
    }
  }
  if (!authorExists) {
    handleAddAuthor(library, author);
  }
  book.setAuthor(author);

  std::cout << "Enter the genre of the book: ";
  std::cin >> genre;
  bool genreExists = false;

  std::vector<Genre>* genres = library.get_genres();
  for (size_t i = 0; i < genres->size(); ++i) {
    if (genres->at(i).get_name() == genre) {
      genreExists = true;
      break;
    }
  }
  if (!genreExists) {
    handleAddGenre(library, genre);
  }
  book.setGenre(genre);

  std::cout << "Is the book restricted? (1 for yes, 0 for no): ";
  std::cin >> isRestricted;
  book.setRestricted(isRestricted);

  std::cout << "Is the book fictional? (1 for yes, 0 for no): ";
  std::cin >> isFictional;
  book.setFictional(isFictional);

  library.add_book(book);
  std::cout << "Book added.\n";
}

void handleRemoveBook(Library& library) {
  Book book;
  std::string title;
  std::cout << "Enter the title of the book to remove: ";
  std::cin >> title;
  book.set_name(title);
  library.remove_book(book);
  std::cout << "Book removed.\n";
}

void handleUpdateBook(Library& library) {
  Book book;
  std::string title, newTitle, newAuthor, newGenre;
  bool newIsRestricted, newIsFictional;

  std::cout << "Enter the title of the book to update: ";
  std::cin >> title;
  Book* existingBook = library.search_book(title);
  if (existingBook == nullptr) {
    std::cout << "Book not found.\n";
    return;
  }

  // Collect new information
  std::cout << "Enter the new title of the book: ";
  std::cin >> newTitle;
  book.set_name(newTitle);

  std::cout << "Enter the new author of the book: ";
  std::cin >> newAuthor;
  book.setAuthor(newAuthor);

  std::cout << "Enter the new genre of the book: ";
  std::cin >> newGenre;
  book.setGenre(newGenre);

  std::cout << "Is the book restricted? (1 for yes, 0 for no): ";
  std::cin >> newIsRestricted;
  book.setRestricted(newIsRestricted);

  std::cout << "Is the book fictional? (1 for yes, 0 for no): ";
  std::cin >> newIsFictional;
  book.setFictional(newIsFictional);
}

void handleSearchBook(Library& library) {
  std::string title;
  std::cout << "Enter the title of the book to search: ";
  std::cin >> title;
  Book* book = library.search_book(title);
  if (book != nullptr) {
    book->displayDetails();
  } else {
    std::cout << "Book not found.\n";
  }
}

void handleSearchGenre(Library& library) {
  std::string name;
  std::cout << "Enter the name of the genre to search: ";
  std::cin >> name;
  Genre* genre = library.search_genre(name);
  if (genre != nullptr) {
    genre->displayDetails();
  } else {
    std::cout << "Genre not found.\n";
  }
}

void handleSearchAuthor(Library& library) {
  std::string name;
  std::cout << "Enter the name of the author to search: ";
  std::cin >> name;
  Author* author = library.search_author(name);
  if (author != nullptr) {
    author->displayDetails();
  } else {
    std::cout << "Author not found.\n";
  }
}

void handleGenerateReport(Library& library) { library.generate_report(); }

void handleAddPatron(Library& library) {
  std::cout << "Enter patron name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Enter patron details: ";
  std::string details;
  std::cin >> details;
  std::cout << "Enter patron password: ";
  std::string password;
  std::cin >> password;
  std::cout << "Enter patron age: ";
  int age;
  std::cin >> age;
  std::cout << "Are you an admin? (Y/N):  ";
  std::string adminString;
  std::cin >> adminString;
  bool isAdmin = (adminString == "Y");
  Patron newPatron(library.get_patrons()->size() + 1, name, details, password,
                   age, isAdmin, {});
  library.addPatron(library, newPatron);
}

void handleDeletePatron(Library& library) {
  std::string patronIdentifier;
  std::cout << "Enter the name or login of the patron to remove: ";
  std::cin >> patronIdentifier;

  // Locate patron to remove
  Patron* patronToRemove = library.findPatron(patronIdentifier);

  if (patronToRemove != nullptr) {
    library.deletePatron(library, *patronToRemove);
    std::cout << "Patron has been removed.\n";
  } else {
    std::cout << "Patron not found. No patron has been removed.\n";
  }
}

void handleEditPatron(Library& library) {
  std::cout << "Enter the new name: ";
  std::string newName;
  std::cin >> newName;
  library.updatePatronName(&user, newName);
  std::cout << "Name updated successfully.\n";
}



// Handles the book checkout process.
void handleCheckOutBook(Library& library, Patron& user) {
  std::string title;
  std::cout << "Enter the title of the book to check out: ";
  std::cin >> title;
  if (library.check_out_book(title, user)) {
    std::cout << "Successfully checked out the book.\n";
  } else {
    std::cout << "Failed to check out the book.\n";
  }
}

// Handles the book return process.
void handleReturnBook(Library& library, Patron& user) {
  std::string title;
  std::cout << "Enter the title of the book to return: ";
  std::cin >> title;
  if (library.return_book(title, user)) {
    std::cout << "Successfully returned the book.\n";
  } else {
    std::cout << "Failed to return the book.\n";
  }
}

// Allows the user to update their own information.
void handleUpdateSelfInformation(Library& library, Patron& user) {
  std::string new_name;
  int new_age;

  // Update name
  std::cout << "Enter your new name: ";
  std::cin >> new_name;
  user.set_name(new_name);

  // Update age
  std::cout << "Enter your new age: ";
  std::cin >> new_age;
  user.set_age(new_age);  // Assuming set_age is a method in your Patron
  // class

  // Update the user information in the library database
  library.update_patron(user);

  std::cout << "Information updated.\n";
}






class UnitTest1 {
public:
    void testHandleAddBook() {
        Library library;
        std::string testTitle = "Test Book";
        std::string testAuthor = "Test Author";
        std::string testGenre = "Test Genre";
        bool testIsRestricted = false;
        bool testIsFictional = true;

        std::stringstream input; // gives string interface instead of cin
        input << testTitle << "\n" << testAuthor << "\n" << testGenre << "\n" << "0" << "\n" << "1" << "\n";
        std::cin.rdbuf(input.rdbuf());
       
        std::vector<Book>* books = library.get_books();
        if (!books->empty()) {
            Book& addedBook = books->back();
            if (addedBook.get_name() == testTitle &&
                addedBook.getAuthor() == testAuthor &&
                addedBook.getGenre() == testGenre &&
                addedBook.isRestricted() == testIsRestricted &&
                addedBook.isFictional() == testIsFictional) {
                std::cout << "handleAddBook function PASSED" << std::endl;
            } else {
                std::cout << "handleAddBook function FAILED" << std::endl;
            }
        } else {
            std::cout << "handleAddBook FAILED" << std::endl;
        }
    }
};



#endif // MAIN_H