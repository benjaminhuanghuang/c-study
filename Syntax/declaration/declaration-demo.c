/*
  Here display() is called before it is definde. 
  In such case the compiler assumes that function is declared as

    int display();

  Then when we defined the function, the compiler finds it
  is returning void hence the discrpancy.

*/


int main(){
  display();

  return 0;
}


void display(){
  return;
}