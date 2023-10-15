#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Library.h"
#include "Patron.h"

Library library;
Patron user;

Patron* findPatron(std::vector<Patron>* patrons, std::string name) {
  for (std::vector<Patron>::size_type i = 0; i < patrons->size(); i++) {
    if (patrons->at(i).getName() == name) {
      return &patrons->at(i);
    }
  }
  return NULL;
}

Patron* userLogin(std::string user, std::string password,
                  std::vector<Patron>* patrons) {
  Patron* patron = findPatron(patrons, user);

  if (patron->checkLogin(user, password)) {
    std::cout << "User found: " << std::endl;
    return patron;
  }

  return new Patron();
}

Book getBookByID(int id) {
  for (std::vector<Book>::size_type i = 0; i < library.get_books().size();
       i++) {
    if (library.get_books().at(i).getId() == id) {
      return library.get_books().at(i);
    }
  }
  return Book();
}

std::vector<Book> parseBooks(const std::string& booksString) {
  std::vector<Book> books;
  // Assuming booksString is a semicolon-delimited string of book IDs
  std::stringstream ss(booksString);
  std::string bookIDStr;

  while (std::getline(ss, bookIDStr, ';')) {
    int bookID = std::stoi(bookIDStr);
    // Assuming you have a function getBookByID to fetch a Book by its ID
    Book book = getBookByID(bookID);
    books.push_back(book);
  }

  return books;
}

std::vector<BorrowedBook> parseBrowsingHistory(
    const std::string& browsingHistoryString) {
  std::vector<BorrowedBook> browsingHistory;
  // Assuming browsingHistoryString is a semicolon-delimited string of
  // BorrowedBook
  std::stringstream ss(browsingHistoryString);
  std::string borrowedBookStr;

  while (std::getline(ss, borrowedBookStr, ';')) {
    // make a new BorrowedBook object
    BorrowedBook borrowedBook;
    // Assuming borrowedBookStr is a comma-delimited string of
    // bookID,dateHired,dateDue,dateReturned,isReturned
    std::stringstream ssBorrowedBook(borrowedBookStr);
    std::string bookIDStr, dateHiredStr, dateDueStr, dateReturnedStr,
        isReturnedStr;
    std::getline(ssBorrowedBook, bookIDStr, ',');
    std::getline(ssBorrowedBook, dateHiredStr, ',');
    std::getline(ssBorrowedBook, dateDueStr, ',');
    std::getline(ssBorrowedBook, dateReturnedStr, ',');
    std::getline(ssBorrowedBook, isReturnedStr, ',');
    // Type conversion
    int bookID = std::stoi(bookIDStr);
    int dateHired = std::stoi(dateHiredStr);
    int dateDue = std::stoi(dateDueStr);
    int dateReturned = std::stoi(dateReturnedStr);
    bool isReturned = (isReturnedStr == "1");
    // Set the fields of the BorrowedBook object
    borrowedBook.bookID = bookID;
    borrowedBook.dateHired = dateHired;
    borrowedBook.dateDue = dateDue;
    borrowedBook.dateReturned = dateReturned;
    borrowedBook.isReturned = isReturned;
    // Append to browsingHistory vector
    browsingHistory.push_back(borrowedBook);
  }

  return browsingHistory;
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
  std::cout << "4. Generate Report\n";
  std::cout << "5. Update own information\n";
  std::cout << "6. Exit\n";
}

