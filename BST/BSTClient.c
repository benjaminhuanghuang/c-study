

//---------------------------------------------------------------------
// BSTClient.c
// Test client for Binary Search Tree ADT
//
// This is just an example, you will be doing a lot more tests!
//---------------------------------------------------------------------

#include "stdio.h"
#include "BST.h"

int main(int argc, char *argv[])
{

  BSTObj *T;

  T = NULL;

  printf("inserting a lot of nodes to build a tree \n");

  insert("1", &T);
  insert("4", &T);
  insert("5", &T);
  insert("2", &T);
  insert("3", &T);
  insert("7", &T);
  insert("8", &T);

  printf("inorder traverse == \n");
  inorderTraverse(stdout, T);
  printf("\n== after traverse ==\n ");

  // Test find
  int exist = find("a", T);
  if (exist)
    printf("\n== found\n ");
  else
    printf("\n== not found\n ");

  // Test treeHeight
  int height = treeHeight(T, 0);
  printf("\n== The height is %d.\n ", height);

  // Test copyTree
  BSTObj *Tcopy = copyTree(T);
  inorderTraverse(stdout, Tcopy);

  // Test makeEmpty
  makeEmpty(&T);
  inorderTraverse(stdout, T);
  return 0;
}
