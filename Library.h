#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>

#include "Author.h"
#include "Book.h"
#include "Genre.h"
#include "Patron.h"

// Define the Library class
class Library {
 public:
  // Methods for managing books
  void add_book(const Book& book);
  void remove_book(const Book& book);
  void update_book(const Book& book);
  Book* search_book(const std::string& title) const;
  const Book* search_book(const int& id) const;
  void generate_book_report() const;

  // Methods for managing genres
  void add_genre(const Genre& genre);
  void remove_genre(const std::string& name);
  std::vector<Genre> get_genres() const;

  // Methods for managing authors
  void add_author(const Author& author);
  void remove_author(const std::string& name);
  std::vector<Author> get_authors() const;

  // Methods for managing patrons
  void addPatron(Library& library, Patron& patron);
  void deletePatron(Library& library, Patron& patron);

  // General report for the library
  void generate_report() const;

  Library(std::vector<Book> books, std::vector<Genre> genres,
          std::vector<Author> authors);
  std::vector<Book> get_books() const;

  Library();

 private:
  std::vector<Book> books;
  std::vector<Genre> genres;
  std::vector<Author> authors;
  std::vector<Patron> patrons;
};



#endif  // LIBRARY_H
