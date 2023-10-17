
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "Author.h"
#include "Book.h"
#include "Entity.h"
#include "EntityWithBooks.h"
#include "Genre.h"
#include "Library.h"
#include "Patron.h"

// Test cases for Author class
void test_Author_methods() {
  std::cout << "Testing Author methods..." << std::endl;

  // Test constructor and getters
  Author author1(1, "Author1", "Nationality1");
  assert(author1.get_id() == 1);
  assert(author1.get_name() == "Author1");
  assert(author1.getNationality() == "Nationality1");

  // Test setters
  author1.set_id(2);
  author1.set_name("NewAuthor1");
  author1.setNationality("NewNationality1");
  assert(author1.get_id() == 2);
  assert(author1.get_name() == "NewAuthor1");
  assert(author1.getNationality() == "NewNationality1");

  // TODO: Add more test cases as needed

  std::cout << "All Author test cases passed." << std::endl;
}

// Test cases for Book class
void test_Book_methods() {
  std::cout << "Testing Book methods..." << std::endl;

  // Test constructor and getters
  std::string author1 = "Author1";
  std::string genre1 = "Genre1";
  Book book1(1, "Book1", author1, genre1, true);
  assert(book1.get_id() == 1);
  assert(book1.get_name() == "Book1");
  assert(book1.getAuthor() == "Author1");
  assert(book1.getGenre() == "Genre1");
  assert(book1.isAvailable() == true);

  // Test setters
  book1.setAuthor("NewAuthor1");
  book1.setGenre("NewGenre1");
  book1.setAvailable(false);
  assert(book1.getAuthor() == "NewAuthor1");
  assert(book1.getGenre() == "NewGenre1");
  assert(book1.isAvailable() == false);

  // TODO: Add more test cases as needed

  std::cout << "All Book test cases passed." << std::endl;
}

// Test cases for Patron class
void test_Patron_methods() {
  std::cout << "Testing Patron methods..." << std::endl;

  // Test constructor and getters
  std::vector<BorrowedBook> history;
  Patron patron1(1, "Patron1", "Details1", "Password1", 30, false, history);
  assert(patron1.get_id() == 1);
  assert(patron1.get_name() == "Patron1");
  assert(patron1.getDetails() == "Details1");
  assert(patron1.get_age() == 30);
  assert(patron1.getIsAdmin() == false);

  // Test setters
  patron1.set_details("NewDetails1");
  patron1.set_age(35);
  assert(patron1.getDetails() == "NewDetails1");
  assert(patron1.get_age() == 35);

  // Test login check
  assert(patron1.checkLogin("Patron1", "Password1") == true);
  assert(patron1.checkLogin("WrongUser", "WrongPassword") == false);

  // TODO: Add more test cases as needed

  std::cout << "All Patron test cases passed." << std::endl;
}

void test_Library_methods() {
  std::cout << "Testing Library methods..." << std::endl;

  // Initialize Library
  Library library;

  // Test adding a book

  std::string author1 = "Author1";
  std::string genre1 = "Genre1";
  Book book1(1, "Book1", author1, genre1, true);
  library.add_book(book1);
  // TODO: Add a method in Library to get a book by ID or name and use it for
  // assertion

  // Test removing a book
  library.remove_book(book1);
  // TODO: Add a method in Library to get a book by ID or name and use it for
  // assertion to confirm removal

  // TODO: Test check_out_book and return_book methods
  // TODO: Test update_patron method

  // TODO: Add more test cases as needed

  std::cout << "All Library test cases passed." << std::endl;
}

int main() {
  std::cout << "Running unit tests..." << std::endl;

  test_Author_methods();
  test_Book_methods();
  test_Patron_methods();
  test_Library_methods();

  std::cout << "All unit tests passed." << std::endl;

  return 0;
}
