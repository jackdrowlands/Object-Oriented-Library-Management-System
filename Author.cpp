
#include "Author.h"

// Extra inclusions
#include "Library.h"
#include "Book.h"
#include "Genre.h"
#include "Patron.h"
#include "Entity.h"
#include "EntityWithBooks.h"

Author::Author(int id, std::string name, std::string nationality,
               std::vector<std::string> aliases, std::vector<Book> books)
    : EntityWithBooks(id, name) {
  this->nationality = nationality;
  this->aliases = aliases;
  this->books = books;
}
// Add other method implementations here, if any

// Setters and getters
int Author::getId() { return id; }
void Author::setId(int id) { this->id = id; }
std::string Author::getName() { return name; }
void Author::setName(std::string name) { this->name = name; }
std::vector<Book> Author::getBooks() { return books; }
void Author::setBooks(std::vector<Book> books) { this->books = books; }
std::string Author::getNationality() { return nationality; }
void Author::setNationality(std::string nationality) {
  this->nationality = nationality;
}
std::vector<std::string> Author::getAliases() { return aliases; }
void Author::setAliases(std::vector<std::string> aliases) {
  this->aliases = aliases;
}

// implementation of the displayDetails method
void Author::displayDetails() {
  Entity::displayDetails();
  std::cout << "Nationality: " << nationality << std::endl;
}

std::string Author::getAliasesString() {
  std::string aliasesString = "";
  for (int i = 0; i < aliases.size(); i++) {
    aliasesString += aliases[i];
    if (i != aliases.size() - 1) {
      aliasesString += ";";
    }
  }
  return aliasesString;
}