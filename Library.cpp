#include "Library.h"

// implementing methods for managing books

void Library::add_book( Book& book) { books.push_back(book); }

void Library::remove_book( Book& book) {
  for (auto it = books.begin(); it != books.end(); ++it) {
    if (it->get_name() == book.get_name()) {
      books.erase(it);
      return;
    }
  }
}

void Library::update_book( Book& book) {
  for (auto& b : books) {
    if (b.get_name() == book.get_name()) {
      b = book;  // assumes Book has an assignment operator
      return;
    }
  }
}

Book* Library::search_book( std::string& title)  {
  for ( auto& book : books) {
    if (book.get_name() == title) {
      return _cast<Book*>(&book);
    }
  }
  return nullptr;
}

 Book* Library::search_book( int& id)  {
  for ( auto& book : books) {
    if (book.get_id() == id) {
      return _cast< Book*>(&book);
    }
  }
  return nullptr;
}

void Library::generate_report()  {
  std::cout << "Library Report" << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Total Books: " << books.size() << std::endl;
  std::cout << "Total Authors: " << authors.size() << std::endl;
  std::cout << "Total Genres: " << genres.size() << std::endl;
}

// implementing methods for managing genres

void Library::add_genre( Genre& genre) { genres.push_back(genre); }

void Library::remove_genre( std::string& name) {
  for (auto it = genres.begin(); it != genres.end(); ++it) {
    if (it->get_name() == name) {
      genres.erase(it);
      return;
    }
  }
}

std::vector<Genre>* Library::get_genres() { return &genres; }

// implementing methods for managing authors

void Library::add_author( Author& author) { authors.push_back(author); }

void Library::remove_author( std::string& name) {
  for (auto it = authors.begin(); it != authors.end(); ++it) {
    if (it->get_name() == name) {
      authors.erase(it);
      return;
    }
  }
}

std::vector<Author>* Library::get_authors() { return &authors; }

Library::Library(std::vector<Book> books, std::vector<Genre> genres,
                 std::vector<Author> authors)
    : books(books), genres(genres), authors(authors) {}

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
    std::ofstream bookFile("book.csv");
    bookFile << "The Lord of the Rings,J.R.R. Tolkien,1,1,\n";
    bookFile.close();
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
    std::ofstream genreFile("genre.csv");
    genreFile << "1,Fantasy,1,0,\n";
    genreFile.close();
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
  // author has id, name, vector of books, nationality, and vector of aliases
  if (!authorFile.is_open()) {
    std::cout << "Generating author.csv...\n";
    std::ofstream authorFile("author.csv");
    authorFile << "1,J.R.R. Tolkien,1,English,\n";
    authorFile.close();
    authorFile.open("author.csv");  // Re-open the file for reading
  } else {
    std::cout << "author.csv found.\n";
    // read from file
  }
  std::getline(authorFile, line);
  while (std::getline(authorFile, line)) {
    std::ifstream authorFile("author.csv");
    if (!authorFile.is_open()) {
      std::cout << "Generating author.csv...\n";
      std::ofstream authorFile("author.csv");
      authorFile << "1,J.R.R. Tolkien,1,English,\n";
      authorFile.close();
      authorFile.open("author.csv");
    } else {
      std::cout << "author.csv found.\n";
    }
    std::string line;
    std::getline(authorFile, line);
    while (std::getline(authorFile, line)) {
      std::stringstream ss(line);
      std::string idString, name, booksString, nationality, aliasesString;
      std::getline(ss, idString, ',');
      std::getline(ss, name, ',');
      std::getline(ss, booksString, ',');
      std::getline(ss, nationality, ',');
      std::getline(ss, aliasesString, ',');

      int id = std::stoi(idString);
      std::vector<Book> books = parseBooks(booksString);
      // Assuming aliases are semicolon-separated
      std::vector<std::string> aliases;
      std::stringstream ssAliases(aliasesString);
      std::string alias;
      while (std::getline(ssAliases, alias, ';')) {
        aliases.push_back(alias);
      }

      Author author(id, name, nationality, aliases, books);
      authors.push_back(author);
    }
  }
}

std::vector<Book>* Library::get_books() { return &books; }

std::vector<Patron>* Library::get_patrons() { return &patrons; }

Patron* Library::findPatron(std::string user) {
  std::vector<Patron>& patrons = *get_patrons();
  for (std::vector<Patron>::size_type i = 0; i < patrons.size(); i++) {
    if (patrons[i].get_name() == user) {
      return &(patrons[i]);
    }
  }
  return nullptr;
}

