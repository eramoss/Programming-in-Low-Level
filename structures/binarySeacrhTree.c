#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node * createNode(Node * root, int data){
  if (root == NULL){
    root = malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else {
    Node *current = root;
    while(1){
      if (current->data > data){
        if (current->left == NULL) {
          Node * newNode = malloc(sizeof(Node));
          newNode->data = data;
          newNode->left = NULL;
          newNode->right = NULL;
          current->left = newNode;
          return newNode;
          break;
        } else {
          current = current->left;
        }
      } else if (current->data < data) {
        if (current->right == NULL) {
          Node * newNode = malloc(sizeof(Node));
          newNode->data = data;
          newNode->right = NULL;
          newNode->left = NULL;
          current->right = newNode;
          return newNode;
          break;
        } else {
          current = current->right;
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
  if (root == NULL){
    printf("Error: root cannot be NULL\n");
    return NULL;
  } else {
    Node *current = root;
    while(1){
      if (current->data == data){
        return current;
      } else if (current->data > data){
        if (current->left == NULL) {
          printf("Error: Node not found\n");
          return NULL;
        }
        current = current->left;
      } else if (current->data < data){
          if (current->right == NULL) {
          printf("Error: Node not found\n");
          return NULL;
        }
        current = current->right;
      } else {
        printf("Error: Node not found\n");
        return NULL;
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
 