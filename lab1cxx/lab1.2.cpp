#include <iostream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// To do : 1.4
// To do : 5.5

//Lab 1, deluppgift 2.
int main()
{
    double firstPrice{};
    double lastPrice{};
    double stride{};
    double tax{};

    //Tar bort flagga från cin och rensar buffer
    void reset_buffer(int max_char = {10000}, char new_line = {'\n'});

    cout << "INPUT PART \n"
         << "==========\n"
         << "Enter first price: " << flush;

    //Hämta första priset, med en errorhanterare för felaktiga värden.
    cin >> firstPrice;
    reset_buffer();
    while (firstPrice < 0 || firstPrice > 100000)
    {

        cerr << "First price must be at least 0 kr or max 100000\n";
        cout << "Enter first price : ";
        cin >> firstPrice;
        reset_buffer();
    }
   
    //Hämta sista priset med en while-loop som hanterar errors.
    cout << "Enter last price : " << flush;
    cin >> lastPrice;
    reset_buffer();
    while (lastPrice < firstPrice || lastPrice > 100000 || lastPrice < 0)
    {
        cerr << "Last price must be at least 0 kr, bigger than first price and max 100000\n";
        cout << "Enter last price  : ";
        cin >> lastPrice;
        reset_buffer();
    }

    //Hämta prispålägg med en while-loop som hanterar errors.
    cout << "Enter stride     : " << flush;
    cin >> stride;
    reset_buffer();
    while (stride < 0.01 || stride > (lastPrice - firstPrice))
    {
        cerr << "Stride must be at least 0.01 and smaller than the difference between last and first price\n";
        cout << "Enter stride  : ";
        cin >> stride;
        reset_buffer();
    }

    //Hämta skatten med en while-loop som hanterar errors.
    cout << "Enter tax        : " << flush;
    cin >> tax;
    reset_buffer();
    while (tax < 0 || tax > 60)
    {
        cerr << "The tax must be between 0-60\n";
        cout << "Enter tax  : ";
        cin >> tax;
        reset_buffer();
    }

    tax = tax / 100;

    cout << "TAX TABLE \n"
         << "=========\n"
         << "       Price            Tax          Price with tax\n"
         << setfill('-') << setw(51) << "" << setfill(' ') << endl;

    //En while-loop som skriver ut värdena i en tabell.
    int loop_count = (lastPrice - firstPrice) / stride; 
    for (int i = 0; i <= loop_count; i++) {
        cout << setw(12) << fixed << setprecision(2);
        cout << firstPrice << setw(15);
        cout << firstPrice * tax << setw(24);
        cout << tax * firstPrice + firstPrice << endl;
        firstPrice = firstPrice + stride;
    }
}

void reset_buffer(int max_char = {10000}, char new_line = {'\n'})
{
    cin.clear();
    cin.ignore(max_char, new_line);
}