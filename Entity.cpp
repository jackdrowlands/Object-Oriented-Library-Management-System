#include "Entity.h"

// Constructor
Entity::Entity() {
  this->id = -1;
  this->name = "";
}

Entity::Entity(int id, std::string name) {
  this->id = id;
  this->name = name;
}

// Getter functions
int Entity::get_id() { return id; }

std::string Entity::get_name() { return name; }