
#ifndef GENRE_H
#define GENRE_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Entity.h"

class Genre : public Entity {
 protected:
  std::vector<Book> books;
  bool restricted;
  bool fictional;

 public:
  Genre(int id, std::string name, std::vector<Book> books, bool restricted,
        bool fictional);

  // Setters and getters
  std::vector<Book> getBooks();
  bool isRestricted();
  bool isFictional();
  bool getIsRestricted();
  bool getIsFictional();
  void setBooks(std::vector<Book> books);
  void setRestricted(bool restricted);
  void setFictional(bool fictional);
};

#endif  // GENRE_H