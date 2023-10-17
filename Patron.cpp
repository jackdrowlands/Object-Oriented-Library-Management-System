
#include "Patron.h"

// Constructors
Patron::Patron(int id, std::string name, std::string details,
               std::string password, int age, bool isAdmin,
               std::vector<BorrowedBook> history)
    : Entity(id, name) {
  this->details = details;
  this->password = password;
  this->age = age;
  this->isAdmin = isAdmin;
  this->history = history;
}

// Default constructor
Patron::Patron() : Entity() {
  this->details = "";
  this->password = "";
  this->age = 0;
  this->isAdmin = false;
}


// checks login credentials
bool Patron::checkLogin(std::string user, std::string password) {
  if (user == this->name && password == this->password) {
    return true;
  }
  return false;
}




void Patron::addCheckedOutBook(int bookId) {
  // Get the current date
  BorrowedBook book;
  std::time_t now = std::time(0);
  std::time_t dueInDays = 14;

  // Assign the various fields
  book.bookID = bookId;
  book.dateHired = static_cast<int>(now);
  book.dateDue = static_cast<int>(now + dueInDays);
  book.isReturned = false;

  // Add the book to the list of checked-out books
  getHistory().push_back(book);
}


// removes checked out book methods
void Patron::removeCheckedOutBook(int bookId) {
  for (std::vector<BorrowedBook>::size_type it = 0; it < getHistory().size();
       it++) {
    if (getHistory()[it].bookID == bookId) {
      getHistory().erase(getHistory().begin() + it);
      return;
    }
  }
}

// getters and setters
std::string Patron::get_details() { return details; }

int Patron::get_age() { return age; }

std::string Patron::get_password() { return password; }

bool Patron::getIsAdmin() { return isAdmin; }

void Patron::set_details(std::string details) { this->details = details; }

void Patron::set_age(int age) { this->age = age; }

// getter for details
std::string Patron::getDetails() { return details; }


// getter for history
std::vector<BorrowedBook> Patron::getHistory() { return history; }
// gets browsing history
std::string Patron::getBrowsingHistoryString() {
  std::string historyString = "";
  for (std::vector<BorrowedBook>::size_type i = 0; i < history.size(); i++) {
    historyString += std::to_string(history[i].bookID) + " " +
                     std::to_string(history[i].dateHired) + " " +
                     std::to_string(history[i].dateDue) + " " +
                     std::to_string(history[i].dateReturned) + " " +
                     std::to_string(history[i].isReturned) + "\n";
  }
  return historyString;
}