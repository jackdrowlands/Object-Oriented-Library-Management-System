#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Entity.h"

struct BorrowedBook {
  int bookID;
  int dateHired;
  int dateDue;
  int dateReturned;
  bool isReturned;
};

class Patron : public Entity {
 private:
  std::string password;

 protected:
  std::string details;
  std::vector<BorrowedBook> history;
  int age;
  bool isAdmin;

 public:
  Patron(int id, std::string name, std::string details, std::string password,
         int age, bool isAdmin, std::vector<BorrowedBook> history)
      : Entity(id, name) {
    this->details = details;
    this->password = password;
    this->age = age;
    this->isAdmin = isAdmin;
    this->history = history;
  }

  Patron() : Entity() {
    this->details = "";
    this->password = "";
    this->age = 0;
    this->isAdmin = false;
  }

  std::string getDetails() { return details; }

  bool checkLogin(std::string user, std::string password) {
    if (user == this->name && password == this->password) {
      return true;
    }
    return false;
  }

  std::vector<BorrowedBook> getHistory() { return history; }

  bool getIsAdmin() { return isAdmin; }

  void set_details(std::string details) { this->details = details; }

  void set_age(int age) { this->age = age; }
};

#endif  // PATRON_H
