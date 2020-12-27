#include "list.h"

using namespace std;

bool Sorted_list::is_empty()
{
    return (this->first == nullptr);
}

int Sorted_list::operator[](int const value)
{
    int const size = this->count();
    Node *tmp{first};
    if (value >= size)
    {
        throw out_of_range("Out of range operator []");
    }
    for (int i = 0; i != value; i++)
    {
        if (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
    }
    return tmp->value;
}

int Sorted_list::at(int const value)
{
    return this->operator[](value);
}

void Sorted_list::remove(int const value)
{
    if(this->is_empty())
    {
        throw out_of_range("Removing in an empty list: Remove(value)");
    }
    int const size = this->count();
    Node *tmp{first};
    if (first->value == value)
    {
        first = first->next;
        delete tmp;
        return;
    }
    Node *del{tmp->next};
    while (tmp->next != nullptr)
    {
        if (tmp->next->value == value)
        {
            if (tmp->next->next != nullptr)
            {
                tmp->next = tmp->next->next;
                delete del;
                return;
            }
            else
            {
                delete tmp->next;
                tmp->next = nullptr;
                return;
            }
        }
        else
        {
            tmp = tmp->next;
        }
    }
    cerr << "Number not found in the list" << endl; 
}

void Sorted_list::insert(int value)
{
    if (first == nullptr || value < first->value)
    {
        Node *tmp{new Node{value}};
        tmp->next = this->first;
        this->first = tmp;
    }
    else
    {
        this->first->insert_rec(value);
    }
}
//Insert thinks one step ahead, otherwise the previous node will not connect to the new, as the one we're
//using is a copy of the previous pointer, not the actual pointer located in the node.
void Sorted_list::Node::insert_rec(int &value)
{
    if (this->next == nullptr)
    {
        Node *tmp_pointer{new Node{value}};
        this->next = tmp_pointer;
    }
    else if (this->next != nullptr && this->next->value > value)
    {
        Node *tmp_pointer{new Node{value}};
        tmp_pointer->next = this->next;
        this->next = tmp_pointer;
    }
    else
    {
        this->next->insert_rec(value);
    }
}

void Sorted_list::clear_list()
{
    Node *tmp{};
    while (this->first != nullptr)
    {
        tmp = this->first;
        if (this->first->next != nullptr)
        {
            this->first = this->first->next;
        }
        else
        {
            this->first = nullptr;
        }
        if (tmp != nullptr)
        {
            delete tmp;
        }
    }
}

Sorted_list get_list(Sorted_list list, int lower_bound, int upper_bound, int number_of_inputs)
{
    if (!list.is_empty())
    {
        list.clear_list();
    }
    default_random_engine generator;
    uniform_int_distribution<int> distribution(lower_bound, upper_bound);
    for (int i = 0; i != number_of_inputs; i++)
    {
        int value = distribution(generator);
        list.insert(value);
    }
    return list;
}

//Removes and returns the element last added.
int Sorted_list::pop()
{
    if (first != nullptr)
    {
        int tmp{first->value};
        Node *tmp_pointer = first;
        first = first->next;
        delete tmp_pointer;
        return tmp;
    }
    else
    {
        cerr << "was nullpointer" << endl;
        return 0;
    }
}

int Sorted_list::get_value()
{
    if (this->first != nullptr)
    {
        return this->first->value;
    }
    else
    {
        cerr << "was nullpointer" << endl;
        return 0;
    }
}

string Sorted_list::print_to_string()
{
    string str{};
    Node *tmp = this->first;
    int count = this->count();
    if (count == 0)
    {
        return "Empty list";
    }
    for (int i = 0; i < count; i++)
    {
        str += to_string(tmp->value);
        if (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        if (i != count - 1)
        {
            str += ", ";
        }
    }
    return str;
}

int Sorted_list::count()
{
    int count = 0;
    Node *tmp = this->first;
    while (tmp != nullptr)
    {
        count++;

        if (tmp->next != nullptr)
        {
            tmp = tmp->next;
            continue;
        }
        else
        {
            break;
        }
    }
    return count;
}

void Sorted_list::print()
{
    cout << this->print_to_string() << endl;
}

Sorted_list::Sorted_list(initializer_list<int> init_list)
{
    this->first = nullptr;
    for (int i : init_list)
    {
        this->insert(i);
    }
}

Sorted_list::Sorted_list(Sorted_list const &original_list)
{
    this->first = nullptr;
    this->operator=(original_list);
}

Sorted_list &Sorted_list::operator=(Sorted_list const &original_list)
{
    this->clear_list();
    Node *iterator_ptr = original_list.first;
    this->first = nullptr;
    while (iterator_ptr != nullptr)
    {
        this->insert(iterator_ptr->value);
        iterator_ptr = iterator_ptr->next;
    }
    return *this;
}

Sorted_list::Sorted_list(Sorted_list &&original_list)
{
    this->first = nullptr;
    *this = move(original_list);
}

Sorted_list &Sorted_list::operator=(Sorted_list &&original_list)
{
    swap(this->first, original_list.first);
    return *this;
}

Sorted_list::~Sorted_list()
{
    if (this->first != nullptr)
    {
        this->clear_list();
    }
}

bool Sorted_list::operator==(Sorted_list &list)
{
    Sorted_list tmp_1 = *this;
    if (tmp_1.first == nullptr && list.first == nullptr)
    {
        return true;
    }
    int count_1 = tmp_1.count();
    int count_2 = list.count();

    if (count_1 != count_2)
    {
        return false;
    }
    else
    {
        Node *tmp_1 = this->first;
        Node *tmp_2 = list.first;
        while (tmp_1->value == tmp_2->value)
        {
            if (tmp_1->next != nullptr)
            {
                tmp_1 = tmp_1->next;
                tmp_2 = tmp_2->next;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
}
