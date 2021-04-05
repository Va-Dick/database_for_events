#include "database.h"
#include <algorithm>
#include <iterator>
#include <sstream>

void Database::Add(const Date& date_, const string& event_) {
	if(event_.empty()) {
		return;
	}
	if (database_set.count(date_)) {
		auto it = database_set[date_].insert(event_);
		if (it.second) {
			database[date_].push_back(it.first);
		}
	} else {
		auto it = database_set[date_].insert(event_);
		database[date_].push_back(it.first);
	}
}

void Database::Print(ostream& os) const{
	for(const auto& now: database){
		for (const auto& now_2: now.second){
			os << now.first << " ";
			os << *now_2 << endl;
		}
	}
}

string Database::Last(const Date &date_) const{
	if(database.empty()){
		return("No entries");
	}
	auto it = database.upper_bound(date_);
	if(it != database.begin()){
		it--;
		auto it_2 = it->second.end();
		it_2--;
		stringstream ss;
		ss << it->first << " " << **it_2;
		return ss.str();
	}
	return("No entries");
}
