#include "DTree.h"
#include "DecisionTreeNode.h"
#include "ValidAnswer.h"

DTree::DTree()//default c-tor
{
	root = NULL;
}

DTree::DTree(string q)//c-tor
{
	root = new DecisionTreeNode(q);
}

DTree::~DTree()//d-tor
{
	if (root != NULL)
	{
		delete root;
	}

}

DecisionTreeNode * DTree::find_question(string str, DecisionTreeNode * curr, DecisionTreeNode * & father)//searching for a specific question at the tree and updates the father
{
	if (curr->value == str)
	{
		father = curr;//updates the father pointer
		return curr;//returning the right pointer
	}

	if (!curr || curr->value != str)//if there isn't a pointer or the node doesn't hold the question
		return NULL;

	list <ValidAnswer*>::iterator it;
	it = curr->sons.begin();
	DecisionTreeNode * temp = NULL;

	for (; it != curr->sons.end(); it++)//checking the rest of the list
	{
		if (((*it)->son->value) == str)
		{
			father = curr;
			return (*it)->son;
		}
		temp = find_question(str, (*it)->son, father);//keep searching it recursive way
	}
	return temp;
}

bool DTree::add_Node_Leaf(string q, string pa, string val)
{
	
	DecisionTreeNode * c;
	DecisionTreeNode * father = find_question(q, root, c);
	if (!father)
		return false;

	//ValidAnswer * temp = new ValidAnswer(pa, new DecisionTreeNode(val));
	//father->add_answer(pa, val);
	return true;
	
	//father->sons.push_back(temp);
	//father->isLeaf = false;//updating the new node to have sons
	//father->add_Node_Leaf ()
	//return true;

}

