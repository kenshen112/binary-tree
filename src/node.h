#ifndef NODE_H
#define NODE_H
#include <iostream>

template <class T>
class Node
{
  public:
   T data;
   Node <T> *pNext;
   Node <T> *pPrev;

/************************
 * Default Constructor:
 * Create a NULL object.
 ***********************/
   Node()
   {
      pNext = nullptr;
      pPrev = nullptr;
   }  

/**********************************
 * Non Default Constructor:
 * create object with data in it.
 *********************************/  
   Node(T dat)
   {
      data = dat;
      pNext = nullptr;
      pPrev = nullptr;
   }
};

/**********************************
 * Create copy of Linked List.
 *********************************/
template<class T>
Node <T> *copy (Node <T> *pFront )
{
   Node <T> *copyNode = nullptr;
   Node <T> *tempNode = pFront;
   Node <T> *pHead = nullptr;
   bool first = true;
   do
   {
      if(first)
      {
         pHead = insert(tempNode->data, copyNode);
         copyNode = pHead;
         first = false;
         tempNode = tempNode->pNext;
      }
      else
      {
         insert(tempNode->data, copyNode, true);
         tempNode = tempNode->pNext;
         copyNode = copyNode->pNext;
      }
   } while (tempNode != nullptr);
   
   return pHead;
}

/***********************************
 * Insert:
 * A simple function that inserts into
 * various parts of the list as a whole.
 ***************************************/
