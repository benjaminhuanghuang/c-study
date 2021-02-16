#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lexicographic_sort(const char* a, const char* b) {
    int i=0;
    int j=0;
    while(a[i]&& b[j])
    {
      if(a[i] < b[j])
        return -1;
      if(a[i]>b[j])
        return 1;
      i++;
      j++;
    }
    if(a[i]){
        return 1;
    }
    if(b[j]){
        return -1;
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -lexicographic_sort(a, b);
}

int get_distinct_chars(const char *s){
  int count[26]={0};
  char c;
  int i=0;
  while(c=s[i++]){
    count[c-'a']++;
  }
  int n =0;
  for(int i=0;i < 26;i ++){
    if(count[i]){
      n++;
    }
  }
  return n;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int cmp = get_distinct_chars(a) - get_distinct_chars(b);
    if(cmp == 0)
    {
        return lexicographic_sort(a,b);
    }
    return cmp;
}

int get_length(const char *str){
  int length = 0;
  int i=0; 
  while(str[i++]){
    length++;
  }
  return length;
}
int sort_by_length(const char* a, const char* b) {
  int cmp= get_length(a) - get_length(b);
   if(cmp == 0)
    {
        return lexicographic_sort(a,b);
    }
    return cmp;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
  for(int i =0; i< len-1; i++)
  {
    for(int j = i+ 1; j< len; j++)
    {
      if(cmp_func(arr[i], arr[j]) > 0)
      {
        char *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}