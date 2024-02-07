#include "Library.h"

// implementing methods for managing books
// add book methods
void Library::add_book(Book& book) { books.push_back(book); }

// remove book methods
void Library::remove_book(Book& book) {
  for (auto it = books.begin(); it != books.end(); ++it) {
    if (it->get_name() == book.get_name()) {
      books.erase(it);
      return;
    }
  }
}
// update details of book methods
void Library::update_book(Book& book) {
  for (auto& b : books) {
    if (b.get_name() == book.get_name()) {
      b = book;
      return;
    }
  }
}

// search for book methods using name
Book* Library::search_book(std::string& title) {
  for (auto& book : books) {
    if (book.get_name() == title) {
      return static_cast<Book*>(&book);
    }
  }
  return nullptr;
}

// search for book methods using id
Book* Library::search_book(int& id) {
  for (auto& book : books) {
    if (book.get_id() == id) {
      return static_cast<Book*>(&book);
    }
  }
  return nullptr;
}

// generate report methods
void Library::generate_report() {
  std::cout << "Library Report" << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Total Books: " << books.size() << std::endl;
  std::cout << "Total Authors: " << authors.size() << std::endl;
  std::cout << "Total Genres: " << genres.size() << std::endl;
}

// implementing methods for managing genres
// adding genre methods
void Library::add_genre(Genre& genre) { genres.push_back(genre); }

// remove genre methods
void Library::remove_genre(std::string& name) {
  for (auto it = genres.begin(); it != genres.end(); ++it) {
    if (it->get_name() == name) {
      genres.erase(it);
      return;
    }
  }
}
// returns a pointer to the genre with the given name
std::vector<Genre>* Library::get_genres() { return &genres; }

// implementing methods for managing authors
// adding author methods
void Library::add_author(Author& author) { authors.push_back(author); }

// remove author methods
void Library::remove_author(std::string& name) {
  for (auto it = authors.begin(); it != authors.end(); ++it) {
    if (it->get_name() == name) {
      authors.erase(it);
      return;
    }
  }
}

// returns a pointer to the author with the given name
std::vector<Author>* Library::get_authors() { return &authors; }

// search for author methods using name
Library::Library(std::vector<Book> books, std::vector<Genre> genres,
                 std::vector<Author> authors)
    : books(books), genres(genres), authors(authors) {}