template <class T>
Node <T>* insert(Node <T> *&pFront, T newItem, bool after = false)
{
   Node <T> *itemNode = new Node<T>(newItem); //making a new node
   
   if (pFront == nullptr)
   {
      pFront = itemNode;
      return pFront;
   }
   
   if(after)
   {
      //insert after the passed node
      // potentially three nodes involved. the one passed, the new node, the next node. they need to end in that order.
      // first set up the players, we have passed and new, get the next, ad if it is NULL, no biggy.
      
      Node <T> *temp = pFront->pNext;  //this represents what will come after the new one;
      
      //now we start changing pointers. starting with the passed one
      pFront->pNext = itemNode; //the referenced one points forward to the new one.
      
      //the new one need to point both the the passed one, and the next one
      itemNode->pPrev = pFront; //the new one points backward to the referenced one
      itemNode->pNext = temp; //the new one points forward to the next one
      
      //now it is possible that the next one soesn't exist and is NULL, if it is we are done, if not have it point back
      if(temp == nullptr)
      {
         return itemNode;
      }
      else
      {
         temp->pPrev = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
   }
   else
   {
      //insert before the passed node similar to the after insert, just different
      //so I need to identify the players again. we have pFront, which will be the back
      //   itemNode, will be in the middle, and temp will be in the front.
      Node <T> *temp = pFront->pPrev;
      
      //Now we start changing pointers, starting with pFront, which will be in back;
      pFront->pPrev = itemNode;

      //next is itemNode, which is in the middle,
      itemNode->pNext = pFront;
      itemNode->pPrev = temp;

      //Now we handle the case of the NULL pointer in temp.
      if(temp == nullptr)
      {
         return itemNode;
      }
      else
      {
         temp->pNext = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
      
   }
}
/**********************************
 * Insert:
 * A simple function that inserts into
 * various parts of the node as a whole.
 * This is an overload to the above class
 ***************************************/
template <class T>
Node <T>* insert(T newItem, Node <T> *&pFront, bool after = false)
{
   Node <T> *itemNode = new Node<T>(newItem); //making a new node

   if (pFront == NULL)
   {
      pFront = itemNode;
      return pFront;
   }
   
   if(after) //this was supposed to be a bool. need to rework this
   {
      //insert after the passed node
      // potentially three nodes involved. the one passed, the new node, the next node. they need to end in that order.
      // first set up the players, we have passed and new, get the next, ad if it is NULL, no biggy.
      
      Node <T> *temp = pFront->pNext;  //this represents what will come after the new one;
      
      //now we start changing pointers. starting with the passed one
      pFront->pNext = itemNode; //the referenced one points forward to the new one.
      
      //the new one need to point both the the passed one, and the next one
      itemNode->pPrev = pFront; //the new one points backward to the referenced one
      itemNode->pNext = temp; //the new one points forward to the next one
      
      //now it is possible that the next one soesn't exist and is NULL, if it is we are done, if not have it point back
      if(temp == nullptr)
      {
         return itemNode;
      }
      else
      {
         temp->pPrev = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
   }
   else
   {
      //insert before the passed node similar to the after insert, just different
      //so I need to identify the players again. we have pFront, which will be the back
      //   itemNode, will be in the middle, and temp will be in the front.
      Node <T> *temp = pFront->pPrev;
      
      //Now we start changing pointers, starting with pFront, which will be in back;
      pFront->pPrev = itemNode;

      //next is itemNode, which is in the middle,
      itemNode->pNext = pFront;
      itemNode->pPrev = temp;

      //Now we handle the case of the NULL pointer in temp.
      if(temp == nullptr)
      {
         return itemNode;
      }
      else
      {
         temp->pNext = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
      
   }
}

/***********************************************************************
 * ADD LEFT/RIGHTs:
 * Takes a pointer to a Node, and gives it a child, to the left or right
 * specified in the name of the function. one version is passed a T item
 * and makes a new node, the other is passed a node that is already made
 * and simply attaches it in the correct location
 **********************************************************************/
/*******************************************************************
*ADDLEFT, TEMPLATE
* This adsds a left hand child with the passed template data
********************************************************************/
template <class T>
void addLeft(BNode <T> *pNode, const T & t) throw (const char *)
{
   BNode <T> *itemNode = new Node<T>(t); //making a new node

   //and now we just set the pointers
   pNode->pLeft = itemNode; //the referenced one points forward to the new one.
      
   //the new one needs to point to the passed one
   itemNode->pParent = pNode; //the new one points backward to the referenced one  
}

/*******************************************************************
*ADDRIGHT, TEMPLATE
* This adsds a right hand child with the passed template data
********************************************************************/
template <class T>
void addLeft(BNode <T> *pNode, const T & t) throw (const char *)
{
	BNode <T> *itemNode = new Node<T>(t); //making a new node

	//and now we just set the pointers
	pNode->pRight = itemNode; //the referenced one points forward to the new one.

	//the new one needs to point to the passed one
	itemNode->pParent = pNode; //the new one points backward to the referenced one  
}

/*******************************************************************
*ADDRIGHT, NODE
* This adsds a right hand child with the passed Node pointer
********************************************************************/
template <class T>
void addLeft(BNode <T> *pNode, BNode <T> *pChild) throw (const char *)
{
	//and now we just set the pointers
	pNode->pRight = pChild; //the referenced one points forward to the new one.

	//the new one needs to point to the passed one
	pChild->pParent = pNode; //the new one points backward to the referenced one  
}

/*******************************************************************
*ADDLEFT, NODE
* This adsds a Left hand child with the passed Node pointer
********************************************************************/
template <class T>
void addLeft(BNode <T> *pNode, BNode <T> *pChild) throw (const char *)
{
	//and now we just set the pointers
	pNode->pLeft = pChild; //the referenced one points forward to the new one.

	//the new one needs to point to the passed one
	pChild->pParent = pNode; //the new one points backward to the referenced one  
}


/**************************************************
* SIZE
* returns an int of how many nodes there are in the tree
*****************************************************/
template <T>
int sizeBtree(BNode <T> *pNode)
{
   if(pNode == nullptr)
      return 0;
   else
      return (sizeBtree(pNode.pLeft) + 1 + sizeBtree(pNode.pRight));
}


/**********************************
* Remove:
* A simple function that removes an Node
***************************************/

template <class T>
Node <T>* remove(Node <T> *pRemove)
{
	Node <T>* pReturn;

	if (pRemove == nullptr)
	{
		return pRemove;
	}

	if (pRemove->pPrev != nullptr)
	{
		pRemove->pPrev->pNext = pRemove->pNext;
	}
	if (pRemove->pNext != nullptr)
	{
		pRemove->pNext->pPrev = pRemove->pPrev;
	}

	if (pRemove->pPrev != nullptr)
	{
		pReturn = pRemove->pPrev;
	}
	else
	{
		pReturn = pRemove->pNext;
	}

	delete pRemove;

	return pReturn;
}

/****************************************
 * Find:
 * Searches the linked list for an item.
 ***************************************/
template <class T>
Node <T> *find(Node <T> *pFront, T finding)
{
   if (pFront == nullptr)
   {
      return nullptr;
   }

   for (Node <T> *tempNode = pFront; tempNode; tempNode = tempNode->pNext)
   {
      if (tempNode->data == finding)
      {
         return tempNode;
      }
   }

   return NULL;
}


/************************************************************
 * << Operator:
 * This loops through the list and prints the items it finds
 *************************************************************/
template<class T>
std::ostream& operator<<(std::ostream &output, Node <T> *pFront)
{
   Node <T> *outputNode = pFront;
   while (outputNode != nullptr)
   {
      if (outputNode->pNext == nullptr)
      {
         output << outputNode->data;
      }

      else
      {
         output << outputNode->data << ", ";
      }
      outputNode = outputNode->pNext;
   }

   return output;
}

/*******************************************************************
 * freeData:
 * this loops through the list and deletes each node
 * by copying into two temp pointers one to loop through the nodes
 * and the other to free them both are assigned to each other then
 * outside the loop pFront is assigned the NULL value each time.
 ******************************************************************/
template <class T>
void freeData(Node <T> *&pFront)
{
   Node <T> *deleteNode = nullptr;
   Node <T> *tempNode = deleteNode = pFront; //i dont understand this line
   while(tempNode != nullptr)
   {
      deleteNode = tempNode;
      tempNode = tempNode->pNext;
      delete deleteNode;
   }

   pFront = tempNode;
}
   
#endif /* NODE_H */
