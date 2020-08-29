#include "DecisionTreeNode.h"
#include "ValidAnswer.h"

DecisionTreeNode * DecisionTreeNode::clear(DecisionTreeNode * a)// a help function for the d-tor
{
	//list <DecisionTreeNode *>::iterator it;//iterator
	auto it = a-> sons.begin();

	for (it; it != (a-> sons.end()); it++)
	{
		
	}
	delete a;
	return nullptr;
}

void DecisionTreeNode::add_answer(string a, string va)
{
	ValidAnswer * temp = new ValidAnswer(a, va);
	sons.push_back(temp);
}

DecisionTreeNode::DecisionTreeNode(string v)//constructor
{
	value = v;
}

DecisionTreeNode::~DecisionTreeNode()//destructor
{
	//using clear function(this)
}

void DecisionTreeNode::set_value(string val)//setter
{
	value = val;
}

string DecisionTreeNode::get_value()//getter
{
	return value;
}

void DecisionTreeNode::adding_leaf_or_node(string q, string ans, string val)
{

}
