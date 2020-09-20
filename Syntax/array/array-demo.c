#include <stdio.h>

int main()
{
  /*
    When and automatic array is pratially initialised, 
    the remaining array elements are initialised to 0.
  */
  int a[5] = {2, 3};

  printf("\n%d %d %d\n", a[2], a[3], a[4]);
}