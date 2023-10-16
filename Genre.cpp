
#include "Genre.h"

Genre::Genre(int id, std::string name, std::vector<Book> books, bool restricted,
             bool fictional)
    : Entity(id, name) {
  this->restricted = restricted;
  this->fictional = fictional;
  this->books = books;
}
// Add other method implementations here, if any