// reads from csv files and populates the vectors
Library::Library() {
  std::ifstream userFile("users.csv");
  if (!userFile.is_open()) {
    std::cout << "Generating users.csv...\n";
    std::ofstream userFileOut("users.csv");
    userFileOut << "0,admin,admin,admin,admin,99,1,\0\n";
    userFileOut.close();
    userFile.open("users.csv");  // Re-open the file for reading
  } else {
    std::cout << "users.csv found.\n";
    // read from file
  }
  std::string line;
  while (std::getline(userFile, line)) {
    std::stringstream ss(line);
    std::string idString, details, login, password, name, ageString,
        isAdminString, browsingHistoryString;
    std::getline(ss, idString, ',');
    std::getline(ss, details, ',');
    std::getline(ss, login, ',');
    std::getline(ss, password, ',');
    std::getline(ss, name, ',');
    std::getline(ss, ageString, ',');
    std::getline(ss, isAdminString, ',');
    std::getline(ss, browsingHistoryString, ',');
    // Type conversion
    int id = std::stoi(idString);
    int age = std::stoi(ageString);
    bool isAdmin = (isAdminString == "1");
    // browsingHistory is a vector of BorrowedBook
    std::vector<BorrowedBook> browsingHistory;
    // convert browsingHistory from string to vector
    browsingHistory = parseBrowsingHistory(browsingHistoryString);
    // Create Patron object
    Patron patron(id, name, details, password, age, isAdmin, browsingHistory);
    // Append to patrons vector
    patrons.push_back(patron);
  }

  std::ifstream bookFile("book.csv");
  // book has title, author, genre, ID, and availability
  if (!bookFile.is_open()) {
    std::cout << "Generating book.csv...\n";
    std::ofstream bookFileOut("book.csv");
    bookFileOut << "The Lord of the Rings,J.R.R. Tolkien,Fantasy,1,1,\n";
    bookFileOut.close();
    bookFile.open("book.csv");  // Re-open the file for reading
  } else {
    std::cout << "book.csv found.\n";
    // read from file
  }
  while (std::getline(bookFile, line)) {
    std::stringstream ss(line);
    std::string title, author, genre, idString, isAvailableString;
    std::getline(ss, title, ',');
    std::getline(ss, author, ',');
    std::getline(ss, genre, ',');
    std::getline(ss, idString, ',');
    std::getline(ss, isAvailableString, ',');
    // Type conversion
    int id = std::stoi(idString);
    bool isAvailable = (isAvailableString == "1");
    // Create Book object
    Book book(id, title, author, genre, isAvailable);
    // Append to books vector
    books.push_back(book);
  }

  std::ifstream genreFile("genre.csv");
  // genre has ID, name, vector of books, restricted, and fictional
  if (!genreFile.is_open()) {
    std::cout << "Generating genre.csv...\n";
    std::ofstream genreFileOut("genre.csv");
    genreFileOut << "1,Fantasy,,1,0,\n";
    genreFileOut.close();
    genreFile.open("genre.csv");  // Re-open the file for reading
  } else {
    std::cout << "genre.csv found.\n";
    // read from file
  }
  while (std::getline(genreFile, line)) {
    std::stringstream ss(line);
    std::string idString, name, booksString, isRestrictedString,
        isFictionalString;
    std::getline(ss, idString, ',');
    std::getline(ss, name, ',');
    std::getline(ss, booksString, ',');
    std::getline(ss, isRestrictedString, ',');
    std::getline(ss, isFictionalString, ',');
    // Type conversion
    int id = std::stoi(idString);
    bool isRestricted = (isRestrictedString == "1");
    bool isFictional = (isFictionalString == "1");
    // books is a vector of Book
    std::vector<Book> books;
    // convert books from string to vector
    books = parseBooks(booksString);
    // Create Genre object
    Genre genre(id, name, books, isRestricted, isFictional);
    // Append to genres vector
    genres.push_back(genre);
  }

  std::ifstream authorFile("author.csv");
  // author has id, name, vector of books, nationality
  if (!authorFile.is_open()) {
    std::cout << "Generating author.csv...\n";
    std::ofstream authorFileOut("author.csv");
    authorFileOut << "1,J.R.R. Tolkien,The Lord of the Rings|J.R.R. Tolkien|"
                     "Fantasy|1|1;,,English\n";
    authorFileOut.close();
    authorFile.open("author.csv");  // Re-open the file for reading
  } else {
    std::cout << "author.csv found.\n";
    // read from file
  }
  while (std::getline(authorFile, line)) {
    std::stringstream ss(line);
    std::string idString, name, booksString, nationality;
    std::getline(ss, idString, ',');
    std::getline(ss, name, ',');
    std::getline(ss, booksString, ',');
    std::getline(ss, nationality, ',');

    int id = std::stoi(idString);
    std::vector<Book> books = parseBooks(booksString);

    Author author(id, name, nationality, books);
    authors.push_back(author);
  }
}

// getter function for books
std::vector<Book>* Library::get_books() { return &books; }

// getter function for patrons
std::vector<Patron>* Library::get_patrons() { return &patrons; }

// finds patrons methods
Patron* Library::findPatron(std::string user) {
  std::vector<Patron>& patrons = *get_patrons();
  for (std::vector<Patron>::size_type i = 0; i < patrons.size(); i++) {
    if (patrons[i].get_name() == user) {
      // delete the patron from the vector
      patrons.erase(patrons.begin() + patrons[i].get_id());
      return &(patrons[i]);
    }
  }
  return nullptr;
}

// user login methods
Patron* Library::userLogin(std::string user, std::string password) {
  Patron* patron = findPatron(user);
  if (patron != NULL && patron->checkLogin(user, password)) {
    std::cout << "User found: " << std::endl;
    return patron;
  }

  return new Patron();
}

