#include "Patron.h"

class User : public Patron {
 private:
  public:
  User(Patron* patron);
  User();
  void viewBooks(Library& library);
  void viewGenres(Library& library);
  void viewAuthors(Library& library);

  void borrowBook(Library& library);
  void returnBook(Library& library);
  void viewHistory(Library& library);
  void viewDetails(Library& library);
  void viewProfile(Library& library);
};