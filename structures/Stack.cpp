/* this code is for the exercise 1 at chapter 8.5 in 
"c++ programming language - by Bjarne Stroustrup" */
#include <iostream>
typedef struct Node {
  Node(int d){
    data = d;
    prev = NULL;
    next = NULL;
  }
  int data;
  Node *next;
  Node *prev;
} Node;

 Node * current = NULL;
 Node * previous = NULL;



Node * createNode(int data){
  Node * newNode = new Node(data);
  if(!current){
    current = newNode;
  } else {
    previous = current;
    current = newNode;  
    newNode->prev = previous;
    newNode->prev->next = current;
  }
  return newNode;
}

void Pop(){
  std::cout << "last node: " << current->data << " is deleted" << std::endl;
  delete current;
  previous->next = NULL;
  current = previous;
  std::cout << "The new current node is: " << current->data << std::endl;
}

int main(int argc, char const *argv[])
{
  Node * root = createNode(50);
  Node * test = createNode(30);
  Pop();

  return 0;
}

