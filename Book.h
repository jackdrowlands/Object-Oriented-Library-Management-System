#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>

// define the Book class
class Book {
 public:
  Book(const std::string& title, const std::string& author,
       const std::string& genre);
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getGenre() const;
  bool isAvailable() const;
  int getId() const;

 private:
  std::string title;
  std::string author;
  std::string genre;
  bool available;
  int id;
};

#endif  // BOOK_H
