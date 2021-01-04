#include<iostream>
#include<cstdlib>

using namespace std;

class Node{
public:
  int data;
  Node *next;
};

class Queue{
  Node *last , *first;
  int n;
public:
  Queue(){
    last = NULL;
    first = NULL;
    n = 0;
  }

  void prepend_start(int ele){
    Node *newNode = new Node;
    newNode->data = ele;
    newNode->next = NULL;
    if(first == NULL){
      first = newNode;
      last = newNode;
      n++;
      return;
    }

    newNode->next = last;
    last = newNode;
    n++;
  }

  void delete_element(){
    if(first == NULL){
      cout<<"Queue is empty!"<<endl;
      return;
    }
    Node *temp = last;
    for(int i = 1;i<n-1;i++){
      temp = temp->next;
    }
    cout<<temp->data<<endl;
    free(temp->next);
    n--;
    temp->next = NULL;
    first = temp;
  }

  void display(){
    if(first == NULL){
      cout<<"Queue is empty!"<<endl;
      return;
    }
    Node *temp = last;
    while(temp!=NULL){
      cout<<temp->data<<"-->";
      temp = temp->next;
    }
    cout<<endl;
  }
};

int main(){
  Queue q;
  q.prepend_start(5);
  q.prepend_start(15);
  q.prepend_start(25);
  q.prepend_start(35);
  q.delete_element();
  q.display();
  return 0;
}
