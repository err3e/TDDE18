#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;
// To do : 1.4
// To do : 5.5
int main()
{
    ifstream ifs{"data.txt"};
    string str{};
    int charCount{};       
    int totWords{};        
    int shortest{100};     
    string shortestWord{}; 
    int longest{};         
    string longestWord{};  

    //Läser innehållet i "data.txt"
    while (ifs >> str)
    {
        //Hitta det kortaste ordet
        if (str.length() < shortest)
        {
            shortest = str.length();
            shortestWord = str;
        }
        //Hitta det längsta ordet
        if (str.length() > longest)
        {
            longest = str.length();
            longestWord = str;
        }
        //Räknar antal bokstäver respk. antal ord.
        charCount += str.length();
        totWords++;
    }

    if (totWords == 0)
    {
        cerr << "Error: File Empty" << endl;
        return 0;
    }

    //Skriver ut statistiken.
    cout << "Antal bokstäver: " << charCount << endl;
    cout << "Antal ord: " << totWords << endl;
    cout << "Kortaste ordet var: '" << shortestWord << "' med '" << shortest << "' antal bokstäver." << endl;
    cout << "Längsta ordet var: '" << longestWord << "' med '" << longest << "' antal bokstäver." << endl;
    cout << "Den genomsnittliga längden var: " << static_cast<double>(charCount) / totWords << endl;
}
