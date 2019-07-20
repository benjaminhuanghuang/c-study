#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TABLE_SIZE (1024 * 1024)

/* element of the hash table's chain list */
struct kv
{
  struct kv *next;
  char *key;
  void *value;
};

/* HashTable */
struct HashTable
{
  struct kv **table;
};

/* constructor of struct kv */
static void init_kv(struct kv *kv)
{
  kv->next = NULL;
  kv->key = NULL;
  kv->value = NULL;
}

/* destructor of struct kv */
static void free_kv(struct kv *kv)
{
  if (kv)
  {
    kv->key = NULL;
    free(kv);
  }
}

/* the classic Times33 hash function */
static unsigned int hash_33(const char *key)
{
  unsigned int hash = 0;
  while (*key)
  {
    hash = (hash << 5) + hash + *key++;
  }
  return hash;
}

/* another hash function */
static unsigned int hash_string(const char *skey)
{
  const signed char *p = (const signed char *)skey;
  unsigned int h = *p;
  if (h)
  {
    for (p += 1; *p != '\0'; ++p)
      h = (h << 5) - h + *p;
  }
  return h;
}

/* new a HashTable instance */
HashTable *create_hash_table()
{
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  if (NULL == ht)
  {
    destruct_hash_table(ht);
    return NULL;
  }
  ht->table = malloc(sizeof(struct kv *) * TABLE_SIZE);
  if (NULL == ht->table)
  {
    destruct_hash_table(ht);
    return NULL;
  }
  memset(ht->table, 0, sizeof(struct kv *) * TABLE_SIZE);

  return ht;
}
/* destruct a HashTable instance */
void destruct_hash_table(HashTable *ht)
{
  if (ht)
  {
    if (ht->table)
    {
      int i = 0;
      for (i = 0; i < TABLE_SIZE; i++)
      {
        struct kv *p = ht->table[i];
        struct kv *q = NULL;
        while (p)
        {
          q = p->next;
          free_kv(p);
          p = q;
        }
      }
      free(ht->table);
      ht->table = NULL;
    }
    free(ht);
  }
}

/* insert or update a value indexed by key */
int hash_table_put(HashTable *ht, char *key, void *value)
{
  int i = hash_33(key) % TABLE_SIZE;
  struct kv *p = ht->table[i];
  struct kv *prep = p;

  while (p)
  { /* if key is already stroed, update its value */
    if (strcmp(p->key, key) == 0)
    {
      p->value = value;
      break;
    }
    prep = p;
    p = p->next;
  }

  if (p == NULL)
  { /* if key has not been stored, then add it */
    char *kstr = malloc(strlen(key) + 1);
    if (kstr == NULL)
    {
      return -1;
    }
    struct kv *kv = malloc(sizeof(struct kv));
    if (NULL == kv)
    {
      free(kstr);
      kstr = NULL;
      return -1;
    }
    init_kv(kv);
    kv->next = NULL;
    strcpy(kstr, key);
    kv->key = kstr;
    kv->value = value;
    
    if (prep == NULL)
    {
      ht->table[i] = kv;
    }
    else
    {
      prep->next = kv;
    }
  }
  return 0;
}

/* get a value indexed by key */
void *hash_table_get(HashTable *ht, char *key)
{
  int i = hash_33(key) % TABLE_SIZE;
  struct kv *p = ht->table[i];
  while (p)
  {
    if (strcmp(key, p->key) == 0)
    {
      return p->value;
    }
    p = p->next;
  }
  return NULL;
}

/* remove a value indexed by key */
void hash_table_rm(HashTable *ht, char *key)
{
  int i = hash_33(key) % TABLE_SIZE;

  struct kv *p = ht->table[i];
  struct kv *prep = p;
  while (p)
  {
    if (strcmp(key, p->key) == 0)
    {
      free_kv(p);
      if (p == prep)
      {
        ht->table[i] = NULL;
      }
      else
      {
        prep->next = p->next;
      }
    }
    prep = p;
    p = p->next;
  }
}
