#pragma once
#include "node.h"


template <class T>
class binaryTree
{

private:
	T data;
	Node <T> pParent;
	Node <T> pLeft;
	Node <T> pRight;

public:
	binaryTree()
	{
		pParent = NULL;
		pLeft = NULL;
		pRight = NULL;

	}

	binaryTree(T newItem)
	{
		data = newItem;
		pParent = NULL;
		pLeft = NULL;
		pRight = NULL;
	}


};