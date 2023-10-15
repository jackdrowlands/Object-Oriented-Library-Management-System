#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include "Book.h"

class Entity {
 protected:
  std::string id;
  std::string name;
  std::vector<Book> books;

 public:
  Entity();
  Entity(std::string id, std::string name);
  std::string get_id();
  std::string get_name();
  std::vector<Book> get_books();
};

#endif  // ENTITY_H