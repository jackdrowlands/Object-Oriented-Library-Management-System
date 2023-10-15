#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"

// define the Book class
class Book : public Entity {
 public:
  Book(int id, std::string name, const std::string& author,
       const std::string& genre, bool available);
  std::string getAuthor() const;
  std::string getGenre() const;
  bool isAvailable() const;
  Book();

 private:
  std::string author;
  std::string genre;
  bool available;
};

#endif  // BOOK_H
