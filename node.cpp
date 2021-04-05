#include "node.h"

bool EmptyNode::Evaluate(const Date& date_ ,const string& event_){
	return true;
}

Node::~Node(){};

bool DateComparisonNode::Evaluate(const Date &date_ ,const string &event_){
	switch(comp){
	case Comparison::Less:
		return date_ < date;
	case Comparison::LessOrEqual:
		return date_ <= date;
	case Comparison::Greater:
		return date_ > date;
	case Comparison::GreaterOrEqual:
		return date_ >= date;
	case Comparison::Equal:
		return date_ == date;
	case Comparison::NotEqual:
		return date_ != date;
	}
	return false;
}

bool EventComparisonNode::Evaluate(const Date &date_,const string &event_){
	switch(comp){
	case Comparison::Less:
		return event_ < event;
	case Comparison::LessOrEqual:
		return event_ <= event;
	case Comparison::Greater:
		return event_ > event;
	case Comparison::GreaterOrEqual:
		return event_ >= event;
	case Comparison::Equal:
		return event_ == event;
	case Comparison::NotEqual:
		return event_ != event;
	}
	return false;
}

bool LogicalOperationNode::Evaluate(const Date& date_, const string& event_){
	switch(operation){
	case LogicalOperation::And:
		return node_left->Evaluate(date_, event_) && node_right->Evaluate(date_, event_);
	case LogicalOperation::Or:
		return node_left->Evaluate(date_, event_) || node_right->Evaluate(date_, event_);
	}
	return false;
}
