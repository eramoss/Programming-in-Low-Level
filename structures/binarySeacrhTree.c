#include <stdlib.h>
#include <stdio.h>

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



int main(int argc, char const *argv[]){

  Node *  root = NULL;
  root = createNode(root, 50);
  Node * node = createNode(root, 100);
  Node * child = createNode(root, 32);

  Node * test = Search(root, 33);

  return 0;
}
 