#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>

class Entity {
 protected:
  int id;
  std::string name;

 public:
  Entity();
  Entity(int id, std::string name);

  int get_id();
  void set_id(int id);
  std::string get_name();
  void set_name(std::string name);

  virtual void displayDetails();
};

#endif  // ENTITY_H