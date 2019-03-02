###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother XXXXX, CS235
# Author:
#     <your name here>
# Summary:
#     <put a description here>
#     HUFFMAN HAS BEEN REMOVED, DO NOT FORGET TO PUT IT BACK
# Time:
#     <how long did it take to complete this program>?
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o 
	g++ -o a.out assignment08.o -g -std=c++11
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h assignment08.cpp
	g++ -c assignment08.cpp -g -std=c++11
###########################################
#huffman.o: bnode.h huffman.h huffman.cpp
#	g++ -c huffman.cpp -g -std=c++11
#########################################
