###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother Kirby, CS235
# Author:
#     Ken Smith
#     Jessica Smith
#     Tim O'Barr
# Summary:
#     Implements a binary node, and uses it to makea huffman code
# Time:
#     Group: 11 hours
#     Solo:
#        Ken: 6 hours
#        Jessica: 4 hours
#        Tim: 5 hours
# Difficulties:
#     Ken: Stuck on the insertion operator for 6 hours
#     Jessica: understanding huffman codes
#     Tim: Stuck on the insertion operator for 6 hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o huffman.o
	g++ -o a.out assignment08.o -g -std=c++11
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h huffman.h assignment08.cpp
	g++ -c assignment08.cpp -g -std=c++11

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g -std=c++11
