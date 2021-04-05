#pragma once
#include "date.h"
#include <memory>
#include <string>

using namespace std;

enum Comparison{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum LogicalOperation{
	And,
	Or
};

class Node{
public:
	virtual bool Evaluate(const Date &date_, const string &event_)=0;
	virtual ~Node();
};

class EmptyNode: public Node{
public:
	bool Evaluate(const Date &date_, const string &event_) override;
};

class DateComparisonNode: public Node{
public:
	DateComparisonNode(const Comparison& comp_, const Date& date_): comp(comp_),date(date_){}
	bool Evaluate(const Date &date_ ,const string &event_) override;
	Comparison comp;
	Date date;
};

class EventComparisonNode: public Node{
public:
	EventComparisonNode(const Comparison& comp_, const string& event_): comp(comp_), event(event_){}
	bool Evaluate(const Date &date, const string &event_) override;
	Comparison comp;
	string event;
};

class LogicalOperationNode: public Node{
public:
	LogicalOperationNode(const LogicalOperation& op_, const shared_ptr<Node>& node_left_,
			shared_ptr<Node> node_right_):operation(op_),node_left(node_left_),node_right(node_right_){}
	bool Evaluate(const Date &date, const string& event_) override;
private:
	LogicalOperation operation;
	std::shared_ptr<Node> node_left;
	std::shared_ptr<Node>  node_right;
};
