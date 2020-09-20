#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

typedef struct graph_node
{
  char dna[4];
  struct graph_node  **leftChild;  
} graph_node;

graph_node *contructGraph(char *filename)
{
    ///open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File open error!\n");
        return NULL;
    }
    HashTable* hashtable = create_hash_table();
    graph_node* node= (struct graph_node *)malloc(sizeof(struct graph_node));

    destruct_hash_table(hashtable);
    fclose(fp);
    return node;
}
/*
  Running
  ./pa4 3 input.txt output.txt
 */
int main(int argc, char **argv)
{
    if (argc < 3)
    {
      printf("Please give k, input file and output file.\n");
      exit(1);
    }
    int k = atoi(argv[1]);
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];

    printf("k is %d, input file is %s, output file is %s \n", k,  inputFileName, outputFileName);
}
