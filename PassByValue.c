#include <stdio.h>

void f3(char hello[]){
  printf("from f3: %p\n",&hello);
  return;
}

void f2(char hello[]){
  printf("from f2: %p\n",&hello);
  f3(hello);
  return;
}

void f1(char hello[]){
  printf("from f1: %p\n",&hello);
  f2(hello);
  return;
}


int main(int argc, char const *argv[])
{
  char hello[] = "hello world";
  f1(hello);
  /*
    The output of functions above will be like this:

     Console:
      from f1: 0x7fffda5661a8
      from f2: 0x7fffda566188
      from f3: 0x7fffda566168 

    The & operator is equivalent to get a memory location of variable.
    In the functions above, the output changes because, when i pass variable (hello)
    to other function, C creates a copy of this variable.
  */
  return 0;
}
