#ifndef PATRON_H
#define PATRON_H

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Book.h"
#include "Entity.h"

// struct for book with all details
struct BorrowedBook {
  int bookID;
  int dateHired;
  int dateDue;
  int dateReturned;
  bool isReturned;
};

class Patron : public Entity {
 private:
  std::string password;

 protected:
  std::string details;
  std::vector<BorrowedBook> history;
  int age;
  bool isAdmin;

 public:
  Patron(int id, std::string name, std::string details, std::string password,
         int age, bool isAdmin, std::vector<BorrowedBook> history);
  bool checkLogin(std::string user, std::string password);

  // getters and setters
  std::string getDetails();
  std::vector<BorrowedBook> getHistory();
  std::vector<BorrowedBook>* getHistoryPointer();
  Patron();
  std::string getBrowsingHistoryString();
  bool getIsAdmin();

  void set_details(std::string details);

  void set_age(int age);
  std::string get_details();
  int get_age();
  std::string get_password();

  void addCheckedOutBook(int bookId);
  void removeCheckedOutBook(int bookId);

  void displayDetails() override;
};

#endif
