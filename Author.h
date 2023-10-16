
#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "EntityWithBooks.h"

class Author : public EntityWithBooks {
 protected:
  int id;
  std::string name;
  std::vector<Book> books;
  std::string nationality;
  std::vector<std::string> aliases;

 public:
  Author(int id, std::string name, std::string nationality,
         std::vector<std::string> aliases, std::vector<Book> books);
  Author(int id, std::string name, std::string nationality,
         std::vector<std::string> aliases);
  // Add other public member function declarations here, if any
  // Setters and getters
  int getId();
  void setId(int id);
  std::string getName();
  void setName(std::string name);
  std::vector<Book> getBooks();
  void setBooks(std::vector<Book> books);
  std::string getNationality();
  void setNationality(std::string nationality);
  std::vector<std::string> getAliases();
  void setAliases(std::vector<std::string> aliases);
  void displayDetails() override;
  std::string getAliasesString();
};

#endif  // AUTHOR_H
