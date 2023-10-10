#include <iostream>
#include <string>
#include <vector>
#include "Entity.cpp"
using namespace std;

// Yet to add the add_book function?

class Genre : public Entity {
protected:
    string id;
    string name;
    vector<Book> books;
    bool restricted;
    bool fictional;

    public:
    Genre(std::string id, std::string name, bool restricted, bool fictional){
        this->id = id;
        this->name = name;
        this->restricted = restricted;
        this->fictional = fictional;
    }

    // Getter functions
    std::string get_id(){
        return id;
    }
    
    std::string get_name(){
        return name;
    }

    std::vector<Book> get_books(){
        return books;
    }

    bool is_restricted(){
        return restricted;
    }

    bool is_fictional(){
        return fictional;
    }
};