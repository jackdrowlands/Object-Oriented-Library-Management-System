#include <iostream>
#include <string>

#include "Library.h"

int login(std::sring login, std::string password) {
  // TODO
  int result = 0;
  std::cin >> result;
  return result;
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

void adminMainMenu(Library library) {
  while (true) {
    displayAdminMainMenu();
    std::cin >> choice;

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

void patronMainMenu(Library library) {
  // TODO
}

int main() {
  Library library;
  std::string login;
  std::string password;
  int choice;
  while (true) {
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;
    if (login(login, password) != -1) {
      break;
    }
    std::cout << "Wrong login or password" << std::endl;
  }
  switch (login(login, password)) {
    case 0:
      adminMainMenu(library);
      break;
    default:
      patronMainMenu(library);
      break;
  }
  return 0;
}
