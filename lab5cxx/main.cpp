#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<string> args(argv + 1, argv + argc + !argc);
    vector<string>::iterator it_a;
    vector<string>::iterator it_f;
    vector<string>::iterator it_oN;
    string file_name;

    if (args.size() == 0)
    {
        cerr << "Error: No arguments given" << endl;
        cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
    }

    if (args.size() == 1)
    {
        cerr << "Error: Second argument" << endl;
        cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
    }
    else
    {
        file_name = args[0];
        it_a = find(args.begin(), args.end(), "-a");
        it_f = find(args.begin(), args.end(), "-f");
        it_oN = find(args.begin(), args.end(), "-o");
    }

    vector<string> word_list{};

    ifstream ifs(file_name);
    istream_iterator<string> it_begin(ifs);
    istream_iterator<string> it_end{};

    copy(it_begin, it_end, back_inserter(word_list));
    vector<string> clean_list{word_list.size()};

    //Hittar den första karaktären som inte har en av de oönskade startvärdena.
    //Ta bort alla ord mellan starten och precis innan det första önskade värdet. 
    //Gör likadant för den sista, vi går även där från begin och inkrementerar iteratorn till vår sista önskade bokstav. Vi tar bort mellan den sista önskade + 1, till slutet. 
    //I båda fallen ovan måste vi kolla ifall vi får npos, som indikerar att vi inte funnit en karaktär som vi letar efter. 
    //Vi kollar sedan på de två sista karaktärerna och ser ifall de är "'s", ifall detta stämmer tar vi bort den delen. 
    //Vi gör om alla karaktärer till lowercase. 
    transform(word_list.begin(), word_list.end(), clean_list.begin(), [](string word) {
        int first_character = (word.find_first_not_of("\"\'(") == string::npos) ? 0 : word.find_first_not_of("\"\'(");
        word.erase(word.begin(), word.begin() + first_character);
        int last_character = ((word.find_last_not_of("!?;,:.\"\'") == string::npos) ? 0 : word.find_last_not_of("!?;,:.\"\'") + 1);
        word.erase(word.begin() + last_character, word.end());
        if (word.substr(word.size() - 2, word.size()) == "'s")
        {
            word.erase((word.end() - 2), word.end());
        }
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        return word;
    });

    vector<string> valid_list{clean_list.size()};

    //Kollar ifall alla karaktärer i ett ord är alfabetiska eller bindestreck. 
    auto alpha_or_hyphen = [](string word) { return all_of(word.begin(), word.end(), [](char c) -> bool { return (isalpha(c) != 0 || c == '-'); }); };

    //Kollar ifall ett ord är giltigt, med villkoren att ordet måste vara större eller lika med 3, inte ha några följande bindestreck, och bara innehåller alfabetiska karaktärer eller bindesteck. 
    auto is_valid_word = [&alpha_or_hyphen](string word) -> bool {
        return ((word.length() >= 3) && (word.find("--") == string::npos) && alpha_or_hyphen(word));
    };

    //Kopierar alla ord från vår tidigare rengjorda lista till en validerad lista om de passerar kraven som är deklarerade i is_valid_word.
    auto it = copy_if(clean_list.begin(), clean_list.end(), valid_list.begin(), [&is_valid_word](string word) -> bool {
        return is_valid_word(word);
    });
    //Ändrar storleken på vår validerade lista till att matcha mängden element mellan den första iteratorn och den sista, som vi har fått i retur från copy_if. 
    valid_list.resize(distance(valid_list.begin(), it));

    if (it_a != args.end())
        a(valid_list);
    if (it_f != args.end())
        f(valid_list);
    if (it_oN != args.end())
    {
        //Vi inkrementerar vår iterator med 1 för att använda den givna integern. 
        if (++it_oN != args.end())
        {
            o(valid_list, stoi(*it_oN));
        }
        else
        {
            cerr << "You need to supply a maximum amount of characters per row" << endl;
        }
    }
}


//Alfabetisk enl första bokstav p ord.
//Även räkna hur många av var ord det finns.
void a(vector<string> word_list)
{
    vector<string>::iterator findLongestWord = max_element(word_list.begin(), word_list.end(),
     [&word_list](string const& a, string const& b) {
        return (a.length() != b.length() ? a.length() < b.length() : a < b);
    });
    int longest_word_length = (*findLongestWord).length();

    map<string, int> map;
    sort(word_list.begin(), word_list.end());
    
    //Lägg in varje ord från vektorn till en map, och inkrementera dess value, som är en integer, och då kommer ge en räknare för antal förekomster.
    for_each(word_list.begin(), word_list.end(), [&map](string key) { map[key]++; });
   
    //Skriv ut hela map:en.
    for_each(map.begin(), map.end(), [&longest_word_length](pair<string, int> element) { cout << element.first << setw((longest_word_length + 5) - element.first.length() )<< element.second << endl; });
}

void f(vector<string> word_list)
{

    vector<string>::iterator findLongestWord = max_element(word_list.begin(), word_list.end(),
     [&word_list](string const& a, string const& b) {
        return (a.length() != b.length() ? a.length() < b.length() : a < b);
    });
    int longest_word_length = (*findLongestWord).length();
    map<string, int> map;
    //Samma som i a.
    for_each(word_list.begin(), word_list.end(), [&map](string key) { map[key]++; });
    vector<pair<string, int>> pair_vector{};
    //Lägg till som par i en vektor.
    for_each(map.begin(), map.end(), [&pair_vector](pair<string, int> element) { pair_vector.push_back(element); });
    //Sortera först efter vår integer, som är frekvensen på ordet, ifall de är lika sorterar vi i bokstavsordning.
    sort(pair_vector.begin(), pair_vector.end(), [](const pair<string, int> &x, const pair<string, int> &y) {
        return ((x.second != y.second) ? (x.second > y.second) : (x.first < y.first));
    });
    //Skriv ut hela vektorn med sorterade par.
    for_each(pair_vector.begin(), pair_vector.end(), [&longest_word_length](pair<string, int> word_int_pair) {
        cout << setw(longest_word_length) << word_int_pair.first << setw(3) << word_int_pair.second << endl;
    });
}

void o(vector<string> word_list, int n)
{
    
    int length = 0; 
    //Skriver maximalt antal ord som får plats inom N, med ett blanksteg inräknat. 
    auto print_max_line_length = [&length,&n, &word_list](string word){
     if(length + word.length() + 1 >= n)
        {
             cout << "\n";
            length = 0; 
        }
             cout << word + " " << flush;
             length += (word.length() + 1);
        
      };
    //Ta varje ord
    //Kör copy_if på den nya stringen, som är en sammansättning av de tidigare orden
    //Villkoret är att string length understiger N. (Det är inte detta som händer för tillfället, utan behöver skrivas.)
    for_each(word_list.begin(), word_list.end(), print_max_line_length);
    cout << "\n";
}
