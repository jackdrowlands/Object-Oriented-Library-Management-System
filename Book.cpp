#include "Book.h"

// implementation of the ructor
Book::Book(int id, std::string name,  std::string& author,
            std::string& genre, bool available)
    : Entity(id, name) {
  this->author = author;
  this->genre = genre;
  this->available = available;
}

// implementation of the default ructor
Book::Book() : Entity() {
  this->name = "";
  this->author = "";
  this->genre = "";
  this->id = 0;
  this->available = false;
}

// implementation of the getAuthor method
std::string Book::getAuthor()  { return author; }

// implementation of the getGenre method
std::string Book::getGenre()  { return genre; }

// implementation of the isAvailable method
bool Book::isAvailable()  { return available; }


// Setters and getters
void Book::setAuthor(std::string author) { this->author = author; }
std::string Book::getAuthor()  { return author; }
void Book::setGenre(std::string genre) { this->genre = genre; }
std::string Book::getGenre()  { return genre; }
void Book::setAvailable(bool available) { this->available = available; }
bool Book::isAvailable()  { return available; }