// get book by id methods
Book* Library::getBookByID(int id) {
  std::vector<Book>& books = *get_books();
  for (std::vector<Book>::size_type i = 0; i < books.size(); i++) {
    if (books[i].get_id() == id) {
      return &(books[i]);
    }
  }
  return new Book();
}

// get book by name methods
void Library::addPatron(Library& library, Patron& patron) {
  library.patrons.push_back(patron);
}

// delete patron methods
void Library::deletePatron(Library& library, Patron& patron) {
  for (auto it = library.patrons.begin(); it != library.patrons.end(); ++it) {
    if (it->get_name() == patron.get_name()) {
      library.patrons.erase(it);
      return;
    }
  }
}

// update patron methods
void Library::updatePatronName(Patron* patron, std::string& newName) {
  (*patron).set_name(newName);
}

// update patron methods
void Library::updatePatronDetails(Patron* patron, std::string& newDetails) {
  (*patron).set_details(newDetails);
}

// update patron methods
void Library::updatePatronAge(Patron* patron, int newAge) {}

// parse books methods
std::vector<Book> Library::parseBooks(std::string& booksString) {
  std::vector<Book> books;
  std::stringstream ss(booksString);
  std::string bookStr;
  while (std::getline(ss, bookStr, ';')) {
    // make a new Book object
    Book book;
    std::stringstream ssBook(bookStr);
    std::string title, author, genre, idString, isAvailableString;
    std::getline(ssBook, title, '|');
    std::getline(ssBook, author, '|');
    std::getline(ssBook, genre, '|');
    std::getline(ssBook, idString, '|');
    std::getline(ssBook, isAvailableString, '|');
    // Type conversion
    int id = std::stoi(idString);
    bool isAvailable = (isAvailableString == "1");
    // Set the fields of the Book object
    book.set_name(title);
    book.setAuthor(author);
    book.setGenre(genre);
    book.set_id(id);
    book.setAvailable(isAvailable);
    // Append to books vector
    books.push_back(book);
  }

  return books;
}

std::vector<BorrowedBook> Library::parseBrowsingHistory(
    std::string& browsingHistoryString) {
  std::vector<BorrowedBook> browsingHistory;
  std::stringstream ss(browsingHistoryString);
  std::string borrowedBookStr;

  while (std::getline(ss, borrowedBookStr, '|')) {
    // make a new BorrowedBook object
    BorrowedBook borrowedBook;
    std::stringstream ssBorrowedBook(borrowedBookStr);
    std::string bookIDStr, dateHiredStr, dateDueStr, dateReturnedStr,
        isReturnedStr;
    std::getline(ssBorrowedBook, bookIDStr, ',');
    std::getline(ssBorrowedBook, dateHiredStr, ',');
    std::getline(ssBorrowedBook, dateDueStr, ',');
    std::getline(ssBorrowedBook, dateReturnedStr, ',');
    std::getline(ssBorrowedBook, isReturnedStr, ',');
    // Type conversion
    int bookID = std::stoi(bookIDStr);
    int dateHired = std::stoi(dateHiredStr);
    int dateDue = std::stoi(dateDueStr);
    int dateReturned = std::stoi(dateReturnedStr);
    bool isReturned = (isReturnedStr == "1");
    // Set the fields of the BorrowedBook object
    borrowedBook.bookID = bookID;
    borrowedBook.dateHired = dateHired;
    borrowedBook.dateDue = dateDue;
    borrowedBook.dateReturned = dateReturned;
    borrowedBook.isReturned = isReturned;
    // Append to browsingHistory vector
    browsingHistory.push_back(borrowedBook);
  }

  return browsingHistory;
}
void Library::save_borrow() {
  std::ofstream userFileOut("users.csv");
  for (std::vector<Patron>::size_type i = 0; i < patrons.size(); i++) {
    userFileOut << patrons.at(i).get_id() << "," << patrons.at(i).get_details()
                << "," << patrons.at(i).get_name() << ","
                << patrons.at(i).get_password() << ","
                << patrons.at(i).get_name() << "," << patrons.at(i).get_age()
                << "," << patrons.at(i).getIsAdmin() << ","
                << patrons.at(i).getBrowsingHistoryString() << ",\n";
  }
  userFileOut.close();
}

