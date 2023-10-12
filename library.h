#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>

// Define the Book class
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

// Define the Genre class
class Genre {
public:
    Genre(const std::string& name);
    std::string getName() const;
private:
    std::string name;
};

// Define the Author class
class Author {
public:
    Author(const std::string& name);
    std::string getName() const;
private:
    std::string name;
};

// Define the Library class
class Library {
public:
    // Methods for managing books
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    std::vector<Book> getBooks() const;

    // Methods for managing genres
    void addGenre(const Genre& genre);
    void removeGenre(const std::string& name);
    std::vector<Genre> getGenres() const;

    // Methods for managing authors
    void addAuthor(const Author& author);
    void removeAuthor(const std::string& name);
    std::vector<Author> getAuthors() const;
private:
    std::vector<Book> books;
    std::vector<Genre> genres;
    std::vector<Author> authors;
};

#endif // LIBRARY_H