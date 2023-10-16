#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Library.h"

Patron user;

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
  std::cout << "4. Generate Report\n";
  std::cout << "5. Update own information\n";
  std::cout << "6. Exit\n";
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
    std::cout << "Book found: " << book->get_name() << "\n";
  } else {
    std::cout << "Book not found.\n";
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

void adminMainMenu(Library library, Patron user) {
  int choice;

  while (true) {
    displayAdminMainMenu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        break;
      case 2:
        handleRemoveBook(library);
        break;
      case 3:
        handleUpdateBook(library);
        break;
      case 4:
        handleSearchBook(library);
        break;
      case 5:
        handleGenerateReport(library);
        break;
      case 6:
        handleAddPatron(library);
        break;
      case 7:
        handleDeletePatron(library);
        break;
      case 8:
        handleEditPatron(library);
        break;
      case 9:
        std::cout << "Exiting...\n";
        return;
      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

void patronMainMenu(Library library, Patron user) {
  int choice;
  while (true) {
    displayPatronMainMenu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        // handleSearchBook(library, patron);
        std::cout << "Search Book\n";
        break;
      case 2:
        // handleCheckOutBook(library, patron);
        std::cout << "Check Out Book\n";
        break;
      case 3:
        // handleReturnBook(library, patron);
        std::cout << "Return Book\n";
        break;
      case 4:
        // handleGenerateReport(library, patron);
        std::cout << "Generate Report\n";
        break;
      case 5:
        // handleEditSelfInformation(library, patron);
        std::cout << "Update own information\n";
        break;
      case 6:
        std::cout << "Exiting...\n";
        return;
      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

int main() {
  Library library;
  std::vector<Patron> patrons = *library.get_patrons();
  std::vector<Book> books = *library.get_books();
  std::vector<Genre> genres = *library.get_genres();
  std::vector<Author> authors = *library.get_authors();
  std::string login;
  std::string password;
  while (true) {
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;
    user = (*library.userLogin(login, password));
    if (user.get_id() != -1) {
      break;
    }
    std::cout << "Wrong login or password" << std::endl;
  }
  if (user.getIsAdmin()) {
    adminMainMenu(library, user);
  } else {
    patronMainMenu(library, user);
  }
  return 0;
}
