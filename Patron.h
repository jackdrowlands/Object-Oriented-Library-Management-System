
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
  std::string id;
  std::string name;
  std::vector<Book> books;
  std::string details;
  std::vector<BorrowedBook> history;

 public:
  // Add public member function declarations here, if any
  Patron(std::string id, std::string name, std::string details);
  Patron* login(std::string user, std::string password);
  bool checkLogin(std::string user, std::string password);
};

#endif  // PATRON_H
