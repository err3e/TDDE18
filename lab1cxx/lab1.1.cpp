#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// To do : 1.4
int main()
{
    // Comment : good naming!
    int integer{};
    double real{};
    char character{};
    string word{};

    //Clears buffer and removes flag
    void reset_buffer(int max_char = {10000}, char new_line = {'\n'});

    //exmp 1
    cout << "Enter one integer: " << flush;
    cin >> integer;
    cout << "You entered the number: " << integer << endl;
    reset_buffer();

    //exmp 2
    cout << "\nEnter four integers: " << flush;
    cin >> integer;
    cout << "You entered the following numbers: " << integer;
    cin >> integer;
    cout << " " << integer;
    cin >> integer;
    cout << " " << integer;
    cin >> integer;
    cout << " " << integer << endl;
    reset_buffer();

    //exmp 3
    cout << "\nEnter one integer and one real number: " << flush;
    cin >> integer >> real;
    cout << fixed << setprecision(3) << "The real is: " << real << endl;
    cout << "The integer is: " << integer << endl;
    reset_buffer();

    cout << "\nEnter one real and one integer number: " << flush;
    cin >> real >> integer;
    cout << fixed << setprecision(3);
    cout << "The real is: " << real << endl;
    cout << "The integer is: " << integer << endl;
    reset_buffer();

    //exmp 4
    cout << "\nEnter a character: " << flush;
    cin >> character;
    cout << "You entered: " << character << endl;
    reset_buffer();

    //exmp 5
    cout << "\nEnter a word: " << flush;
    cin >> word;
    cout << "The word " << word << " has " << word.length() << " character(s)" << endl;
    reset_buffer();

    //exmp 6
    cout << "\nEnter an integer and a word: " << flush;
    cin >> integer >> word;
    cout << "You have entered '" << integer << "' and '" << word << "'." << endl;
    reset_buffer();
   
    //exmp 7
    cout << "\nEnter an character and a word: " << flush;
    cin >> character >> word;
    cout << "You have entered '" << character << "' and '" << word << "'." << endl;
    reset_buffer();
    
    //exmp 8
    
    cout << "\nEnter word and a real: " << flush;
    cin >> word >> real;
    cout << "You have entered '" << word << "' and '" << real << "'." << endl;
    reset_buffer();

    //exmp 9
    cout << "\nEnter a text-line: " << flush;
    getline(cin, word);
    cout << "You entered: " << word << endl;
    

    //exmp 10
    cout << "\nEnter a second line of text: " << flush;
    getline(cin, word, '\n');
    cout << "You entered: " << word << endl;
    
    //exmp 11
    cout << "\nEnter three words: " << flush;
    cin >> word;
    cout << "You entered: " << word << " ";
    cin >> word;
    cout << word << " " << flush;
    cin >> word;
    cout << word << endl;
    reset_buffer();
}

void reset_buffer(int max_char = 10000, char new_line = '\n')
{
    cin.ignore(max_char, new_line);
    cin.clear();
}