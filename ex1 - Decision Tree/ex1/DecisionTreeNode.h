#pragma once
#include <iostream>
#include <string>
#include <list>
#include "ValidAnswer.cpp"
using namespace std;

class ValidAnswer;
class DecisionTreeNode// a node at a deciding tree
{
public:
	string value;//question or decision
	bool isLeaf;
	list <ValidAnswer *> sons; //list of pointers of "possible answer"
	DecisionTreeNode * clear(DecisionTreeNode * a);// a help function for the d-tor
	void add_answer(string a, string va);

//public:
	DecisionTreeNode(string);//constructor
	~DecisionTreeNode();//destructor

	void set_value(string val);//setter
	string get_value();//getter

	void adding_leaf_or_node(string q, string ans, string val);

	//DecisionTreeNode * find_question(string str);//searching for a specific question at the tree
};
