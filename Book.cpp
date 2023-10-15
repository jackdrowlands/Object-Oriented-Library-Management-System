#include "Book.h"

// implementation of the constructor
Book::Book(const std::string& title, const std::string& author,
           const std::string& genre, const int& id, bool available) {
  this->title = title;
  this->author = author;
  this->genre = genre;
  this->id = id;
  this->available = available;
}

// implementation of the default constructor
Book::Book() {
  this->title = "";
  this->author = "";
  this->genre = "";
  this->id = 0;
  this->available = false;
}

// implementation of the getTitle method
std::string Book::getTitle() const { return title; }

// implementation of the getAuthor method
std::string Book::getAuthor() const { return author; }

// implementation of the getGenre method
std::string Book::getGenre() const { return genre; }

// implementation of the getId method
int Book::getId() const { return id; }

// implementation of the isAvailable method
bool Book::isAvailable() const { return available; }
