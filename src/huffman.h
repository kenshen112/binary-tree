/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/
#include "pair.h"
#include "bnode.h"
#include <string.h>

#ifndef HUFFMAN_H
#define HUFFMAN_H

void huffman(const std::string & fileName);

class huffman
{
   BNode <custom::pair <std::string, float > > * data;

};
#endif // HUFFMAN_H