Patron* Library::userLogin(std::string user, std::string password) {
  Patron* patron = findPatron(user);
  if (patron != NULL && patron->checkLogin(user, password)) {
    std::cout << "User found: " << std::endl;
    return patron;
  }

  return new Patron();
}

Book* Library::getBookByID(int id) {
  std::vector<Book>& books = *get_books();
  for (std::vector<Book>::size_type i = 0; i < books.size(); i++) {
    if (books[i].get_id() == id) {
      return &(books[i]);
    }
  }
  return new Book();
}

void Library::addPatron(Library& library, Patron& patron) {
  library.patrons.push_back(patron);
}

void Library::deletePatron(Library& library, Patron& patron) {
  for (auto it = library.patrons.begin(); it != library.patrons.end(); ++it) {
    if (it->get_name() == patron.get_name()) {
      library.patrons.erase(it);
      return;
    }
  }
}


void Library::updatePatronName(Patron *patron, std::string &newName) {
  (*patron).set_name(newName);
  }

void Library::updatePatronDetails(Patron *patron, std::string &newDetails) {
    (*patron).set_details(newDetails);
}

void Library::updatePatronAge(Patron *patron, int newAge) {
    
}

std::vector<Book> Library::parseBooks(const std::string& booksString) {

  std::vector<Book> books;
  // Assuming booksString is a semicolon-delimited string of book IDs
  std::stringstream ss(booksString);
  std::string bookIDStr;

  while (std::getline(ss, bookIDStr, ';')) {
    int bookID = std::stoi(bookIDStr);
    // Assuming you have a function getBookByID to fetch a Book by its ID
    Book book = *(getBookByID(bookID));
    books.push_back(book);
  }

  return books;
}

std::vector<BorrowedBook> Library::parseBrowsingHistory(
     std::string& browsingHistoryString) {
  std::vector<BorrowedBook> browsingHistory;
  // Assuming browsingHistoryString is a semicolon-delimited string of
  // BorrowedBook
  std::stringstream ss(browsingHistoryString);
  std::string borrowedBookStr;

  while (std::getline(ss, borrowedBookStr, ';')) {
    // make a new BorrowedBook object
    BorrowedBook borrowedBook;
    // Assuming borrowedBookStr is a comma-delimited string of
    // bookID,dateHired,dateDue,dateReturned,isReturned
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

Library::~Library() {
  // write to file
  std::ofstream userFileOut("users.csv");
  for (std::vector<Patron>::size_type i = 0; i < patrons.size(); i++) {
    userFileOut << patrons.at(i).get_id() << "," << patrons.at(i).get_details()
                << "," << patrons.at(i).get_login() << ","
                << patrons.at(i).get_password() << ","
                << patrons.at(i).get_name() << "," << patrons.at(i).get_age()
                << "," << patrons.at(i).getIsAdmin() << ","
                << patrons.at(i).getBrowsingHistoryString() << ",\n";
  }
  userFileOut.close();
  std::ofstream bookFileOut("book.csv");
  for (std::vector<Book>::size_type i = 0; i < books.size(); i++) {
    bookFileOut << books.at(i).get_title() << "," << books.at(i).get_author()
                << "," << books.at(i).get_genre() << "," << books.at(i).get_id()
                << "," << books.at(i).getIsAvailable() << ",\n";
  }
  bookFileOut.close();
  std::ofstream genreFileOut("genre.csv");
  for (std::vector<Genre>::size_type i = 0; i < genres.size(); i++) {
    genreFileOut << genres.at(i).get_name() << ","
                 << genres.at(i).get_booksString() << ","
                 << genres.at(i).get_id() << ","
                 << genres.at(i).getIsRestricted() << ","
                 << genres.at(i).getIsFictional() << ",\n";
  }
  genreFileOut.close();
  std::ofstream authorFileOut("author.csv");
  for (std::vector<Author>::size_type i = 0; i < authors.size(); i++) {
    authorFileOut << authors.at(i).get_name() << ","
                  << authors.at(i).get_booksString() << ","
                  << authors.at(i).get_id() << ","
                  << authors.at(i).getNationality() << ","
                  << authors.at(i).getAliasesString() << ",\n";
  }
  authorFileOut.close();

  // delete vectors
  delete &books;
  delete &genres;
  delete &authors;
}