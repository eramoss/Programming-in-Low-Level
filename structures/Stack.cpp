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
 Node * root = NULL;
 int nodes;

Node * createNode(int data){
  Node * newNode = new Node(data);
  if(!current){
    current = newNode;
    root = newNode;
  } else {
    previous = current;
    current = newNode;  
    newNode->prev = previous;
    newNode->prev->next = current;
  }
  ++nodes;
  return newNode;
}

void Pop(){
  std::cout << "last node: " << current->data << " is deleted" << std::endl;
  delete current;
  previous->next = NULL;
  current = previous;
  std::cout << "The new current node is: " << current->data << std::endl;
}


static int length;
void Sort(){

  if(root->next){

    for(Node *curr = root; curr; curr = curr->next){
      for(Node *next = curr->next; next; next = next->next){
        if(curr->data > next->data){
          curr->data = curr->data + next->data; /*GAMBIARRA*/
          next->data = curr->data - next->data;
          curr->data = curr->data - next->data;
        }
      }
    }
    for(Node *curr = root; curr; curr = curr->next){
    std::cout << curr->data << std::endl;
    }

  return;
  } else return;
}

int main(int argc, char const *argv[])
{
  Node * test = createNode(7000);
  Node * test1 = createNode(60);
  Node * test2 = createNode(700);
  Node * test3 = createNode(50);
  Node * test4 = createNode(61);

  Sort();
  

  return 0;
}

