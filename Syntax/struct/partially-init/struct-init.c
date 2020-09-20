#include <stdio.h>

int main()
{
  struct employee
  {
    char name[20];
    int age;
    float sal;
  };
  /*
    When and automatic structure is pratially initialised, 
    the remaining elements are initialised to 0.
  */
  struct employee e = {"Tiger"};

  printf("\n%d %f\n", e.age, e.sal);
}