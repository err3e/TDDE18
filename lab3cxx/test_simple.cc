#include "list.h"
#include <random>
using namespace std;

int main()
{
    Sorted_list list{1,2,4,5,6};
       
    cout << list[4] << endl;  
    cout << list[4] << endl;
    list.print();
    list.remove(2);
    list.print();
    list.remove(9);
    list.remove(6);
    list.remove(1);
    list.remove(5);
    list.remove(4);
    list.remove(1);
    list.print();
}