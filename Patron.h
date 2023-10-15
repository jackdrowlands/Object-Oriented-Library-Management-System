
#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.cpp"
#include "Entity.cpp"

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
  int id;
  std::string name;
  std::string details;
  std::vector<BorrowedBook> history;
  int age;
  bool isAdmin;

 public:
  // Add public member function declarations here, if any
  Patron(int id, std::string name, std::string details, std::string password,
         int age, bool isAdmin, std::vector<BorrowedBook> history);
  bool checkLogin(std::string user, std::string password);
  int getId() const;
  std::string getName() const;
  std::string getDetails() const;
  std::vector<BorrowedBook> getHistory() const;
  Patron();
  bool getIsAdmin() const;
};

#endif  // PATRON_H
