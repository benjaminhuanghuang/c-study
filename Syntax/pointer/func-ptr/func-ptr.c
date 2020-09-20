
extern int fun();

int main()
{
  int(*p)() = fun;

  (*p)();
}


int fun(){
  return 0;
}