#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <iostream>

#include "Book.h"
#include "Genre.h"
#include "Author.h"


// define the Library class
class Library {
public:
    // methods for managing books
    void add_book(const Book& book);
    void remove_book(const Book& book);
    void update_book(const Book& book);
    Book search_book(const std::string& title) const;
    void generate_report() const;

    // methods for managing genres (unchanged)
    void addGenre(const Genre& genre);
    void removeGenre(const std::string& name);
    std::vector<Genre> getGenres() const;

    // methods for managing authors (unchanged)
    void addAuthor(const Author& author);
    void removeAuthor(const std::string& name);
    std::vector<Author> getAuthors() const;
private:
    std::vector<Book> books;
    std::vector<Genre> genres;
    std::vector<Author> authors;
};

#endif // LIBRARY_H
