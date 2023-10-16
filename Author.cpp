
#include "Author.h"

Author::Author(int id, std::string name, std::string nationality,
               std::vector<std::string> aliases, std::vector<Book> books) {
  this->id = id;
  this->name = name;
  this->nationality = nationality;
  this->aliases = aliases;
  this->books = books;
}
// Add other method implementations here, if any
