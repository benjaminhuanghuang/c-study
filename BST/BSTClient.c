

//---------------------------------------------------------------------
// BSTClient.c
// Test client for Binary Search Tree ADT
// 
// This is just an example, you will be doing a lot more tests!
//---------------------------------------------------------------------

#include "stdio.h"
#include "BST.h"

int main(int argc, char* argv[]){

    BSTObj  *T;
    
    T = NULL;

    printf("inserting a lot of nodes to build a tree \n");
    insert("a", &T);
    insert("b", &T);
    insert("z", &T);
    insert("t", &T);
    insert("h", &T);
    insert("m", &T);
  
    insert("s", &T);

    printf("inorder traverse == \n");
    inorderTraverse(stdout, T);
    printf("\n== after traverse ==\n ");

   
  return 0;
}
