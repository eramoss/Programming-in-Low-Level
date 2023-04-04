#include <stdlib.h>
#include <stdio.h>
#define array_size 100
#define max_lenght_number 2048
typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node * createNode(Node * root, int data){
  if (root == NULL){ // root is NULL, create a first instance of the node
    root = malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else {
    Node *current = root;
    while(1){ // infinite loop for walks through other nodes
      if (current->data > data){
        if (current->left == NULL) { // last node > data
          Node * newNode = malloc(sizeof(Node));
          newNode->data = data;
          newNode->left = NULL;
          newNode->right = NULL;
          current->left = newNode; // set this new node to the tree
          return newNode;
          break;
        } else {
          current = current->left; // advance left child
        }
      } else if (current->data < data) {
        if (current->right == NULL) { // last node < data
          Node * newNode = malloc(sizeof(Node));
          newNode->data = data;
          newNode->right = NULL;
          newNode->left = NULL;
          current->right = newNode; // add this new node to the tree
          return newNode;
          break;
        } else {
          current = current->right; // advance right child
        }
      } else {
        printf("ERROR: Invalid data, node cannot be inserted with same data of other nodes\n");
        return NULL;
        break;
      }
    }
  }
}

Node * Search(Node* root, int data){
  if (root == NULL){ // case tree is not initialized
    printf("Error: root cannot be NULL\n");
    return NULL;
  } else {
    Node *current = root;
    while(1){ // walk all nodes
      if (current->data == data){ // return current 
        return current;
      } else if (current->data > data){ 
        if (current->left == NULL) { // verify if current node is last in tree
          printf("Error: Node not found\n");
          return NULL;
        }
        current = current->left; // advance left pointer
      } else if (current->data < data){
          if (current->right == NULL) { // verify if current node is last in tree
          printf("Error: Node not found\n");
          return NULL;
        }
        current = current->right; // advance right pointer
      } else {
        printf("Error: Node not found\n");
        return NULL; // return an error message if any cases are encountered
      }
    }
  }
}


void printInOrder(Node* root){
  if (root) {
    printInOrder(root->left); // stack up until root is null
    printf("%d ", root->data); // stack down
    printInOrder(root->right); // stack up until root is null
  }
}



int main(int argc, char const *argv[]){

  Node *  root = NULL;
  int array[array_size];
  for(int i = 0; i < array_size; i++){
    array[i] = rand() % max_lenght_number; // random number generator populate array
  }

  for (int i=0; i < array_size; i++){
    if (i == 0) {
      root = createNode(root, array[i]);   // the array populate tree structure
    } else {
      Node * node = createNode(root,array[i]);
    }
  }

  printInOrder(root);
  printf("\n");

  return 0;
}
 