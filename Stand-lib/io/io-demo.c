#include <stdio.h>

void print2Stdout(FILE *out, char *message)
{
  fprintf(out, "%s\n", message);
}

int main(int argc, char *argv[])
{
  char *test = "test test test";
  print2Stdout(stdout, test);

  return 0;
}
