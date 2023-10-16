#ifndef LIBRARY_H
#define LIBRARY_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
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
  std::vector<Genre>* get_genres();

  // Methods for managing authors
  void add_author(const Author& author);
  void remove_author(const std::string& name);
  std::vector<Author>* get_authors();

  // General report for the library
  void generate_report() const;

  Library(std::vector<Book> books, std::vector<Genre> genres,
          std::vector<Author> authors);
  std::vector<Book>* get_books();

  Library();

  std::vector<Patron>* get_patrons();

  Patron* findPatron(std::string name);

  Patron* userLogin(std::string user, std::string password);

  Book* getBookByID(int id);

  void addPatron(Library& library, Patron& patron);
  void deletePatron(Library& library, Patron& patron);

  std::vector<Book> parseBooks(const std::string& booksString);
  std::vector<BorrowedBook> Library::parseBrowsingHistory(
      const std::string& browsingHistoryString);

 private:
  std::vector<Book> books;
  std::vector<Genre> genres;
  std::vector<Author> authors;
  std::vector<Patron> patrons;
};

#endif  // LIBRARY_H
