#include "Book.h"

// implementation of the constructor
Book::Book(const std::string& title, const std::string& author, const std::string& genre) {
    this->title = title;
    this->author = author;
    this->genre = genre;
}

// implementation of the getTitle method
std::string Book::getTitle() const {
    return title;
}

// implementation of the getAuthor method
std::string Book::getAuthor() const {
    return author;
}

// implementation of the getGenre method
std::string Book::getGenre() const {
    return genre;
}

// implementation of the getId method
int Book::getId() const {
    return id;
}
