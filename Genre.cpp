
#include "Genre.h"

// Extra inclusions
#include "Author.h"
#include "Library.h"
#include "Book.h"
#include "Patron.h"
#include "Entity.h"
#include "EntityWithBooks.h"

Genre::Genre(int id, std::string name, std::vector<Book> books, bool restricted,
             bool fictional)
    : EntityWithBooks(id, name) {
  this->restricted = restricted;
  this->fictional = fictional;
  this->books = books;
}
// Add other method implementations here, if any

// Setters and getters
std::vector<Book> Genre::getBooks() { return books; }
bool Genre::isRestricted() { return restricted; }
bool Genre::isFictional() { return fictional; }

void Genre::setBooks(std::vector<Book> books) { this->books = books; }
void Genre::setRestricted(bool restricted) { this->restricted = restricted; }
void Genre::setFictional(bool fictional) { this->fictional = fictional; }

bool Genre::getIsRestricted() { return restricted; }

bool Genre::getIsFictional() { return fictional; }