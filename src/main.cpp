#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "Library.h"
#include "Patron.h"

// Global variables
Patron user;

bool isValidInt(const std::string& input) {
  std::istringstream iss(input);
  int x;
  char extra;
  if (!(iss >> x) || iss.get(extra)) return false;
  return true;
}

// add author methods
void handleAddAuthor(Library& library, std::string name) {
  int id = library.get_authors()->size() + 1;
  std::cout << "Enter author nationality: ";
  std::string nationality;
  std::getline(std::cin, nationality);
  Author author(id, name, nationality);
  library.add_author(author);
}
void handleAddAuthor(Library& library) {
  std::cout << "Enter author name: ";
  std::string name;
  std::getline(std::cin, name);
  handleAddAuthor(library, name);
}
// add genre methods
void handleAddGenre(Library& library, std::string name) {
  int id = library.get_genres()->size() + 1;
  bool isFictional;
  while (true) {
    std::cout << "Is the genre fictional? (Y/N)";
    char input;
    std::cin >> input;
    std::cin.ignore();
    // Add input validation
    if (input == 'Y' || input == 'y') {
      isFictional = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isFictional = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  bool isRestricted;
  while (true) {
    std::cout << "Is the genre restricted? (Y/N)";
    char input;
    std::cin >> input;
    std::cin.ignore();
    // Add input validation
    if (input == 'Y' || input == 'y') {
      isRestricted = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isRestricted = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  Genre genre(id, name, isRestricted, isFictional);
  library.add_genre(genre);
}

void handleAddGenre(Library& library) {
  std::cout << "Enter genre name: ";
  std::string name;
  std::getline(std::cin, name);
  handleAddGenre(library, name);
}
// delete author methods
void handleDeleteAuthor(Library& library) {
  std::cout << "Enter author name: ";
  std::string name;
  std::getline(std::cin, name);
  library.remove_author(name);
}

// displays admin menu
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

// displays patron menu
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
  std::getline(std::cin, title);
  book.set_name(title);

  std::cout << "Enter the author of the book: ";
  std::getline(std::cin, author);
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
  std::getline(std::cin, genre);
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

  while (true) {
    std::cout << "Is the book fictional? (Y/N)";
    char input;
    std::cin >> input;
    std::cin.ignore();
    // Add input validation
    if (input == 'Y' || input == 'y') {
      isFictional = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isFictional = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  while (true) {
    std::cout << "Is the book restricted? (Y/N)";
    char input;
    std::cin >> input;
    std::cin.ignore();

    // Add input validation
    if (input == 'Y' || input == 'y') {
      isRestricted = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isRestricted = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  book.setRestricted(isRestricted);
  book.setFictional(isFictional);
  book.setAvailable(true);
  library.add_book(book);
  std::cout << "Book added.\n";
}

void handleRemoveBook(Library& library) {
  Book book;
  std::string title;
  std::cout << "Enter the title of the book to remove: ";
  std::getline(std::cin, title);
  if (library.search_book(title) == nullptr) {
    std::cout << "Book not found.\n";
    return;
  }
  book.set_name(title);
  library.remove_book(book);
  std::cout << "Book removed.\n";
}
// updates book
void handleUpdateBook(Library& library) {
  Book book;
  std::string title, newTitle, newAuthor, newGenre;

  std::cout << "Enter the title of the book to update: ";
  std::getline(std::cin, title);
  Book* existingBook = library.search_book(title);
  if (existingBook == nullptr) {
    std::cout << "Book not found.\n";
    return;
  }

  // Collect new information
  std::cout << "Enter the new title of the book: ";
  std::getline(std::cin, newTitle);
  book.set_name(newTitle);

  std::cout << "Enter the new author of the book: ";
  std::getline(std::cin, newAuthor);
  book.setAuthor(newAuthor);

  std::cout << "Enter the new genre of the book: ";
  std::getline(std::cin, newGenre);
  book.setGenre(newGenre);

  bool isFictional;
  while (true) {
    std::cout << "Is the book fictional? (Y/N)";
    char input;
    std::cin >> input;
    std::cin.ignore();

    // Add input validation
    if (input == 'Y' || input == 'y') {
      isFictional = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isFictional = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  bool isRestricted;
  while (true) {
    std::cout << "Is the book restricted? (Y/N)";
    char input;
    std::cin >> input;
    std::cin.ignore();

    // Add input validation
    if (input == 'Y' || input == 'y') {
      isRestricted = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isRestricted = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  book.setRestricted(isRestricted);
  book.setFictional(isFictional);
}
// search book
void handleSearchBook(Library& library) {
  std::string title;
  std::cout << "Enter the title of the book to search: ";
  std::getline(std::cin, title);
  Book* book = library.search_book(title);
  if (book != nullptr) {
    book->displayDetails();
  } else {
    std::cout << "Book not found.\n";
  }
}
// search genre
void handleSearchGenre(Library& library) {
  std::string name;
  std::cout << "Enter the name of the genre to search: ";
  std::getline(std::cin, name);
  Genre* genre = library.search_genre(name);
  if (genre != nullptr) {
    genre->displayDetails();
  } else {
    std::cout << "Genre not found.\n";
  }
}

// search author
void handleSearchAuthor(Library& library) {
  std::string name;
  std::cout << "Enter the name of the author to search: ";
  std::getline(std::cin, name);
  Author* author = library.search_author(name);
  if (author != nullptr) {
    author->displayDetails();
  } else {
    std::cout << "Author not found.\n";
  }
}
// generate report
void handleGenerateReport(Library& library) { library.generate_report(); }
// add patron
void handleAddPatron(Library& library) {
  std::cout << "Enter patron name: ";
  std::string name;
  std::getline(std::cin, name);
  std::cout << "Enter patron details: ";
  std::string details;
  std::getline(std::cin, details);
  std::cout << "Enter patron password: ";
  std::string password;
  std::getline(std::cin, password);
  std::cout << "Enter patron age: ";
  int age;
  while (!(std::cin >> age)) {
    std::cout << "Invalid input. Please enter a number.\n";
    std::cin.clear();  // clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');  // ignore the invalid input
  }
  bool isAdmin;
  while (true) {
    std::cout << "Is the user an Admin? (Y/N)";
    char input;
    std::cin >> input;

    // Add input validation
    if (input == 'Y' || input == 'y') {
      isAdmin = true;
      break;
    } else if (input == 'N' || input == 'n') {
      isAdmin = false;
      break;
    } else {
      std::cout << "Invalid input. Please enter Y or N.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
  }
  std::vector<BorrowedBook> history;
  Patron newPatron(library.get_patrons()->size() + 1, name, details, password,
                   age, isAdmin, history);
  library.addPatron(library, newPatron);
  library.save_borrow();
}
// delete patron methods
void handleDeletePatron(Library& library) {
  std::string patronIdentifier;
  std::cout << "Enter the name or login of the patron to remove: ";
  std::getline(std::cin, patronIdentifier);

  // Locate patron to remove
  Patron* patronToRemove = library.findPatron(patronIdentifier);

  if (patronToRemove != nullptr) {
    library.deletePatron(library, *patronToRemove);
    std::cout << "Patron has been removed.\n";
  } else {
    std::cout << "Patron not found. No patron has been removed.\n";
  }
  library.save_borrow();
}
// edit patron methods
void handleEditPatron(Library& library) {
  std::cout << "Enter the new name: ";
  std::string newName;
  std::getline(std::cin, newName);
  library.updatePatronName(&user, newName);
  std::cout << "Name updated successfully.\n";
  library.save_borrow();
}

// switch case for admin menu
void adminMainMenu(Library& library, Patron& user) {
  std::string input;
  int choice;
  while (true) {
    displayAdminMainMenu();
    while (!(std::cin >> choice)) {
      std::cout << "Invalid input. Please enter a number.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
    std::cin.ignore();
    switch (choice) {
      case 1:
        handleAddBook(library);
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

// Handles the book checkout process.
void handleCheckOutBook(Library& library, Patron& user) {
  std::string title;
  std::cout << "Enter the title of the book to check out: ";
  std::getline(std::cin, title);
  if (library.check_out_book(title, user)) {
    std::cout << "Successfully checked out the book.\n";
  } else {
    std::cout << "Failed to check out the book.\n";
  }
  library.save_borrow();
}

// Handles the book return process.
void handleReturnBook(Library& library, Patron& user) {
  std::string title;
  std::cout << "Enter the title of the book to return: ";
  std::getline(std::cin, title);
  if (library.return_book(title, user)) {
    std::cout << "Successfully returned the book.\n";
  } else {
    std::cout << "Failed to return the book.\n";
  }
  library.save_borrow();
}

// Allows the user to update their own information.
void handleUpdateSelfInformation(Library& library, Patron& user) {
  std::string new_name;
  int new_age;

  // Update name
  std::cout << "Enter your new name: ";
  std::getline(std::cin, new_name);
  user.set_name(new_name);

  // Update age
  std::cout << "Enter your new age: ";
  while (!(std::cin >> new_age)) {
    std::cout << "Invalid input. Please enter a number.\n";
    std::cin.clear();  // clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');  // ignore the invalid input
  }
  std::cin.ignore();

  user.set_age(new_age);  // Assuming set_age is a method in your Patron
  // class

  // Update the user information in the library database
  library.update_patron(user);

  std::cout << "Information updated.\n";
  library.save_borrow();
}

void handleGenerateSelfReport(Patron user) { user.displayDetails(); }

// switch case for patron menu
void patronMainMenu(Library& library, Patron& user) {
  int choice;
  while (true) {
    displayPatronMainMenu();
    while (!(std::cin >> choice)) {
      std::cout << "Invalid input. Please enter a number.\n";
      std::cin.clear();  // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // ignore the invalid input
    }
    std::cin.ignore();
    switch (choice) {
      case 1:
        handleSearchBook(library);
        break;
      case 2:
        handleCheckOutBook(library, user);
        break;
      case 3:
        handleReturnBook(library, user);
        break;
      case 4:
        handleSearchAuthor(library);
        break;
      case 5:
        handleSearchGenre(library);
        break;
      case 6:
        handleGenerateSelfReport(user);
        break;
      case 7:
        handleUpdateSelfInformation(library, user);
        break;
      case 8:
        std::cout << "Exiting...\n";
        return;
      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

// main function
int main() {
  Library library;
  Patron user;

  std::cout << "Welcome to the Library Management System!\n";
  while (true) {
    user = *library.userLoginPrompt();
    if (user.getIsAdmin()) {
      adminMainMenu(library, user);
    } else {
      patronMainMenu(library, user);
    }
    std::cout << "Logging out...\n";
    std::cout << "Thank you for using the Library Management System!\n";
    while (true) {
      std::cout << "Would you like to log in again? (Y/N)";
      char input;
      std::cin >> input;
      std::cin.ignore();
      // Add input validation
      if (input == 'Y' || input == 'y') {
        break;
      } else if (input == 'N' || input == 'n') {
        return 0;
        break;
      } else {
        std::cout << "Invalid input. Please enter Y or N.\n";
        std::cin.clear();  // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');  // ignore the invalid input
      }
    }
  }
  return 0;
}