
#include "Patron.h"

// Add method implementations here, if any

Patron::Patron(std::string id, std::string name, std::string details) {
  this->id = id;
  this->name = name;
  this->details = details;
}

Patron* Patron::findPatron(std::vector<Patron*> patrons, std::string id) {
  for (int i = 0; i < patrons.size(); i++) {
    if (patrons[i]->getId() == id) {
      return patrons[i];
    }
  }
  return NULL;
}

std::string Patron::getId() const { return id; }

std::string Patron::getName() const { return name; }

std::string Patron::getDetails() const { return details; }

bool Patron::checkLogin(std::string user, std::string password) {
  if (user == id && password == this->password) {
    return true;
  }
  return false;
}

Patron* Patron::login(std::string user, std::string password,
                      std::vector<Patron*> patrons) {
  if (checkLogin(findPatron(patrons, user))) {
    return findPatron(patrons, user);
  }
  return NULL;
}
