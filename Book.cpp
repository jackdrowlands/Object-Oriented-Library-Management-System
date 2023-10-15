#include "Book.h"

// implementation of the constructor
Book::Book(int id, std::string name, const std::string& author,
           const std::string& genre, bool available)
    : Entity(id, name) {
  this->author = author;
  this->genre = genre;
  this->available = available;
}

// implementation of the default constructor
Book::Book() : Entity() {
  this->name = "";
  this->author = "";
  this->genre = "";
  this->id = 0;
  this->available = false;
}

// implementation of the getAuthor method
std::string Book::getAuthor() const { return author; }

// implementation of the getGenre method
std::string Book::getGenre() const { return genre; }

// implementation of the isAvailable method
bool Book::isAvailable() const { return available; }
