
#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "EntityWithBooks.h"

class Author : public EntityWithBooks {
 protected:
  std::string nationality;

 public:
  Author(int id, std::string name, std::string nationality,
         std::vector<Book> books);
  Author(int id, std::string name, std::string nationality);
  // Add other public member function declarations here, if any
  // Setters and getters
  std::string getNationality();
  void setNationality(std::string nationality);
  void displayDetails() override;
};

#endif  // AUTHOR_H
