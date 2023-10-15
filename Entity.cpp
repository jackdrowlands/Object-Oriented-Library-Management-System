#include "Entity.h"

// Constructor
Entity::Entity() {
  this->id = "0";
  this->name = "";
}

Entity::Entity(std::string id, std::string name) {
  this->id = id;
  this->name = name;
}

// Getter functions
std::string Entity::get_id() { return id; }

std::string Entity::get_name() { return name; }

std::vector<Book> Entity::get_books() { return books; }