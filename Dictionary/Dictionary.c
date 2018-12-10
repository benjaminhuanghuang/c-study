#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Dictionary.h"

// rotate_left()
// rotate the bits in an unsigned int
unsigned int rotate_left(unsigned int value, int shift)
{
	int sizeInBits = 8 * sizeof(unsigned int);
	shift = shift & (sizeInBits - 1);
	if (shift == 0)
		return value;
	return (value << shift) | (value >> (sizeInBits - shift));
}
// pre_hash()
// turn a string into an unsigned int
unsigned int pre_hash(char *input)
{
	unsigned int result = 0xBAE86554;
	while (*input)
	{
		result ^= *input++;
		result = rotate_left(result, 5);
	}
	return result;
}
// hash()
// turns a string into an int in the range 0 to tableSize-1
int hash(char *key, int tableSize)
{
	// printf("pre_hash(key) %d, table size %d \n",pre_hash(key), tableSize);
	return pre_hash(key) % tableSize;
}

HashTableObj *newHashTable(int size)
{
	HashTableObj *H;
	H = (HashTableObj *)malloc(sizeof(H->size) + sizeof(bucketList)*size);
	H->size = size;
	//	assert(H!=NULL);
	return H;
}

void deleteHashTable(HashTableObj *H)
{
	int i;

	if (H == NULL)
	{
		return;
	}
	//if (*H == NULL){
	//return;
	//}
	bucketListObj *next;

	if (H != NULL)
	{
		for (i = 0; i < H->size; i++)
		{
			if (H->bucket[i] != NULL)
			{
				while (H->bucket[i]->next != NULL)
				{
					next = H->bucket[i]->next;
					free(H->bucket[i]);
					H->bucket[i] = next;
				}
				next = H->bucket[i]->next;
				free(H->bucket[i]);
				H->bucket[i] = next;
			}
		}
		H->size = 0;
		free(H->bucket[i]);
		H->bucket[i] = NULL;
	}
}

bool member(HashTableObj *H, char *str)
{
	int i = hash(H, str);
	while (H->bucket[i] != NULL)
	{
		if (H->bucket[i]->item != str)
		{
			H->bucket[i] = H->bucket[i]->next;
		}
		else if (H->bucket[i]->item == str)
		{
			return true;
		}
	}
}

void insert(HashTableObj *H, char *str)
{
	// if (H == NULL)
	// {
	// 	fprintf(stderr, "ERROR\n");
	// 	exit(EXIT_FAILURE);
	// }
	// if (str == NULL)
	// {
	// 	fprintf(stderr, "ERROR");
	// 	exit(EXIT_FAILURE);
	// }
	bucketListObj *newNode = malloc(sizeof(int)+ strlen(str) + 1);
	// newNode->item = malloc(sizeof(strlen(str) + 1)); 
	// bucketListObj *newNode = malloc(sizeof(bucketListObj) + strlen(str) + 1);
	
	strcpy(newNode->item, str);
	
	// printf("The size of hashtable %d \n",H->size); 
	
	int i = hash(newNode->item, H->size);
	printf("hash value is %d\n",i);
	printf("H->bucket[i] is %d\n",H->bucket[i]);

	if(H->bucket[i] == 0)
	{
		printf("H->bucket[i] is null\n");
		H->bucket[i] = newNode;
		newNode->next = NULL;
	}
	else
	{
		bucketListObj *temp = H->bucket[i];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = NULL;
	}
}

/*for( i=0; i<H->size; i++){
	        if (H->bucket[i] == NULL){
		      //H->bucket[i]->item == temp;
	        	H->bucket[i] = temp;
	        	temp->next = NULL;

	        }else {
	            H->bucket[i]= temp;
	            temp->next = H->bucket[i]->next;			


	}
			}
}

*/

bool delete (HashTableObj *H, char *str)
{
	int i;

	bucketListObj *previous;

	i = hash(H, str);
	if (str == NULL || H == NULL)
	{
		return false;
	}

	while (strcmp(H->bucket[i]->item[i], str) != 0)
	{
		previous = H->bucket[i];
		H->bucket[i] = H->bucket[i]->next;
	}
	if (strcmp(H->bucket[i]->item[i], str) == 0)
	{
		H->bucket[i] = H->bucket[i]->next;
		free(previous);
	}
	else
	{
		previous->next = H->bucket[i]->next;
		free(H->bucket[i]);
	}
}

void printHashTable(FILE *out, HashTableObj *H)
{
	int i;
	bucketListObj *temp;

	for (i = 0; i < H->size; i++)
	{
		if (H->bucket[i] != NULL)
		{
			fprintf(stdout, "bucket %d\n", i);
			temp = H->bucket[i];
			while (temp != NULL)
			{
				printf("\tbucket list item = %s\n", temp->item);
				temp = temp->next;
			}
		}
	}
}
