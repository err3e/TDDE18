#ifndef _LIST_H_
#define _LIST_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <initializer_list>

template <typename T>
class List
{
public:
  List();
  List(T input);
  List(std::initializer_list<T> init_list);
  ~List() { delete first; }
  void insert(T const &d);
  void write();
  //Copy constructor
  List(List<T> const &);
  //Move constructor
  List(List<T> &&);
  //Copy assign operator
  List<T> &operator=(List const &);
  //Move assign operator
  List<T> &operator=(List &&);
  

  using value_type = T;

private:
  class Link
  {
  public:
    Link(value_type const &d, Link *n)
        : data(d), next(n) {}
    ~Link() { delete next; }

    friend class List;

    static Link *clone(Link const *);

  private:
    value_type data;
    Link *next;
  };

  Link *first;

public:
  class Iterator
  {
  public:
    Iterator();
    Iterator(Link* link) : linkptr(link) {}

    T operator*();
    Iterator& operator++();
    std::ostream& operator<<(std::ostream& os);
    bool operator!=(Iterator it);
    bool operator==(Iterator it);
    friend class List;
    friend class Link;

  private:
    Link *linkptr;
  };
  Iterator begin();
  Iterator end();
  // Suitable place to add things...
};

template <typename T>
std::ostream& operator<<(std::ostream& os, List<T> list);

#include "template.tcc"
#endif
