#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"

// Extra inclusions
#include "Author.h"
#include "Library.h"
#include "Book.h"
#include "Genre.h"
#include "Patron.h"
#include "EntityWithBooks.h"

// define the Book class
class Book : public Entity {
 public:
  bool restricted;
  bool fictional;
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

  bool isRestricted();
  bool isFictional();
  bool getIsRestricted();
  bool getIsFictional();
  void setRestricted(bool restricted);
  void setFictional(bool fictional);

 private:
  std::string author;
  std::string genre;
  bool available;
};

#endif  // BOOK_H
