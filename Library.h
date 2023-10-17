#ifndef LIBRARY_H
#define LIBRARY_H

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
  void add_book(Book& book);
  void remove_book(Book& book);
  void update_book(Book& book);
  Book* search_book(std::string& title);
  Book* search_book(int& id);
  void generate_book_report();

  // Methods for managing genres
  void add_genre(Genre& genre);
  void remove_genre(std::string& name);
  std::vector<Genre>* get_genres();
  Genre* search_genre(std::string& name);

  // Methods for managing authors
  void add_author(Author& author);
  void remove_author(std::string& name);
  std::vector<Author>* get_authors();
  Author* search_author(std::string& name);

  // General report for the library
  void generate_report();

  Library(std::vector<Book> books, std::vector<Genre> genres,
          std::vector<Author> authors);
  std::vector<Book>* get_books();
  Library();
  std::vector<Patron>* get_patrons();

  Patron* findPatron(std::string name);
  Patron* userLogin(std::string user, std::string password);
  Book* getBookByID(int id);

  // Method for managing patrons
  void addPatron(Library& library, Patron& patron);
  void deletePatron(Library& library, Patron& patron);
  void updatePatronName(Patron* patron, std::string& newName);
  void updatePatronDetails(Patron* patron, std::string& newDetails);
  void updatePatronAge(Patron* patron, int newAge);

  std::vector<Book> parseBooks(std::string& booksString);
  std::vector<BorrowedBook> parseBrowsingHistory(
      std::string& browsingHistoryString);

  std::vector<Patron*> patrons;
  Patron* findPatronByName(const std::string& name) {
    for (Patron* patron : patrons) {
      if (patron->get_name() == name) {
        return patron;
      }
    }
    return nullptr;
  }




  ~Library();
  // check out and return books
  bool check_out_book(std::string title, Patron& patron);
  bool return_book(std::string title, Patron& patron);

  // update patron data
  void update_patron(Patron& updatedPatron);



 private:
  std::vector<Book> books;
  std::vector<Genre> genres;
  std::vector<Author> authors;
  std::vector<Patron> patrons;
};

#endif  // LIBRARY_H
