#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <istream>
#include <string>

struct Time
{
	int HH{};
	int MM{};
	int SS{};
};

std::string getfullTime(Time);
bool is_valid(Time const &time);
std::string to_string(Time const &time);
std::string to_string(Time const &time, char p);
bool is_am(Time const &time);
Time operator+(Time const &time, int integer);
Time operator-(Time const &time, int integer);
bool operator==(Time const &time1, Time const &time2);
Time setTime(Time &time, int HH, int MM, int SS);
Time operator++(Time &time);
Time operator++(Time &time, int);
Time operator--(Time &time);
Time operator--(Time &time, int);
bool operator!=(Time const &time1, Time const &time2);
bool operator>(Time const &time1, Time const &time2);
bool operator<(Time const &time1, Time const &time2);
std::ostream &operator<<(std::ostream &os, Time const &time);
std::istream &operator>>(std::istream &is, Time &time);
bool operator>=(Time const &time1, Time const &time2);
bool operator<=(Time const &time1, Time const &time2);
#endif