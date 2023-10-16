#ifndef ENTITY_H
#define ENTITY_H

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
  std::string get_name();
  void set_id(int id);
  void set_name(std::string name);

};

#endif  // ENTITY_H