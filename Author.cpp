
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
std::string Author::getNationality() { return nationality; }
void Author::setNationality(std::string nationality) {
  this->nationality = nationality;
}

// implementation of the displayDetails method
void Author::displayDetails() {
  Entity::displayDetails();
  std::cout << "Nationality: " << nationality << std::endl;
}
