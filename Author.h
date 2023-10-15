
#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Entity.cpp"

class Author : public Entity {
 protected:
  int id;
  std::string name;
  std::vector<Book> books;
  std::string nationality;
  std::vector<std::string> aliases;

 public:
  Author(int id, std::string name, std::string nationality,
         std::vector<std::string> aliases, std::vector<Book> books);
  // Add other public member function declarations here, if any
};

#endif  // AUTHOR_H
