#include <iostream>
#include <string>
#include "Trie.h"
#include "TrieNode.h"

using namespace std;


int main()
{

	char ch;
	string wrd;
	Trie tr;
	int comp;

	cout << "\nTRIE PROGRAM" << endl;
	cout << "\nChoose one of the following" << endl;
	cout << "1: add a new item" << endl;
	cout << "2: delete an item" << endl;
	cout << "3: check if an item exists " << endl;
	cout << "4: complete the possible item name " << endl;
	cout << "5: exit " << endl;
	do
	{
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "Enter a word to insert " << endl;
			cin >> wrd;
			tr.insert(wrd);
			break;
		case '2':
			cout << "Enter a word to del " << endl;
			cin >> wrd;
			if (!tr.deleteWord(wrd)) cout << "ERROR\n";
			break;
		case '3':
			cout << "Enter a word to search " << endl;
			cin >> wrd;
			if (tr.search(wrd))
				cout << "exists\n";
			else
				cout << "does not exist\n";
			break;

		case '4':
			cout << "Enter a prefix to complete " << endl;
			cin >> wrd;
			comp = tr.printAutoSuggestions(wrd);

			if (comp == 0)
				cout << "No string exist with this prefix\n";
			break;
		case '5':cout << "bye " << endl; break;
		default: cout << "ERROR " << endl;  break;
		}//switch
	} while (ch != '5');


	//system("pause");
	return 0;
}/*
 TRIE PROGRAM

Choose one of the following
1: add a new item
2: delete an item
3: check if an item exists
4: complete the possible item name
5: exit
1
Enter a word to insert
app
1
Enter a word to insert
apply
1
Enter a word to insert
apple
2
Enter a word to del
apple
4
Enter a prefix to complete
app
apply
4
Enter a prefix to complete
ap
app
apply
3
Enter a word to search
app
exists
3
Enter a word to search
ap
does not exist
5
bye
Press any key to continue . . .

 
 */