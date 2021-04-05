#pragma once
#include "date.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <sstream>

#pragma once

using namespace std;

class Database {
public:
	Database() {};
	void Add(const Date&, const string&);

	void Find(const Date&) const;

	void Print(ostream&) const;

	string Last(const Date&) const;

	template<typename T>
	vector<string> FindIf(T func)const{
		vector<string> find_out;
		for (auto& now: database){
			Date date = now.first;
			for(auto now_2: now.second){
				if (func(date, *now_2)){
					stringstream s;
					s << now.first << " " << *now_2;
					find_out.push_back(s.str());
				}
			}
		}
		return find_out;
	}

	template<typename M>
	int RemoveIf(M Func){
		int number_dell = 0;
		vector<Date> list_dell;
		for(auto it_1 = database.begin(); it_1 != database.end(); ++it_1){
			Date date_ = it_1->first;
			auto it_2 = stable_partition(database[date_].begin(), database[date_].end(), ///rfwrghkthgkuwrhtgui5
								[&](auto str){
				bool a = Func(date_, *str);
				if(a == 1){
					number_dell++;
					database_set[date_].erase(*str);
				}
				return !a;});
			if((it_2 != database[date_].begin())){
				database[date_].erase(it_2, database[date_].end());

			}
			else{
				list_dell.push_back(date_);
			}
		}
		for(auto it_1 = list_dell.begin(); it_1 != list_dell.end(); ++it_1){
			database.erase(*it_1);
			database_set.erase(*it_1);
		}
		return number_dell;
	}
private:
	map<Date, vector<set<string>::iterator>> database;
	map<Date, set<string>> database_set;
};
