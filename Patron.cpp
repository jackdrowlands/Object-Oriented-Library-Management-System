#include <iostream>
#include <string>
#include <vector>
#include "Entity.cpp"
using namespace std;

// Yet to add the add_book function?

class Patron : public Entity {
protected:
    string id;
    string name;
    vector<Book> books;
    string details;
    std::vector<Book> history; // A vector which describes the list of books 
                               //previously borrowed by that patron
    int age;

public:
Patron(std::string id, std::string name, std::string details, int age){
        this->id = id;
        this->name = name;
        this->details = details;
        this->age = age;
    }

    // Getter functions
    std::string get_id(){
        return id;
    }
    
    std::string get_name(){
        return name;
    }

    std::string get_contact_details(){
        return details;
    }

    int get_age(){
        return age;
    }

    std::vector<Book> get_borrowing_history(){
        return history;
    }
};