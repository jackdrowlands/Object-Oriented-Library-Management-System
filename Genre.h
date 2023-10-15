
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
  // Add other public member function declarations here, if any
};

#endif  // GENRE_H
