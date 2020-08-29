#pragma once
#include<iostream>
#include<string>

using namespace std;
class TrieNode
{
public:
	TrieNode * parent;//pointer to the father
	TrieNode * kids[26];//an array for the kids which contains pointers to another subtrees
	bool isEnd;//if this is the end of the word - avoiding cases such short words which stored in long ones, and are not part of the vocabulary
	bool isLeaf;
	char Letter;//letter

	TrieNode(char l)
	{
		Letter = l;//updating he letter
		isEnd = false;//it ain't the end of the word yet
		isLeaf = true;
		parent = NULL;
		for (int i = 0; i < 26; i++)//initializing wiht NULL
		{
			kids[i] = NULL;
		}
	}

	~TrieNode()//deleting a whole word inside the Trie class
	{

	}
};