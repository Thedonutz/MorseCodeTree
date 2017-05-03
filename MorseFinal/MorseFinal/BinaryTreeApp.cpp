#include "Binary_Search_Tree.h"
#include "Morse.h"
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
	Binary_Search_Tree<Morse> morseTree;

	Morse nullSpot(' ', 50);
	Morse e('e', 29);									
	Morse t('t', 70);
	Morse i('i', 25);		
	Morse a('a', 40);					
	Morse n('n', 65);			
	Morse m('m', 80);
	Morse s('s', 22);
	Morse u('u', 27);
	Morse r('r', 33);
	Morse w('w', 44);
	Morse d('d', 53);
	Morse k('k', 68);
	Morse g('g', 74);
	Morse o('o', 88);
	Morse h('h', 1);
	Morse v('v', 24);
	Morse f('f', 26);
	Morse l('l', 31);
	Morse p('p', 42);
	Morse j('j', 48);
	Morse b('b', 51);
	Morse x('x', 55);
	Morse c('c', 66);
	Morse y('y', 69);
	Morse z('z', 72);
	Morse q('q', 76);	

	vector<Morse> morseData{ nullSpot, e, t, i, a, n, m, s, u, r, w, d, k, g, o, h, v, f, l, p, j, b, x, c, y, z, q };

	for (int i = 0; i < morseData.size(); i++)
		morseTree.insert(morseData[i]);
	
	cout << "Tree Height is " << morseTree.height() - 1 << endl; //It counts 0 as depth so -1 gives the actualy Node_Depth
	
	//Return Map of all values to show Morse for Tree Traversal.
	map<char, string> morseMap = morseTree.getMap();

	//Print out
	for (map<char, string>::iterator i = morseMap.begin(); i != morseMap.end(); i++) {
		cout << i->first << " : " << i->second << endl;
	}

	//String must be lower case. the function does not setToLowerCase.
	cout << morseTree.encode("hello world") << endl;

	//Double space for new Word.
	cout << morseTree.decode("**** **  **** **") << endl;

	system("pause");
	return 0;
}