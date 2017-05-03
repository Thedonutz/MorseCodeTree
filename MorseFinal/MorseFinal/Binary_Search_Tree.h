#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Binary_Tree.h"
#include "BTNode.h"
#include "Morse.h"
#include <map>
using namespace std;

template<typename Item_Type>
class Binary_Search_Tree : public Binary_Tree<Item_Type>
{
public:
	// Constructor
	Binary_Search_Tree() : Binary_Tree<Item_Type>() {}

	// Public Member Functions
	virtual bool insert(Morse& item);

	const Item_Type* min() const;

	const Item_Type* min(BTNode<Item_Type>* local_root) const;

	const Item_Type* max() const;

	const Item_Type* max(BTNode<Item_Type>* local_root) const;

	const Item_Type* find(const Item_Type& target) const;

	string decode(const string& item);
	string decode(BTNode<Morse>*& local_root, const string& coded_message);

	string encode(const string& message);

	map<char, string> morseMap;
	map<char, string> getMap() { return morseMap; }

private:

	// Private Member Functions
	virtual bool insert(BTNode<Morse>*& local_root,
		Morse& item);

	const Item_Type* find(BTNode<Item_Type>* local_root,
		const Item_Type& target) const;

	virtual void replace_parent(
		BTNode<Item_Type>*& old_root,
		BTNode<Item_Type>*& local_root);

}; // End binary search tree

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::min() const {
	return min(this->root);
		
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::min(BTNode<Item_Type>* local_root) const{
	if (local_root == NULL)
		return NULL;

		if (local_root->left == NULL)
			return &(local_root->data);
		 return min(local_root->left);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::max() const {
	return max(this->root);

}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::max(BTNode<Item_Type>* local_root) const{
	if (local_root == NULL)
		return NULL;

		if (local_root->right == NULL)
			return &(local_root->data);
		return max(local_root->right);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::find(
	const Item_Type& item) const {
		return find(this->root, item);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::find(BTNode<Item_Type>* local_root, const Item_Type& target) const {
		if (local_root == NULL)
			return NULL;
		if (target < local_root->data)
			return find(local_root->left, target);
		else if (local_root->data < target)
			return find(local_root->right, target);
		else
			return &(local_root->data);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(Morse& item) {
		return insert(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(BTNode<Morse>*& local_root,Morse& item) 
{
		if (local_root == NULL && item.getLetter() == ' ') 
		{
			morseMap[item.getLetter()] = " ";
			local_root = new BTNode<Item_Type>(item);
			return true;
		}
		else if (local_root == NULL)
		{
			morseMap[item.getLetter()] = item.getCode();
			local_root = new BTNode<Item_Type>(item);
			return true;
		}
		else 
		{
			if (item.getData() < local_root->data.getData())
			{
				item.setCode("*");
				return insert(local_root->left, item);
			}
			else if (local_root->data.getData() < item.getData())
			{		
				item.setCode("-");
				return insert(local_root->right, item);
			}
			else
				return false;		
		}
}

template<typename Item_Type>
void Binary_Search_Tree<Item_Type>::replace_parent(BTNode<Item_Type>*& old_root, BTNode<Item_Type>*& local_root) {
		if (local_root->right != NULL) {
			replace_parent(old_root, local_root->right);
		}
		else {
			old_root->data = local_root->data;
			old_root = local_root;
			local_root = local_root->left;
		}
}

template<typename Item_Type>
string Binary_Search_Tree<Item_Type>::decode(const string& item) {
	return decode(this->root, item);
}

template<typename Item_Type>
string Binary_Search_Tree<Item_Type>::decode(BTNode<Morse>*& local_root, const string& coded_message)
{
	string result;
	BTNode<Morse>* current_tree = local_root;
	for (size_t i = 0; i < coded_message.length(); i++) {
		if (coded_message[i] == '-') 
		{
			current_tree = current_tree->right;	
			if (coded_message[i+1] == ' ' || coded_message.length() == (i + 1))
			{
				char data = current_tree->data.getLetter();
				result += data;
				current_tree = local_root;	
			}				
		}
		else if (coded_message[i] == '*')
		{
			current_tree = current_tree->left;
			if (coded_message[i + 1] == ' ' || coded_message.length() == (i +1))
			{
				char data = current_tree->data.getLetter();
				result += data;
				current_tree = local_root;
			}			
		}
		else if (coded_message[i] == ' ' && coded_message[i+1] == ' ')
			result += ' ';
	}
	return result;
}

template<typename Item_Type>
std::string Binary_Search_Tree<Item_Type>::encode(const string& message)
{
	string encodedMessage;
	for (const char& code : message)
	{
		encodedMessage += morseMap.find(code)->second;
	}
	return encodedMessage;
}

#endif