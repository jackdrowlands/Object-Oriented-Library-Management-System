#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Library.h"
#include "Patron.h"

Library library;
Patron user;

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
        handleAddBook(library, patron);
        break;
      case 2:
        handleRemoveBook(library, patron);
        break;
      case 3:
        handleUpdateBook(library, patron);
        break;
      case 4:
        handleSearchBook(library, patron);
        break;
      case 5:
        handleGenerateReport(library, patron);
        break;
      case 6:
        handleAddPatron(library, patron);
        break;
      case 7:
        handleDeletePatron(library, patron);
        break;
      case 8:
        handleEditPatron(library, patron);
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
        handleSearchBook(library, patron);
        break;
      case 2:
        handleCheckOutBook(library, patron);
        break;
      case 3:
        handleReturnBook(library, patron);
        break;
      case 4:
        handleGenerateReport(library, patron);
        break;
      case 5:
        handleEditSelfInformation(library, patron);
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

  std::ifstream userFile("user.csv");
  if (!userFile.is_open()) {
    std::cout << "Generating users.csv...\n";
    std::ofstream userFile("users.csv");
    userFile << "0,admin,admin,admin,99,1,\0\n";
    userFile.close();
    userFile.open("users.csv");  // Re-open the file for reading
  } else {
    std::cout << "users.csv found.\n";
    // read from file
  }
  std::string line;
  std::getline(userFile, line);
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
  std::getline(bookFile, line);
  while (std::getline(bookFile, line)) {
    std::stringstream ss(line);
    std::string title, author, genreString, idString, isAvailableString;
    std::getline(ss, title, ',');
    std::getline(ss, author, ',');
    std::getline(ss, genreString, ',');
    std::getline(ss, idString, ',');
    std::getline(ss, isAvailableString, ',');
    // Type conversion
    int genreID = std::stoi(genreString);
    int id = std::stoi(idString);
    bool isAvailable = (isAvailableString == "1");
    // Create Book object
    Book book(title, author, genreID, id, isAvailable);
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
  std::getline(genreFile, line);
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

      Author author(id, name, books, nationality, aliases);
      authors.push_back(author);
    }
  }
  std::string login;
  std::string password;
  while (true) {
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;
    user = login(login, password);
    if (user.get_id != 0) {
      break;
    }
    std::cout << "Wrong login or password" << std::endl;
  }
  if (user.isAdmin) {
    adminMainMenu(library, user);
  } else {
    patronMainMenu(library, user);
  }
  return 0;
}
