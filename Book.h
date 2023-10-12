#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>
#include <iostream>



// define the Book class
class Book {
public:
    Book(const std::string& title, const std::string& author, const std::string& genre);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
private:
    std::string title;
    std::string author;
    std::string genre;
};

#endif // BOOK_H

