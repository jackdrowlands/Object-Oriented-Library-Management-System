#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Library.h"

Patron user;

void handleAddAuthor(Library library) {
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

void handleDeleteAuthor(Library library) {
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
  std::cout << "9. Add Author\n";
  std::cout << "10. Remove Author\n";
  std::cout << "11. Update Author\n";
  std::cout << "12. Add Genre\n";
  std::cout << "13. Remove Genre\n";
  std::cout << "14. Update Genre\n";
  std::cout << "15. Exit\n";
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

void adminMainMenu(Library library, Patron user) {
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
        handleAddAuthor(library);
        break;
      case 10:
        handleDeleteAuthor(library);
        break;
      case 11:
        // handleEditAuthor(library, patron);
        std::cout << "Edit Author\n";
        break;
      case 12:
        // handleAddGenre(library, patron);
        std::cout << "Add Genre\n";
        break;
      case 13:
        // handleDeleteGenre(library, patron);
        std::cout << "Delete Genre\n";
        break;
      case 14:
        // handleEditGenre(library, patron);
        std::cout << "Edit Genre\n";
        break;
      case 15:
        std::cout << "Exiting...\n";
        return;
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
  // call ~Library() to save changes to the files
  library.~Library();
  return 0;
}