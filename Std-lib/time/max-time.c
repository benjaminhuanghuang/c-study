#include <stdio.h>
#include <time.h>

int main()
{
  time_t biggest = 0x7FFFFFFF;

  // ctime convert number to local time
  printf("biggest = %s \n", ctime(&biggest));

  // utc time
  printf("biggest(UTC) = %s \n", asctime(gmtime(&biggest)));

  return 0;
}