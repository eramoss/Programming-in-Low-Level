#include <stdio.h>
#include <stdlib.h>

void f3(char (*pointer_hello)[]){
  printf("from f3: %p\n",pointer_hello);
  return;
}

void f2(char (*pointer_hello)[]){
  printf("from f2: %p\n",pointer_hello);
  f3(pointer_hello);
  return;
}

void f1(char (*pointer_hello)[]){
  printf("from f1: %p\n",pointer_hello);
  f2(pointer_hello);
  return;
}


int main(int argc, char const *argv[])
{
  char hello[] = "hello world";
  char (*pointer_hello)[] = malloc(sizeof(hello)); // unique copy of string in Heap memory
  pointer_hello = &hello;
  f1(pointer_hello);
  /*
    The output of functions above will be like this:

     Console:
      from f1: 0x7ffdac9f39cc
      from f2: 0x7ffdac9f39cc
      from f3: 0x7ffdac9f39cc

    The & operator is equivalent to get a memory location of variable.
    In the functions above, the output not changes because, when i pass a pointer to (hello)
    to other function, C pass Location of variable in Heap.
  */
  return 0;
}
