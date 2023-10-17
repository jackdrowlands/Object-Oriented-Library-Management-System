// Unit test for the handleAddBook() function

#ifndef UNITTEST1_H
#define UNITTEST1_H

#include <iostream>

#include "Library.h"
#include "Patron.h"

class UnitTest1 {
public:
    void testHandleAddBook() {
        Library library;
        std::string testTitle = "Test Book";
        std::string testAuthor = "Test Author";
        std::string testGenre = "Test Genre";
        bool testIsRestricted = false;
        bool testIsFictional = true;

        std::stringstream input; // gives string interface instead of cin
        input << testTitle << "\n" << testAuthor << "\n" << testGenre << "\n" << "0" << "\n" << "1" << "\n";
        std::cin.rdbuf(input.rdbuf());
        
        std::vector<Book>* books = library.get_books();
        if (!books->empty()) {
            Book& addedBook = books->back();
            if (addedBook.get_name() == testTitle &&
                addedBook.getAuthor() == testAuthor &&
                addedBook.getGenre() == testGenre &&
                addedBook.isRestricted() == testIsRestricted &&
                addedBook.isFictional() == testIsFictional) {
                std::cout << "handleAddBook function PASSED" << std::endl;
            } else {
                std::cout << "handleAddBook function FAILED" << std::endl;
            }
        } else {
            std::cout << "handleAddBook FAILED" << std::endl;
        }
    }
};
#endif