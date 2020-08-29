#pragma once
#include<string>
#include "TrieNode.h"
class Trie
{
public:
	TrieNode * root;

	Trie();//c-tor
	~Trie();//d-tor

	

	void insert(string word);//adding a new word to the tree 
	bool deleteWord(string word);//deleting a word from the tree
	bool search(string word);
	int printAutoSuggestions(string prefix);

private:
	void clear(TrieNode* current);//helper function the D-tor
	void ins(TrieNode * r, string w);//helper func to "insert" function
	bool srch(TrieNode * r, string w);//helper func to "search" function
	TrieNode* del(TrieNode* r, string w);//helper functo the "delete Node" function
	TrieNode* findP(TrieNode * r, string w);//helper func to print sub-prefix
	void wordP(TrieNode * r, string w);
};