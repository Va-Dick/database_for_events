#include "date.h"
#include <iostream>
#include <iomanip>
#include <tuple>
#include <exception>
#include <sstream>

Date::Date(const int& year_, const int& month_, const int& day_): year(year_), month(month_), day(day_){
	stringstream ss;
	if(!(year >= 0 && year <= 9999)){
		ss << "Error, invalid date format, year = " << year_;
		throw invalid_argument(ss.str());
	}
	if(!(month >= 1 && month <= 12)){
		ss << "Error, invalid date format, month = " << month_;
		throw invalid_argument(ss.str());
	}
	if(!(day >= 1 && day <= 31)){
		ss << "Error, invalid date format, day = " << day_;
		throw invalid_argument(ss.str());
	}
}

bool Date::operator < (const Date& date_2)const{
	return tie(year, month, day)<tie(date_2.year, date_2.month, date_2.day);
}

bool Date::operator <= (const Date& date_2)const{
	return tie(year, month, day)<=tie(date_2.year, date_2.month, date_2.day);
}

bool Date::operator > (const Date& date_2)const{
	return tie(year, month, day)>tie(date_2.year, date_2.month, date_2.day);
}

bool Date::operator >= (const Date& date_2)const{
	return tie(year, month, day)>=tie(date_2.year, date_2.month, date_2.day);
}

bool Date::operator != (const Date& date_2)const{
	return tie(year, month, day)!=tie(date_2.year, date_2.month, date_2.day);
}

bool Date::operator == (const Date& date_2)const{
	return tie(year, month, day)==tie(date_2.year, date_2.month, date_2.day);
}
ostream& operator << (ostream& os, const Date& date_){
	os << setfill('0') << setw(4) << date_.year << '-'
			 << setw(2) << date_.month << '-' << setw(2) << date_.day;
	return os;
}

Date ParseDate(istream& is){
	int year_, month_, day_;
	stringstream ss;
	is >> year_;
	if(is.get()!='-'){
		ss << "Error, the date haven't ' - '";
		throw invalid_argument(ss.str());
	}
	is >> month_;
	if(is.get()!='-'){
		ss << "Error, the date haven't ' - '";
		throw invalid_argument(ss.str());
	}
	is >> day_;
	Date date(year_, month_, day_);
	return date;
}
