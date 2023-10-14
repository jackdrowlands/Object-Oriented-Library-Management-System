
#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
#include <vector>
#include "Entity.cpp"
#include "Book.cpp"

struct BorrowedBook {
  int bookID;
  int dateHired;
  int dateDue;
  int dateReturned;
  bool isReturned;
};

class Patron : public Entity {
protected:
    std::string id;
    std::string name;
    std::vector<Book> books;
    std::string details;
    std::vector<BorrowedBook> history;

public:
    // Add public member function declarations here, if any
};

#endif // PATRON_H
