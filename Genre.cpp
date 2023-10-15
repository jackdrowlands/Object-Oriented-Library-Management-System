
#include "Genre.h"

Genre::Genre(int id, std::string name, std::vector<Book> books, bool restricted,
             bool fictional) {
  this->id = id;
  this->name = name;
  this->restricted = restricted;
  this->fictional = fictional;
  this->books = books;
}
// Add other method implementations here, if any
