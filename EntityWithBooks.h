#ifndef ENTITYWITHBOOKS_H
#define ENTITYWITHBOOKS_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Entity.h"

class EntityWithBooks : public Entity {
 private:
  std::vector<Book> books;

 public:
  std::string get_booksString();
  EntityWithBooks(int id, std::string name, std::vector<Book> books);
  EntityWithBooks(int id, std::string name);
};

#endif  // ENTITYWITHBOOKS_H