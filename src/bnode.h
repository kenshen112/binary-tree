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


		binaryTree operator>>(const Node <T> display);
        binaryTree <T> copyBTree(binaryTree <T> source);
        void deleteBTree(binaryTree <T> node);
};

/******************************************
 * COPY
 *Copies one binary Tree into another
*****************************************/
template <class T>
binaryTree <T>::binaryTree <T> copyBTree(binaryTree <T> source)
{//^There is an error with this, gonna work more on it tomorrow, Jess 02/27
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
/*********************************************
 *DELETE
 * deletes each node of the binary tree
********************************************/
template <class T>
void deleteBTree(binaryTree <T> node)
{
   if(node == NULL)
   {
      return;
   }

   deleteBTree(node.pLeft); 
   deleteBTree(node.pRight);

   delete node;
}


/********************
* INPUT OPERATOR
*******************/
template <class T>
binaryTree <T>::binaryTree<T> operator>>(const Node <T> display)
{

}
