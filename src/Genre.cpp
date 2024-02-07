
#include "Genre.h"
// constructors 
Genre::Genre(int id, std::string name, std::vector<Book> books, bool restricted,
             bool fictional)
    : EntityWithBooks(id, name, books) {
  this->restricted = restricted;
  this->fictional = fictional;
}
Genre::Genre(int id, std::string name, bool restricted, bool fictional)
    : EntityWithBooks(id, name) {
  this->restricted = restricted;
  this->fictional = fictional;
}

// Setters and getters
bool Genre::isRestricted() { return restricted; }
bool Genre::isFictional() { return fictional; }

void Genre::setRestricted(bool restricted) { this->restricted = restricted; }
void Genre::setFictional(bool fictional) { this->fictional = fictional; }

bool Genre::getIsRestricted() { return restricted; }
bool Genre::getIsFictional() { return fictional; }