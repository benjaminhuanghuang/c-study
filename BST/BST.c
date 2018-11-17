#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "BST.h"

typedef BSTObj *BST;

void insert(char *new_data, BSTObj **pBST)
{
  if (new_data == NULL)
  { //if there is empty in the given data;
    return;
  }
  if (*pBST == NULL)
  { // if the first node is empty, then insert.

    BST new_node;                                          //create a node
    new_node = malloc(sizeof(BSTObj));                     // create a space for this node
    new_node->term = malloc(sizeof(strlen(new_data) + 1)); // to create space for string ?
    strcpy(new_node->term, new_data);                      //to copy the given data into term.

    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    *pBST = new_node; // to let the pointer point to new_node.

    return; // return the root node
  }

  int i = strcmp(new_data, (*pBST)->term);

  if (i < 0)
  {                                        // if the given data is less than the data in the current node
    insert(new_data, &(*pBST)->leftChild); // insert the data the left, why it's not *new_data?
  }
  if (i > 0)
  {                                         // if the given datat is bigger than teh data int the current node
    insert(new_data, &(*pBST)->rightChild); // insert the data to the right
  }
}

void inorderTraverse(FILE *out, BSTObj *T)
{
  if (T != NULL)
  {
    inorderTraverse(out, T->leftChild);
    fprintf(out, "%s, ", T->term);
    inorderTraverse(out, T->rightChild);
  }
}

void preorderTraverse(FILE *out, BSTObj *T)
{
  if (T != NULL)
  {
    fprintf(out, "%s, ", T->term);
    preorderTraverse(out, T->leftChild);
    preorderTraverse(out, T->rightChild);
  }
}

void postorderTraverse(FILE *out, BSTObj *T)
{
  if (T != NULL)
  {
    postorderTraverse(out, T->leftChild);
    postorderTraverse(out, T->rightChild);
    fprintf(out, "%s\n", T->term);
  }
}

// print the leaves of the tree in inorder to OUT
void inorderLeaves(FILE *out, BSTObj *T)
{
  if (T == NULL)
  { //if node is empty, return
    return;
  }
  if (T->leftChild == NULL && T->rightChild == NULL)
  { //if node is leaf node, print its data
  }
}

// return TRUE if the item_to_find matches a string stored in the tree
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
    return TRUE;
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
BSTObj *copyTree(BSTObj *T)
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
}

// remove all the nodes from the tree, deallocate space and reset Tree pointer
void makeEmpty(BSTObj **pT)
{
   if (*pT == NULL)
    return;

  makeEmpty(&(*pT)->leftChild);
  makeEmpty(&(*pT)->rightChild);

  free(*pT);
}
