#include <iostream>
#include <string>

#include "Library.h"
#include "Patron.h"

Library library;

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
  std::string login;
  std::string password;
  while (true) {
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;
    Patron patron(login, password);
    if (patron.ID != "") {
      break;
    }
    std::cout << "Wrong login or password" << std::endl;
  }
  if (patron.isAdmin) {
    adminMainMenu(library, patron);
  } else {
    patronMainMenu(library, patron);
  }
  return 0;
}
