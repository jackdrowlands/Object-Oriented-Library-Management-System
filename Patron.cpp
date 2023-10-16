
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

int Patron::get_id() const {
    return id;
}

std::string Patron::get_details() const {
    return details;
}

std::string Patron::get_login() const {
    return login;
}

std::string Patron::get_password() const {
    return password;
}

std::string Patron::get_name() const {
    return name;
}

int Patron::get_age() const {
    return age;
}

bool Patron::getIsAdmin() const {
    return isAdmin;
}

std::string Patron::getBrowsingHistoryString() const {
    std::stringstream ss;
    for (const auto& borrowedBook : history) {
        ss << borrowedBook.getBookID() << ","
           << borrowedBook.getDateHired() << ","
           << borrowedBook.getDateDue() << ","
           << borrowedBook.getDateReturned() << ","
           << (borrowedBook.isReturned() ? "1" : "0") << ";";
    }
    return ss.str();
}
