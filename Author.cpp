
#include "Author.h"

// initialise author object with ID, name and nationality and a vector of books
Author::Author(int id, std::string name, std::string nationality,
               std::vector<Book> books)
    : EntityWithBooks(id, name, books) {
  this->nationality = nationality;
}

// this constructor is used when creating an author object without books
Author::Author(int id, std::string name, std::string nationality)
    : EntityWithBooks(id, name) {
  this->nationality = nationality;
}

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
