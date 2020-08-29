#include "Trie.h"
#include "TrieNode.h"
#include<string>


Trie::Trie()
{
	root = new TrieNode('-');//initializing the root with "-"
}

Trie::~Trie()
{
	clear(root);
}

void Trie::clear(TrieNode * current)
{
	if (!current)
		return;

	for (int i = 0; i < 26; i++)
	{
		clear(current->kids[i]);
	}
	delete current;//at last deleting the node
}

void Trie::ins(TrieNode * r, string w)
{
	if (!r)//if r=NULL
		return;
	if (w == "")//if this is the end of the word
	{
		r->isEnd = true;
		return;
	}
		
	int index = w[0] - 97;
	if (r->kids[index])//if the node contains the same "prefix" (first letter identical)
	{
		w.erase(0,1);
		ins(r->kids[index], w);
	}
	else//from the rest of the word and on
	{
		r->kids[index] = new TrieNode(w[0]);//after same prefix, alocating the different letter in a new trie node
		r->kids[index]->parent = r;
		if (r->isLeaf)//if till now it was a leaf
			r->isLeaf = false;
		w.erase(0, 1);
		ins(r->kids[index], w);
	}
}

bool Trie::srch(TrieNode * r, string w)
{
	if (!r)
		return false;
	if (!((w[0] > 96) || (w[0] < 123)))//if there are only small letters at the string, a-z
		return false;
	int index = w[0] - 97;
	if (r->kids[index])//if the node contains the same "prefix" (first letter identical)
	{
		w.erase(0, 1);
		if (w.size() == 0)//if this is the end of the word = empty string
		{
			if (r->kids[index]->isEnd == true)//avoiding cases such short words which stored in long ones, and are not part of the vocabulary
				return true;
			return false;
		}

		return srch(r->kids[index], w);//recursive calling
	}
	else
	{
		return false;
	}
}



void Trie::insert(string word)
{
	ins(root, word);
}

TrieNode* Trie::findP(TrieNode * r, string w)
{
	if (!r)
		return NULL;

	int index = w[0] - 97;
	if (r->kids[index])//if the node contains the same "prefix" (first letter identical)
	{
		w.erase(0, 1);//deleting the first letter
		if (w.size() == 0)//if this is the end of the word = empty string
		{
			return (r->kids[index]);
		}
		return findP(r->kids[index], w);
	}
	else
	{
		return NULL;
	}
}

void Trie::wordP(TrieNode * r, string w)
{
	//string temp = w;//prefix
	if (!r)
		return;

	for (int i = 0; i < 26; i++)
	{
		if (r->kids[i])//if the node has kids
		{
			w += (r->kids[i]->Letter);
			if (r->kids[i]->isEnd)
			{
				 cout << w << endl;
			}
			wordP(r->kids[i],w);
			w.erase(w.size() - 1);
		}
	}
}

TrieNode* Trie::del(TrieNode * r, string w)
{
	if (!r)
		return NULL;

	int index = w[0] - 97;
	if (r->kids[index])//if the node contains the same "prefix" (first letter identical)
	{
		w.erase(0, 1);//deleting the first letter
		if (w.size() == 0)//if this is the end of the word = empty string
		{
			if (r->kids[index]->isEnd == true)//avoiding cases such short words which stored in long ones, and are not part of the vocabulary
			{
				return (r->kids[index]);
			}
		}
		return del(r->kids[index], w);
	}
	else
	{
		return NULL;
	}
}
bool Trie::deleteWord(string word)
{
	if (!search(word))//if the word is not at the tree
		return false;

	TrieNode* ll = del(root, word);// ll= last letter of the specific word
	TrieNode* p = ll->parent;
	while (p != root)
	{
		if (ll->isLeaf)
		{
			char c = ll->Letter;
			delete ll;
			ll = NULL;
			p->kids[c - 97] = NULL;
			ll = p;//updating the pointers to the same node
			p = ll->parent;// going backwards. p is the parent of ll.
			ll->isLeaf = true;
			for (int i = 0; i < 26; i++)
			{
				if (ll->kids[i])//in case there are different children
				{
					ll->isLeaf = false;
					break;
				}
			}
		}
		else
		{
			ll-> isEnd = false;
			return true;
		}
	}
	if (p == root)
	{
		return true;
	}
}

bool Trie::search(string word)
{
	return srch(root, word);
}

int Trie::printAutoSuggestions(string prefix)
{
	TrieNode* temp = findP(root, prefix);
	if (temp->isEnd)
		cout << prefix << endl;

	wordP(temp, prefix);
	if (temp == NULL)
		return 0;
	else
		return 1;
}
