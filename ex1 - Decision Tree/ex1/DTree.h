#pragma once
#include "DecisionTreeNode.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
class DTree
{
	DecisionTreeNode * root;//the root of the tree, will contain the first question

public:
	DTree();//default c-tor
	DTree(string q);//c-tor
	~DTree();//d-tor
	DecisionTreeNode * find_question(string str, DecisionTreeNode * curr, DecisionTreeNode * & father);//searching for a specific question at the tree and updates the father
	bool add_Node_Leaf(string q, string pa, string val);// pa = possible answer
};
