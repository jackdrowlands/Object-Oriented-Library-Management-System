#include <iostream>
#include <string>
#include <vector>
#include "Entity.cpp"
using namespace std;

// Yet to add the add_book function?

class Author : public Entity {
    protected:
    string id;
    string name;
    vector<Book> books;
    string nationality;
    vector<string> aliases;

    public:
    Author(std::string id, std::string name, std::string nationality, std::vector<std::string>aliases){
        this->id = id;
        this->name = name;
        this->nationality = nationality;
        this->aliases = aliases;
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

    std::string get_nationality(){
        return nationality;
    }

    std::vector<std::string> get_aliases(){
        return aliases;
    }
};