#pragma once

#include <iostream>
#include <string>
#include <list>
#include "DecisionTreeNode.h"
using namespace std;

class DecisionTreeNode;
class ValidAnswer // class for "possible answer" to a question in decidng tree
{
public:
	string ans;
	DecisionTreeNode * son;

//public:
	ValidAnswer(string a, string s);//c-tor
	~ValidAnswer();//d-tor

	void set_ans();
	string get_ans();
};


ValidAnswer::ValidAnswer(string a, string s)//c-tor
{
	ans = a;//answer
	//son = new DecisionTreeNode(s);//creating new node which holds the answer
	son = new DecisionTreeNode(s);
}

ValidAnswer::~ValidAnswer()//d-tor
{
	//clear()
}
