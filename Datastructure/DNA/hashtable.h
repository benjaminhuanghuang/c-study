typedef struct HashTable HashTable;

/* create a  instance of HashTable */
HashTable *create_hash_table();

/*  
destruct a hashtable and remove all values are removed auotmatically.
*/
void destruct_hash_table(HashTable *ht);

/*
  put element to hashtable
 */
int hash_table_put(HashTable *ht, char *key, void *value);

/* 
get a value by key, return NULL if not found. 
*/
void *hash_table_get(HashTable *ht, char *key);

/* 
remove a value indexed by key 
*/
void hash_table_rm(HashTable *ht, char *key);
