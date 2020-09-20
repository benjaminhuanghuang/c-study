#include <stdio.h>

int main()
{

  union a
  {
    int i;
    char ch[2];
  };

  union a u = {1};             // makes u.x active with value 1
  union a u2 = {.ch = {'\1'}}; // makes u2.c active with value {'\1','\0'}

  printf("\n%d %d\n", u.ch[0], u.ch[1]);

  printf("Memory size occupied by data : %lu\n", sizeof(u2));
}