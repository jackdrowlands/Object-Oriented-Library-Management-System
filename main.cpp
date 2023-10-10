#include <iostream>
#include <string>

#include "Library.h"

int login(std::sring login, std::string password) {
  // TODO
  int result = 0;
  std::cin >> result;
  return result;
}

void adminMainMenu() {
  // TODO
}

void patronMainMenu() {
  // TODO
}

int main() {
  Library library;
  std::string login;
  std::string password;
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
      adminMainMenu();
      break;
    default:
      patronMainMenu();
      break;
  }
  return 0;
}
