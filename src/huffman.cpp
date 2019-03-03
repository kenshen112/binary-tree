/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "vector.h"        // for VECTOR container
#include "pair.h"          // for PAIR container
#include "huffman.h"       // for HUFFMAN() prototype

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;

template <class T>
void readFile(const string & filename, vector <T> & tree1);

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
   //two vectors, of BNodes holding pairs
   vector <BNode *> huff_tree;
   vector <BNode *> hold_order;

   //read the file
   readFile(fileName, huff_tree);
   hold_order = huff_tree;
   
   return;
}

template <class T>
void readFile(const string & filename, vector <T> & tree1)
{
   //why are we passing both trees to readFile?
   //shouldn't the file only contain one tree??
   pair <string, float> data1;
   
   ifstream fin (filename);
   while(!fin.eof())
   {
      fin >> data1; //not sure
      tree1.push_back(data1); //not sure
   }

   fin.close();
   return;
}
}
