#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>

class Entity {
 protected:
  int id;
  std::string name;
  std::vector<Book> books;

 public:
  Entity();
  Entity(int id, std::string name);

  int get_id();
  void set_id(int id);
  std::string get_name();
  void set_name(std::string name);

  virtual void displayDetails();
  std::string get_booksString();
};

#endif  // ENTITY_H