Library::~Library() {
  // write to file
  std::ofstream userFileOut("users.csv");
  for (std::vector<Patron>::size_type i = 0; i < patrons.size(); i++) {
    userFileOut << patrons.at(i).get_id() << "," << patrons.at(i).get_details()
                << "," << patrons.at(i).get_name() << ","
                << patrons.at(i).get_password() << ","
                << patrons.at(i).get_name() << "," << patrons.at(i).get_age()
                << "," << patrons.at(i).getIsAdmin() << ","
                << patrons.at(i).getBrowsingHistoryString() << ",\n";
  }
  userFileOut.close();
  std::ofstream bookFileOut("book.csv");
  for (std::vector<Book>::size_type i = 0; i < books.size(); i++) {
    bookFileOut << books.at(i).get_name() << "," << books.at(i).getAuthor()
                << "," << books.at(i).getGenre() << "," << books.at(i).get_id()
                << "," << books.at(i).isAvailable() << ",\n";
  }

  bookFileOut.close();
  std::ofstream genreFileOut("genre.csv");
  for (std::vector<Genre>::size_type i = 0; i < genres.size(); i++) {
    genreFileOut << genres.at(i).get_id() << "," << genres.at(i).get_name()
                 << "," << genres.at(i).get_booksString() << ","
                 << genres.at(i).isRestricted() << ","
                 << genres.at(i).isFictional() << ",\n";
  }
  genreFileOut.close();
  std::ofstream authorFileOut("author.csv");
  for (std::vector<Author>::size_type i = 0; i < authors.size(); i++) {
    authorFileOut << authors.at(i).get_id() << "," << authors.at(i).get_name()
                  << "," << authors.at(i).get_booksString() << ","
                  << authors.at(i).getNationality() << ",";
  }
  authorFileOut.close();
}

bool Library::check_out_book(std::string title, Patron& patron) {
  Book* book = search_book(title);
  if (book == nullptr) {
    return false;  // Book does not exist
  }

  if (!book->isAvailable()) {
    return false;  // Book is already checked out
  }

  book->setAvailable(false);

  // Associate the book with the patron
  int bookId = book->get_id();

  patron.addCheckedOutBook(bookId);
  patrons.push_back(patron);
  save_borrow();
  return true;
}

bool Library::return_book(std::string title, Patron& patron) {
  Book* book = search_book(title);
  if (book == nullptr) {
    return false;  // Book does not exist
  }

  if (book->isAvailable()) {
    return false;  // Book was not checked out
  }

  book->setAvailable(true);

  // Remove the association between the book and the patron
  int bookId = book->get_id();
  patron.removeCheckedOutBook(bookId);

  return true;
}

// update patron methods
void Library::update_patron(Patron& updatedPatron) {
  for (Patron& patron : patrons) {
    if (patron.get_id() == updatedPatron.get_id()) {
      patron.set_name(updatedPatron.get_name());  // Update the name
      patron.set_age(updatedPatron.get_age());
      return;
    }
  }
  std::cout << "Patron not found in library records.\n";
}

// search for genre methods using name
Genre* Library::search_genre(std::string& name) {
  for (auto& genre : genres) {
    if (genre.get_name() == name) {
      return static_cast<Genre*>(&genre);
    }
  }
  return nullptr;
}

// search for author methods using name
Author* Library::search_author(std::string& name) {
  for (auto& author : authors) {
    if (author.get_name() == name) {
      return static_cast<Author*>(&author);
    }
  }
  return nullptr;
}

// user login prompts
Patron* Library::userLoginPrompt() {
  std::string adminStr = "admin";
  Patron admin = Patron(0, adminStr, adminStr, adminStr, 99, true, {});
  patrons.push_back(admin);
  std::string login;
  std::string password;
  Patron* user;
  while (true) {
    std::cout << "Enter your login: ";
    std::getline(std::cin, login);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);
    user = userLogin(login, password);
    if ((*user).get_id() != -1) {
      break;
    }
    std::cout << "Wrong login or password" << std::endl;
  }
  return user;
}