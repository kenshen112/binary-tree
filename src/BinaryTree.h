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


	}

	binaryTree(T newItem)
	{
		data = newItem;
		pParent = nullptr;
		pLeft = nullptr;
		pRight = nullptr;
	}


};