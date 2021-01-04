#include<iostream>
#include<cstdlib>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
  Node *top;
  int n;
public:
  Stack(){
    top = NULL;
    n = 0;
  }

  void push(int ele){
    Node *newNode = new Node;
    newNode->data = ele;
    newNode->next = NULL;
    if(top == NULL){
      n++;
      top = newNode;
      return;
    }
    newNode->next = top;
    top = newNode;
    n++;
  }

  void pop(){
    if(top == NULL){
      cout<<"UnderFlow!"<<endl;
      return;
    }
    Node *curr = top;
    cout<<top->data<<endl;
    top = top->next;
    free(curr);
    n--;
  }

  void display(){
    if(top == NULL){
      cout<<"Empty Stack!"<<endl;
      return;
    }
    Node *temp = top;
    for(int i = 0;i<n && temp!=NULL;i++){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};





int main()
{
  Stack s;
  s.push(2);
  s.push(3);
  s.pop();
  s.pop();
  s.display();
  return 0;
}
