#include <stdarg.h>     // va_list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000
int  sum (int count,...) {
    va_list ap;
    int i, sum;

    va_start (ap, count);         /* Initialize the argument list. */

    sum = 0;
    for (i = 0; i < count; i++)
        sum += va_arg (ap, int);    /* Get the next argument value. */

    va_end (ap);                  /* Clean up. */
    return sum;
}
