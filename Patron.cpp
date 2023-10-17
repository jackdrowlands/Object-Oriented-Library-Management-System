
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
  (*getHistoryPointer()).push_back(book);
}

// removes checked out book methods
void Patron::removeCheckedOutBook(int bookId) {
  for (std::vector<BorrowedBook>::size_type it = 0; it < getHistory().size();
       it++) {
    if (getHistory()[it].bookID == bookId) {
      (*getHistoryPointer()).erase(getHistory().begin() + it);
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

std::vector<BorrowedBook>* Patron::getHistoryPointer() { return &history; }
// gets browsing history
std::string Patron::getBrowsingHistoryString() {
  std::string historyString = "";
  for (std::vector<BorrowedBook>::size_type i = 0; i < getHistory().size();
       i++) {
    historyString += std::to_string(history[i].bookID) + " " +
                     std::to_string(history[i].dateHired) + " " +
                     std::to_string(history[i].dateDue) + " " +
                     std::to_string(history[i].dateReturned) + " " +
                     std::to_string(history[i].isReturned) + "|";
  }
  return historyString;
}

// displays details
void Patron::displayDetails() {
  std::cout << "Patron ID: " << get_id() << std::endl;
  std::cout << "Patron Name: " << get_name() << std::endl;
  std::cout << "Patron Details: " << getDetails() << std::endl;
  std::cout << "Patron Age: " << get_age() << std::endl;
  std::cout << "Patron Password: " << get_password() << std::endl;
  std::string historyString = getBrowsingHistoryString();
  // split the string by the | and loop through the lines
  std::stringstream ss(historyString);
  std::string history;
  while (std::getline(ss, history, '|')) {
    // split the string by the spaces
    std::istringstream iss(history);
    int id, dateHired, dateDue, dateReturned, isReturned;
    iss >> id >> dateHired >> dateDue >> dateReturned >> isReturned;
    std::cout << "Borrowed Book ID: " << id << std::endl;
    // change the date to a readable format
    time_t t = static_cast<time_t>(dateHired);
    std::string dateHiredStr = std::ctime(&t);
    std::cout << "Date Hired: " << dateHiredStr;
    t = static_cast<time_t>(dateDue);
    std::string dateDueStr = std::ctime(&t);
    std::cout << "Date Due: " << dateDueStr;
    if (isReturned == 1) {
      t = static_cast<time_t>(dateReturned);
      std::string dateReturnedStr = std::ctime(&t);
      std::cout << "Date Returned: " << dateReturnedStr;
    }
    std::cout << "Is Returned: " << isReturned << std::endl;
  }

  std::cout << "Patron Is Admin: " << getIsAdmin() << std::endl;
}