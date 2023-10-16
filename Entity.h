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
  int get_id() const;
  std::string get_name() const;
};

#endif  // ENTITY_H