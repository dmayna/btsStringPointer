// btsStringPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string getData(void) { return data; };
	void setData(string inData) { data = inData; };
	Node * ptrRightChild;
	Node * ptrLeftChild;
	Node(void) :ptrRightChild{ NULL }, ptrLeftChild{ NULL } {};
private:
	string data;
};

class BinaryTree
{
public:
	Node * ptrRoot;
	bool isEmpty(void);
	void search(string key);
	void insert(string key);
	void remove(void);
	void postOrder(void);
	void preOrder(void);
	void inOrder(void);
	void levelOrder(void);
	int size(void) { return nodeCount; }
	BinaryTree() :nodeCount{ 0 }, ptrRoot{ NULL } {};

private:
	int  maxSize;
	int nodeCount;
	void insert(string key, Node * leaf);
	void remove(Node * leaf);
	bool search(string key, Node * leaf);
	void postOrder(Node * leaf);
	void levelOrder(Node * leaf);
	void inOrder(Node * leaf);
	void preOrder(Node * leaf);
};


bool BinaryTree::isEmpty()
{
	if (ptrRoot == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BinaryTree::insert(string key)
{
	if (ptrRoot == NULL)
	{
		ptrRoot = new Node;
		ptrRoot->setData(key);
	}
	else
	{
		insert(key, ptrRoot);
	}
	nodeCount++;
}


void BinaryTree::insert(string key, Node * leaf)
{
	if (key > leaf->getData())
	{
		if (leaf->ptrRightChild == NULL)
		{
			leaf->ptrRightChild = new Node;
			leaf->ptrRightChild->setData(key);
		}
		else
		{
			insert(key, leaf->ptrRightChild);
		}
	}
	if (key <= leaf->getData())
	{
		if (leaf->ptrLeftChild == NULL)
		{
			leaf->ptrLeftChild = new Node;
			leaf->ptrLeftChild->setData(key);
		}
		else
		{
			insert(key, leaf->ptrLeftChild);
		}
	}
}

void BinaryTree::remove()
{
	if (ptrRoot == NULL)
	{
		cout << "UNDERFLOW\n";
	}
	else
	{
		remove(ptrRoot);
		nodeCount--;
	}
}

void BinaryTree::remove(Node * leaf)
{
	// base case
	if (leaf == NULL)
	{
		return;
	}

	if (leaf->ptrLeftChild == NULL)// node with only one or no child
	{
		//leaf = NULL;
		delete(leaf);
		return;
	}
	else if (leaf->ptrRightChild != NULL)
	{
		//leaf = NULL;
		delete(leaf->ptrLeftChild);
		return;
	}
	else
	{
		if (leaf->ptrLeftChild->ptrLeftChild != NULL && leaf->ptrLeftChild->ptrRightChild != NULL) // fix for delete function
		{
			remove(leaf->ptrRightChild);
		}
		remove(leaf->ptrLeftChild);
	}
}

void BinaryTree::postOrder()
{
	if (ptrRoot == NULL)
	{
		cout << "Empty Tree!\n";
		return;
	}
	cout << "Post Order: ";
	postOrder(ptrRoot);
	cout << "\n";
}

void BinaryTree::postOrder(Node * leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	postOrder(leaf->ptrLeftChild);

	postOrder(leaf->ptrRightChild);

	cout << leaf->getData() << " ";
}

void BinaryTree::inOrder()
{
	if (ptrRoot == NULL)
	{
		cout << "Empty Tree!\n";
		return;
	}
	cout << "In Order: ";
	inOrder(ptrRoot);
	cout << "\n";
}

void BinaryTree::inOrder(Node * leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	inOrder(leaf->ptrLeftChild);

	cout << leaf->getData() << " ";

	inOrder(leaf->ptrRightChild);
}
void BinaryTree::preOrder()
{
	if (ptrRoot == NULL)
	{
		cout << "Empty Tree!\n";
		return;
	}
	cout << "Pre Order: ";
	preOrder(ptrRoot);
	cout << "\n";
}

void BinaryTree::preOrder(Node * leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	cout << leaf->getData() << " ";

	preOrder(leaf->ptrLeftChild);

	preOrder(leaf->ptrRightChild);
}

void BinaryTree::levelOrder()
{
	if (ptrRoot == NULL)
	{
		cout << "Empty Tree!\n";
		return;
	}
	cout << "Level Order: " << ptrRoot->getData() << " ";
	levelOrder(ptrRoot);
	cout << "\n";
}

void BinaryTree::levelOrder(Node * leaf)
{
	if (leaf->ptrLeftChild != NULL)
	{
		cout << leaf->ptrLeftChild->getData() << " ";
	}
	if (leaf->ptrRightChild != NULL)
	{
		cout << leaf->ptrRightChild->getData() << " ";
	}
	if (leaf->ptrLeftChild != NULL && leaf->ptrRightChild != NULL)
	{
		levelOrder(leaf->ptrLeftChild);
	}
}

void BinaryTree::search(string key)
{
	if (ptrRoot == NULL)
	{
		cout << "Empty Tree!\n";
		return;
	}
	else
	{
		if (ptrRoot->getData() == key)
		{
			cout << "Found " << key << " at" << " Root\n";
		}
		else if(search(key,ptrRoot))
		{
			cout << "Key Found\n";
		}
		else
		{
			cout << key << " not found in Tree\n";
		}
	}
}

bool BinaryTree::search(string key, Node * leaf)
{
	if (key == leaf->getData())
	{
		return true;
	}
	else if (key > leaf->getData())
	{
		search(key, leaf->ptrRightChild);
	}
	else if (key < leaf->getData())
	{
		search(key, leaf->ptrLeftChild);
	}
	else
	{
		return false;
	}
}

int main()
{
	cout << "Dylan Maynard \t 5-5-2018\n\n";
	BinaryTree bst;
	bst.insert("10");
	bst.insert("15");
	bst.insert("20");
	bst.insert("5");
	bst.insert("10");
	bst.inOrder();
	bst.search("20");
    return 0;
}


