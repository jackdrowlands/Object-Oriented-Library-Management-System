
#include "Patron.h"

// Add method implementations here, if any

Patron::Patron(int id, std::string name, std::string details,
               std::string password, int age, bool isAdmin,
               std::vector<BorrowedBook> history)
    : Entity(id, name) {
  this->details = details;
  this->password = password;
  this->age = age;
  this->isAdmin = isAdmin;
  this->history = history;
}

Patron::Patron() : Entity() {
  this->details = "";
  this->password = "";
  this->age = 0;
  this->isAdmin = false;
}

std::string Patron::getDetails() const { return details; }

bool Patron::checkLogin(std::string user, std::string password) {
  if (user == this->name && password == this->password) {
    return true;
  }
  return false;
}

std::vector<BorrowedBook> Patron::getHistory() const { return history; }

bool Patron::getIsAdmin() const { return isAdmin; }
