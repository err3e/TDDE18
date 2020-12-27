
#include "list.h"

template <typename T>
void List<T>::insert(T const &d)
{
  first = new Link(d, first);
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
  Iterator it{first};
  return it;
}


template <typename T>
typename List<T>::Iterator List<T>::end()
{
  Iterator it{nullptr};
  return it;
}

template <typename T>
T List<T>::Iterator::operator*()
{
  return linkptr->data;
}


template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{

    linkptr = linkptr->next;

  return *this;
}
 
template <typename T>
bool List<T>::Iterator::operator!=(Iterator it) 
{
  return !(*this == it); 
}

template <typename T>
bool List<T>::Iterator::operator==(Iterator it)
{
  return(this->linkptr == it.linkptr);
}

template <typename T>
std::ostream& List<T>::Iterator::operator<<(std::ostream& os)
{
  os << *this;
  return os; 
}

template <typename T>
std::ostream& operator<<(std::ostream& os, List<T> list)
{
  std::for_each(list.begin(), list.end(), [&os](const T val){os << val << " " ;});
    os << std::endl;
    return os; 
}

//-----------------------------------------------------//
// Important copy and assignment stuff
template <typename T>
typename List<T>::Link *List<T>::Link::clone(Link const *dolly)
{
  if (dolly != nullptr)
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

template <typename T>
List<T>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template <typename T>
List<T>::List(List const &l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

template <typename T>
List<T>::List(List &&l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

template <typename T>
List<T> &List<T>::operator=(List const &rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

template <typename T>
List<T> &List<T>::operator=(List &&rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}
