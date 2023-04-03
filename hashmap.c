#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#define array_length 100
#define key_length 14
#define value_length 52


int hash(char key[]){ // function hash returns a nem integer as a fingerprint of key
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

Node * hashmap[array_length] = {0}; // array to contain nodes

void createNode(char key[], char value[])
{
  Node * node = malloc(sizeof(Node));
  strcpy(node->key, key);
  strcpy(node->value, value); /* initialize node */
  node->next = NULL;

  int array_index = hash(key);
  printf("Index of node with key:%s\nis %d\n",key ,array_index);
  
  if (hashmap[array_index] == 0){
    hashmap[array_index] = node;
  }else{
    if (strcmp(hashmap[array_index]->key,key) == 0) { /* verify if this node has key that already exists */
      printf("Error: The node should'nt have been this key. Already exists\n");
      return;
    }
    Node * current = hashmap[array_index]; 
    while(current->next != NULL){ /* walks to linked list until pointer next is null */
    current = current->next;
    }
    current->next = node; /* put the node in last item of linked list */
  }
}

Node * searchNode(char key[]){
  int array_index = hash(key);
  if(strcmp(key,hashmap[array_index]->key) == 0){ // compare key of first item
    return hashmap[array_index];
  }else{
    if (hashmap[array_index]->next == NULL){ // verify if the node has a next item
      printf("Error: The node with key:\"%s\", it's not on list.\n",key);
      return NULL;
    }
    Node * current = hashmap[array_index];
    while (current->next != NULL){ /* walks to linked list until pointer next is null */
      current = current->next;
      if(strcmp(current->key,key) == 0){
        return current; // return the node with key correctly
      }
    }
    printf("Error: The node with key:\"%s\", it's not on list.\n",key); // Error if key is not on list
    return NULL;
  }
}


int main(int argc, char const *argv[])
{
  createNode("v1","value of node 1");
  createNode("v2","value of node 2");
  createNode("v3","value of node 3");
  
  Node * first = searchNode("v1");
  Node * second = searchNode("v2");
  Node * third = searchNode("v3");
  
  printf("%s\n%s\n%s\n",first->value,second->value,third->value);
  
  return 0;
}