void adminMainMenu(Library library, Patron patron) {
  int choice;
  while (true) {
    displayAdminMainMenu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        // handleAddBook(library, patron);
        std::cout << "Add Book\n";
        break;
      case 2:
        // handleRemoveBook(library, patron);
        std::cout << "Remove Book\n";
        break;
      case 3:
        // handleUpdateBook(library, patron);
        std::cout << "Update Book\n";
        break;
      case 4:
        // handleSearchBook(library, patron);
        std::cout << "Search Book\n";
        break;
      case 5:
        // handleGenerateReport(library, patron);
        std::cout << "Generate Report\n";
        break;
      case 6:
        // handleAddPatron(library, patron);
        std::cout << "Add Patron\n";
        break;
      case 7:
        // handleDeletePatron(library, patron);
        std::cout << "Delete Patron\n";
        break;
      case 8:
        // handleEditPatron(library, patron);
        std::cout << "Edit Patron\n";
        break;
      case 9:
        std::cout << "Exiting...\n";
        return;
      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

void patronMainMenu(Library library, Patron patron) {
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
  std::vector<Patron> patrons;
  std::vector<Book> books;
  std::vector<Genre> genres;
  std::vector<Author> authors;

  std::ifstream userFile("users.csv");
  if (!userFile.is_open()) {
    std::cout << "Generating users.csv...\n";
    std::ofstream userFileOut("users.csv");
    userFileOut << "0,admin,admin,admin,99,1,\0\n";
    userFileOut.close();
    userFile.open("users.csv");  // Re-open the file for reading
  } else {
    std::cout << "users.csv found.\n";
    // read from file
  }
  std::string line;
  while (std::getline(userFile, line)) {
    std::stringstream ss(line);
    std::string idString, login, password, name, ageString, isAdminString,
        browsingHistoryString;
    std::getline(ss, idString, ',');
    std::getline(ss, login, ',');
    std::getline(ss, password, ',');
    std::getline(ss, name, ',');
    std::getline(ss, ageString, ',');
    std::getline(ss, isAdminString, ',');
    std::getline(ss, browsingHistoryString, ',');
    // Type conversion
    int id = std::stoi(idString);
    int age = std::stoi(ageString);
    bool isAdmin = (isAdminString == "1");
    // browsingHistory is a vector of BorrowedBook
    std::vector<BorrowedBook> browsingHistory;
    // convert browsingHistory from string to vector
    browsingHistory = parseBrowsingHistory(browsingHistoryString);
    // Create Patron object
    Patron patron(id, login, password, name, age, isAdmin, browsingHistory);
    // Append to patrons vector
    patrons.push_back(patron);
  }

  std::ifstream bookFile("book.csv");
  // book has title, author, genre, ID, and availability
  if (!bookFile.is_open()) {
    std::cout << "Generating book.csv...\n";
    std::ofstream bookFile("book.csv");
    bookFile << "The Lord of the Rings,J.R.R. Tolkien,1,1,\n";
    bookFile.close();
    bookFile.open("book.csv");  // Re-open the file for reading
  } else {
    std::cout << "book.csv found.\n";
    // read from file
  }
  while (std::getline(bookFile, line)) {
    std::stringstream ss(line);
    std::string title, author, genre, idString, isAvailableString;
    std::getline(ss, title, ',');
    std::getline(ss, author, ',');
    std::getline(ss, genre, ',');
    std::getline(ss, idString, ',');
    std::getline(ss, isAvailableString, ',');
    // Type conversion
    int id = std::stoi(idString);
    bool isAvailable = (isAvailableString == "1");
    // Create Book object
    Book book(title, author, genre, id, isAvailable);
    // Append to books vector
    books.push_back(book);
  }

  std::ifstream genreFile("genre.csv");
  // genre has ID, name, vector of books, restricted, and fictional
  if (!genreFile.is_open()) {
    std::cout << "Generating genre.csv...\n";
    std::ofstream genreFile("genre.csv");
    genreFile << "1,Fantasy,1,0,\n";
    genreFile.close();
    genreFile.open("genre.csv");  // Re-open the file for reading
  } else {
    std::cout << "genre.csv found.\n";
    // read from file
  }
  while (std::getline(genreFile, line)) {
    std::stringstream ss(line);
    std::string idString, name, booksString, isRestrictedString,
        isFictionalString;
    std::getline(ss, idString, ',');
    std::getline(ss, name, ',');
    std::getline(ss, booksString, ',');
    std::getline(ss, isRestrictedString, ',');
    std::getline(ss, isFictionalString, ',');
    // Type conversion
    int id = std::stoi(idString);
    bool isRestricted = (isRestrictedString == "1");
    bool isFictional = (isFictionalString == "1");
    // books is a vector of Book
    std::vector<Book> books;
    // convert books from string to vector
    books = parseBooks(booksString);
    // Create Genre object
    Genre genre(id, name, books, isRestricted, isFictional);
    // Append to genres vector
    genres.push_back(genre);
  }

  std::ifstream authorFile("author.csv");
  // author has id, name, vector of books, nationality, and vector of aliases
  if (!authorFile.is_open()) {
    std::cout << "Generating author.csv...\n";
    std::ofstream authorFile("author.csv");
    authorFile << "1,J.R.R. Tolkien,1,English,\n";
    authorFile.close();
    authorFile.open("author.csv");  // Re-open the file for reading
  } else {
    std::cout << "author.csv found.\n";
    // read from file
  }
  std::getline(authorFile, line);
  while (std::getline(authorFile, line)) {
    std::ifstream authorFile("author.csv");
    if (!authorFile.is_open()) {
      std::cout << "Generating author.csv...\n";
      std::ofstream authorFile("author.csv");
      authorFile << "1,J.R.R. Tolkien,1,English,\n";
      authorFile.close();
      authorFile.open("author.csv");
    } else {
      std::cout << "author.csv found.\n";
    }
    std::string line;
    std::getline(authorFile, line);
    while (std::getline(authorFile, line)) {
      std::stringstream ss(line);
      std::string idString, name, booksString, nationality, aliasesString;
      std::getline(ss, idString, ',');
      std::getline(ss, name, ',');
      std::getline(ss, booksString, ',');
      std::getline(ss, nationality, ',');
      std::getline(ss, aliasesString, ',');

      int id = std::stoi(idString);
      std::vector<Book> books = parseBooks(booksString);
      // Assuming aliases are semicolon-separated
      std::vector<std::string> aliases;
      std::stringstream ssAliases(aliasesString);
      std::string alias;
      while (std::getline(ssAliases, alias, ';')) {
        aliases.push_back(alias);
      }

      Author author(id, name, nationality, aliases, books);
      authors.push_back(author);
    }
  }
  library = Library(books, genres, authors);
  std::string login;
  std::string password;
  while (true) {
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << "debug";
    user = *userLogin(login, password, &patrons);
    if (user.getId() != -1) {
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
