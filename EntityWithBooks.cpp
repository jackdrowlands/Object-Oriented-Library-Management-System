#include "EntityWithBooks.h"

// Get books string
std::string EntityWithBooks::get_booksString() {
  std::string booksString = "";
  for (int i = 0; i < books.size(); i++) {
    booksString += books[i].get_name();
    booksString += "|";
    booksString += books[i].getAuthor();
    booksString += "|";
    booksString += books[i].getGenre();
    booksString += "|";
    booksString += std::to_string(books[i].get_id());
    booksString += "|";
    booksString += std::to_string(books[i].isAvailable());
    booksString += ";";
  }
  return booksString;
}

EntityWithBooks::EntityWithBooks(int id, std::string name,
                                 std::vector<Book> books)
    : Entity(id, name) {
  this->books = books;
}
EntityWithBooks::EntityWithBooks(int id, std::string name) : Entity(id, name) {}

// Setters and getters
std::vector<Book> EntityWithBooks::getBooks() { return books; }
void EntityWithBooks::setBooks(std::vector<Book> books) { this->books = books; }
