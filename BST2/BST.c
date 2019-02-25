//Sandy Sang
//Zsang
//Assignment 3
//CMPS12B/M
/*
This file contains function to insert a tree, function to find a tree's height, 
functions to print out reorder inorder postorder, and function to makeEmpty.
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "BST.h"


typedef BSTObj *BST;
/*
// add a new node to the BST with value, must allocate space for string
// no duplicates, case insensitive comparison of ordering
// return 0 for successful insert, -1 if the term was already in the tree
*/
int insert(char *value, BSTObj **pT)
{
  if (value == NULL)
  { //if there is empty in the given data;
    return -1;
  }

  if (*pT == NULL)
  { // if the first node is empty, then insert.

    BST new_node;                                          //create a node
    new_node = malloc(sizeof(BSTObj));                     // create a space for this node
    new_node->term = malloc(sizeof(strlen(value) + 1)); // to create space for string ?
    strcpy(new_node->term, value);                      //to copy the given data into term.

    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    *pT = new_node; // to let the pointer point to new_node.

    return 0; // return the root node
  }

  int i = strcmp(value, (*pT)->term);

  if (i < 0)
  {                                        // if the given data is less than the data in the current node
    return insert(value, &(*pT)->leftChild); // insert the data the left, why it's not *new_data?
  }
  if (i > 0)
  {                                         // if the given datat is bigger than teh data int the current node
    return insert(value, &(*pT)->rightChild); // insert the data to the right
  }
}


// print the inorder traversal to out
void inorderTraverse(FILE *out, BSTObj *T)
{
  if (T != NULL)
  {
    inorderTraverse(out, T->leftChild);
    fprintf(out, "%s ", T->term);
    inorderTraverse(out, T->rightChild);
  }
}

// print the preorder traversal to out
void preorderTraverse(FILE *out, BSTObj *T)
{
  if (T != NULL)
  {
    fprintf(out, "%s ", T->term);
    preorderTraverse(out, T->leftChild);
    preorderTraverse(out, T->rightChild);
  }
}

// print the postorder traversal to out
void postorderTraverse(FILE *out, BSTObj *T)
{
  if (T != NULL)
  {
    postorderTraverse(out, T->leftChild);
    postorderTraverse(out, T->rightChild);
    fprintf(out, "%s", T->term);
  }
}

// print the only the leaves of the tree in order to OUT
/*void inorderLeaves(FILE *out, BSTObj *T)
{
  if (T == NULL)
  { //if node is empty, return
    return;
  }
  if (T->leftChild != NULL)
  { 
    inorderLeaves(out, T->leftChild);//
  }
  if(T->rightChild != NULL)
  {
    inorderLeaves(out, T->rightChild);
  }
  if (T->leftChild == NULL && T->rightChild == NULL)
  { //if node is leaf node, print its data
    fprintf(out, "%s", T->term);
  }
}*/

// return the node with the term case insensitive matching item_to_find, NULL if not found
int find(char *term_to_find, BSTObj *T)
{
  if (T == NULL)
    return FALSE;

  int i = strcmp(term_to_find, T->term);

  if (i > 0)
  {
    //term_to_find is bigger than T->term, search it in the right sub tree.
    return find(term_to_find, T->rightChild);
  }
  else if (i < 0)
  {
    //term_to_find is less than T->term, search it in the left sub tree.
    return find(term_to_find, T->leftChild);
  }
  else
  {
    return T->term;
  }
}

// compute the height of the tree
// call with height = 0 and root of tree
int treeHeight(BSTObj *T, int height)
{
  if (T == NULL)
    return height;

  int leftSubHeight = treeHeight(T->leftChild, height + 1);
  int rightSubHeight = treeHeight(T->rightChild, height + 1);

  if (leftSubHeight > rightSubHeight)
    return leftSubHeight;
  else
    return rightSubHeight;
}

// create and return a complete memory independent copy of the tree
/*BSTObj *copyTree(BSTObj *T)
{
  if(T == NULL)
    return NULL;

  BSTObj *leftSubTree = copyTree(T->leftChild);
  BSTObj *rightSubTree = copyTree(T->rightChild);

  BSTObj *new_node = malloc(sizeof(BSTObj));                     // create a space for this node
  new_node->term = malloc(sizeof(strlen(T->term))); // to create space for string ?
  strcpy(new_node->term, T->term); 
  new_node->leftChild = leftSubTree;
  new_node->rightChild = rightSubTree;

  return new_node;
}*/

// remove all the nodes from the tree, deallocate space and reset Tree pointer
void makeEmpty(BSTObj **pT)
{
   if (*pT == NULL)
    return;

  makeEmpty(&(*pT)->leftChild);
  makeEmpty(&(*pT)->rightChild);

  free(*pT);
  *pT = NULL;
}
