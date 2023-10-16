#include "Entity.h"

// ructor
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

// Setter functions
void Entity::set_id(int id) { this->id = id; }

void Entity::set_name(std::string name) { this->name = name; }

// Display details
void Entity::displayDetails() {
  std::cout << "ID: " << id << std::endl;
  std::cout << "Name: " << name << std::endl;
}

// Get books string
std::string Entity::get_booksString() {
  std::string booksString = "";
  for (int i = 0; i < books.size(); i++) {
    booksString += books[i].get_name();
    booksString += ";";
    booksString += books[i].getAuthor();
    booksString += ";";
    booksString += books[i].getGenre();
    booksString += ";";
    booksString += std::to_string(books[i].get_id());
    booksString += ";";
    booksString += std::to_string(books[i].isAvailable());
    booksString += ",";
  }
  return booksString;
}