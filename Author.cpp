
#include "Author.h"

Author::Author(int id, std::string name, std::string nationality,
               std::vector<Book> books)
    : EntityWithBooks(id, name, books) {
  this->nationality = nationality;
}
Author::Author(int id, std::string name, std::string nationality)
    : EntityWithBooks(id, name) {
  this->nationality = nationality;
}
// Add other method implementations here, if any

// Setters and getters
int Author::getId() { return id; }
void Author::setId(int id) { this->id = id; }
std::string Author::getName() { return name; }
void Author::setName(std::string name) { this->name = name; }
std::string Author::getNationality() { return nationality; }
void Author::setNationality(std::string nationality) {
  this->nationality = nationality;
}

// implementation of the displayDetails method
void Author::displayDetails() {
  Entity::displayDetails();
  std::cout << "Nationality: " << nationality << std::endl;
}
