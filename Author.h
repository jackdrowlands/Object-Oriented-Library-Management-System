
#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "EntityWithBooks.h"

class Author : public EntityWithBooks {
  // protected member variables are accessible in the class and its subclasses
 protected:
  int id;
  std::string name;
  std::string nationality;

  // public ones are accessible everywhere
 public:
  // constructors
  Author(int id, std::string name, std::string nationality,
         std::vector<Book> books);
  Author(int id, std::string name, std::string nationality);
  // add other public member function declarations here, if any
  // setters and getters
  int getId();
  void setId(int id);
  std::string getName();
  void setName(std::string name);
  std::string getNationality();
  void setNationality(std::string nationality);
  void displayDetails() override;
};

#endif 
