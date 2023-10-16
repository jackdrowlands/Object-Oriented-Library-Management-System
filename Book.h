#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"

// define the Book class
class Book : public Entity {
 public:
  Book(int id, std::string name, std::string& author, std::string& genre,
       bool available);

  Book();
  // Setters and getters
  void setAuthor(std::string author);
  std::string getAuthor();
  void setGenre(std::string genre);
  std::string getGenre();
  void setAvailable(bool available);
  bool isAvailable();
  void displayDetails() override;

 private:
  std::string author;
  std::string genre;
  bool available;
};

#endif  // BOOK_H
