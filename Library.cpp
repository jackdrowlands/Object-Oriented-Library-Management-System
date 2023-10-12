#include "Library.h"

// implementing methods for managing books

void Library::add_book(const Book& book) {
    books.push_back(book);
}

void Library::remove_book(const Book& book) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == book.getTitle()) {
            books.erase(it);
            return;
        }
    }
}

void Library::update_book(const Book& book) {
    for (auto& b : books) {
        if (b.getTitle() == book.getTitle()) {
            b = book; // assumes Book has an assignment operator
            return;
        }
    }
}

Book Library::search_book(const std::string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            return book;
        }
    }
    // assumes that Book has a default constructor
    return Book("", "", "");
}

void Library::generate_report() const {
    std::cout << "Library Report" << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << "Total Books: " << books.size() << std::endl;
    std::cout << "Total Authors: " << authors.size() << std::endl;
    std::cout << "Total Genres: " << genres.size() << std::endl;
}

// implementing methods for managing genres

void Library::addGenre(const Genre& genre) {
    genres.push_back(genre);
}

void Library::removeGenre(const std::string& name) {
    for (auto it = genres.begin(); it != genres.end(); ++it) {
        if (it->getName() == name) {
            genres.erase(it);
            return;
        }
    }
}

std::vector<Genre> Library::getGenres() const {
    return genres;
}

// implementing methods for managing authors

void Library::addAuthor(const Author& author) {
    authors.push_back(author);
}

void Library::removeAuthor(const std::string& name) {
    for (auto it = authors.begin(); it != authors.end(); ++it) {
        if (it->getName() == name) {
            authors.erase(it);
            return;
        }
    }
}

std::vector<Author> Library::getAuthors() const {
    return authors;
}
