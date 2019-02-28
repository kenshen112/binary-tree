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

copyBTree(binaryTree source)
{
   if(source == NULL)
   {
      return;
   }

   binaryTree destination = new binaryTree(source.data);

   
   destination.pLeft = copyBTree(source.pLeft);
   if(destination.pLeft != NULL)
   {
      destination.pLeft.pParent = destination;
   }

   destination.pRight = copyBTree(source.pRight);

   if(destination.pRight != NULL)
   {
      destination.pRight.pParent = destination;
   }

   return destination;

}
