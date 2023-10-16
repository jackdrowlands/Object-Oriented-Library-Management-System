#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Library.h"

Patron userPatron;

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
    userPatron = (*library.userLogin(login, password));
    if (userPatron.get_id() != -1) {
      break;
    }
    std::cout << "Wrong login or password" << std::endl;
  }
  if (userPatron.getIsAdmin()) {
    adminMainMenu(library, userPatron);
  } else {
    patronMainMenu(library, userPatron);
  }
  return 0;
}