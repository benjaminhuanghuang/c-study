#include <stdio.h>
#include <time.h>

int main()
{
  const char *weekday[] = {
      "Sunday", "Monday", "Tuesday", "Wednesday",
      "Thursday", "Friday", "Saturday"};

  const char *month[] = {
      "January", "February", "March", "April",
      "May", "June", "July", "August",
      "September", "October", "November", "December"};

  time_t now;
  time(&now);

  printf("\nThis is the Unix epoch, then seconds that have ticked since 1970-1-1: %ld\n\n", now);

  printf("The local time %s\n\n", ctime(&now));

  struct tm *timestamp;
  timestamp = localtime(&now);
  printf("The local time is %d:%02d:%02d\n", timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec);
  printf("Today is %s, %s %d %d\n\n",
         weekday[timestamp->tm_wday],
         month[timestamp->tm_mon],
         timestamp->tm_mday,
         timestamp->tm_year + 1900);


  struct tm *global_time;
  global_time = gmtime(&now);
  printf("The global time is %d:%02d:%02d\n\n", global_time->tm_hour, global_time->tm_min, global_time->tm_sec);
  return 0;
}