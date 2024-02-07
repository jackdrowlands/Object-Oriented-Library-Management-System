#include "Entity.h"

// constructor
Entity::Entity() {
  this->id = -1;
  this->name = "";
}

// constructor with id and name
Entity::Entity(int id, std::string name) {
  this->id = id;
  this->name = name;
}

// getter functions

int Entity::get_id() { return id; }

std::string Entity::get_name() { return name; }

// setter functions
void Entity::set_id(int id) { this->id = id; }

void Entity::set_name(std::string name) { this->name = name; }

// display details
void Entity::displayDetails() {
  std::cout << "ID: " << id << std::endl;
  std::cout << "Name: " << name << std::endl;
}
