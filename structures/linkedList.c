#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node static * current;
struct Node
{
  /* data */
  int data;
  char text[20];
  struct Node * previous;
};
struct Node * createNode(int data, struct Node * previous){
    struct Node * node = malloc(sizeof(struct Node));
    node->data = data;
    node->previous = previous;
    char dataString[2];
    sprintf(dataString, "%d", data);
    char text[] = "string do node: ";
    strcpy(node->text,strcat(text,dataString));
    current = node;
    return node;
}
void searchNode(int data){
  int static i;
  struct Node * temp = current;
  while(temp){
    if(temp->data == data) {
      i = 0;
      printf("%s\n",temp->text);
      return;
    }else{
      i = 1;
      temp = temp->previous;
    }
  }
  if (i) printf("Não possui nenhum node com este valor\n");
  return;
}

int main(int argc, char const *argv[])
{
  /* code */
  struct Node * first = createNode(4,NULL);
  struct Node * second = createNode(2,first);
  struct Node * third = createNode(3,second);


  searchNode(2);
  
  return 0;
}
