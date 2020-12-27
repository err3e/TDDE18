/* #include "list.h"

using namespace std;

 int main()
{
    Sorted_list list{};
    list.insert(100);
    list.insert(200);
    list.print_list();
    //list.is_empty();
}

void Sorted_list::insert(int data)
{
    Node* tmp{new Node{data}};
    tmp->next = first;
    first = tmp; 
   // tmp->next = NULL; //Kommer ta bort firsts vidare pekare 
    tmp = nullptr;
}
            // NODE
//first -> [{} | / ]
//tmp -> [100 | / ]


//first -> [value | next ] - > [value | / ]
//tmp -> ^

//Returnerar true ifall first är en nullptr
bool Sorted_list::is_empty()
{   
    if (this->first)
    {
        //this->first = 1 
        return false; 
    } else {
        //this->first = 0 
        return true;
    }
}        

void Sorted_list::print_list()
{
    cout << (first->next->value) << endl; 
    //cout << this->first->next->value << endl;
 /*    if(this->first->next)
    {
        cout << "yas" << endl; 
        cout << this->first->value << endl; 
        this->first->next();
    } else if (!this->first->next)
    {
        cout << "noes" << endl; 
    } */
    //False om first är en nullptr 
    /* if(this->first)
    {
        cout << this->first->value;
    } */
