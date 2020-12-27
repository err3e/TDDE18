#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <random>

class Sorted_list
{

private:
    class Node
    {
    public:
        int value{};
        Node *next{nullptr};

        void insert_rec(int &value);
        void print_next();
    };
    Node *first;

public:
    //Default constructor
    Sorted_list() : first{nullptr} {};
    //List constructor
    Sorted_list(std::initializer_list<int> init_list);
    //Copy constructor
    Sorted_list(Sorted_list const &original_list);
    //Copy assign operator
    Sorted_list &operator=(Sorted_list const &original_list);
    //Move constructor
    Sorted_list(Sorted_list &&original_list);
    //Move assign operator
    Sorted_list &operator=(Sorted_list &&original_list);
    //Destructor
    ~Sorted_list();

    //Returns true if the list is empty otherwise false
    bool is_empty();
    //Empties the list, including freeing memory, used in the destructor
    void clear_list();
    //Writes the entire list to a string
    std::string print_to_string();
    //Prints a string produced by print_to_string to cout
    void print();
    //Counts and returns the number of values in the list
    int count();
    //Inserts a value into the list, inserts the value in a sorted manner
    void insert(int);
    //Returns the first value in the list
    int get_value();
    //Returns and removes the first value in the list
    int pop();
    //Returns true if the lists are identical
    bool operator==(Sorted_list &list);
    //Retrives the value of a given index
    int operator[](int);
    //Removes the first occurence of a given value
    void remove(int const value);
    //Returns the value of a given index
    int at(int const value);
};

Sorted_list get_list(Sorted_list list, int lower_bound = -50, int upper_bound = 50, int number_of_inputs = 100);

#endif