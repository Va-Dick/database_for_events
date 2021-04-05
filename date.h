#pragma once
#include <iostream>

using namespace std;

class Date {
public:
  Date(){};
  Date(const int& year_, const int& month_, const int& day_);
  ostream& operator << (ostream &)const;
  bool operator < (const Date& date_2)const;
  bool operator <= (const Date& date_2)const;
  bool operator >= (const Date& date_2)const;
  bool operator > (const Date& date_2)const;
  bool operator == (const Date& date_2)const;
  bool operator != (const Date& date_2)const;
  const int year = 0;
  const int month = 0;
  const int day = 0;
};

Date ParseDate(istream&);

ostream& operator << (ostream& os, const Date& date_);
