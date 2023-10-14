#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"

// Yet to add the add_book function?

class Entity {
 protected:
  // These private data members refer to a group of books
  // The id and name strings refer to the entity of books
  std::string id;
  std::string name;
  std::vector<Book> books;

 public:
  // Constructor
  Entity() {
    this->id = "0";
    this->name = "";
  }
  Entity(std::string id, std::string name) {
    this->id = id;
    this->name = name;
  }

  // Getter functions
  std::string get_id() { return id; }

  std::string get_name() { return name; }

  std::vector<Book> get_books() { return books; }
};

#endif  // ENTITY_H