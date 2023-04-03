#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#define array_length 100
#define key_length 14
#define value_length 52


int hash(char key[]){
  int index =0;
  for (int i=0; i<key_length; i++){
    int seed = 54216;
    index = (index + (key[i] << 5) * seed) % array_length;
  }

  return index;
}


typedef struct Node {
  char key[key_length];
  char value[value_length];
  struct Node * next;
}Node;

Node * hashmap[array_length] = {0};

void createNode(char key[], char value[])
{
  Node * node = malloc(sizeof(Node));
  strcpy(node->key, key);
  strcpy(node->value, value);
  node->next = NULL;

  int array_index = hash(key);
  
  if (hashmap[array_index] == 0){
    hashmap[array_index] = node;
  }else{
    Node * current = hashmap[array_index]; 
    while(current->next != NULL){
    current = current->next;
    }
    current->next = node;
  }
}

Node * searchNode(char key[]){
  int array_index = hash(key);
  if(strcmp(key,hashmap[array_index]->key) == 0){
    return hashmap[array_index];
  }else{
    if (hashmap[array_index]->next == NULL){
      printf("O node com chave:\"%s\", não está na lista.\n",key);
      return NULL;
    }
    Node * current = hashmap[array_index];
    while (current->next != NULL){
      current = current->next;
      if(strcmp(current->key,key) == 0){
        return current;
      }
    }
    printf("O node com chave:\"%s\", não está na lista.\n",key);
    return NULL;
  }
}


int main(int argc, char const *argv[])
{
  createNode("BLA","testando");
  createNode("BLB","testando BLB");
  
  Node * BLA = searchNode("BLA");
  Node * BLB = searchNode("BLB");
  

  
  return 0;
}
