#pragma once
#include "node.h"


template <class T>
class BNode
{

private:
	T data;
	Node <T> pParent;
	Node <T> pLeft;
	Node <T> pRight;

public:
	BNode()
	{
		pParent = NULL;
		pLeft = NULL;
		pRight = NULL;

	}

	BNode(T newItem)
	{
		data = newItem;
		pParent = NULL;
		pLeft = NULL;
		pRight = NULL;
	}


		BNode operator>>(const Node <T> display);
        BNode <T> copyBTree(BNode <T> source);
        void deleteBTree(BNode <T> node);
};

/******************************************
 * COPY
 *Copies one binary Tree into another
*****************************************/
template <class T>
BNode <T>::BNode <T> copyBTree(BNode <T> source)
{
   if(source == NULL)
   {
      return;
   }

   BNode destination = new BNode(source.data);

   
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
void deleteBTree(BNode <T> node)
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
BNode <T>::BNode<T> operator>>(const Node <T> display)
{

}
