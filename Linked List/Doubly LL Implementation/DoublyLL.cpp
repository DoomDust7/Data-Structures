#include<iostream>
#include<cstdlib>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;
};
class DoublyLinkedList {
  Node *head;
  Node *tail;
  int n;
public:
  DoublyLinkedList(){
    head = NULL;
    tail = NULL;
    n = 0;
  }
  void append_end(int ele)
  {
    Node *newNode = new Node;
    newNode->data = ele;
    newNode->next = newNode->prev = NULL;
    if(n == 0)
    {
      head = newNode;
      tail = newNode;
      n++;
    }
    else
    {
      tail->next = newNode;
      newNode->next= NULL;
      newNode->prev = tail;
      tail = newNode;
      n++;
    }
  }
  void prepend_start(int ele)
  {
    if(n==0){
      append_end(ele);
    }
    else{
      Node *newNode = new Node;
      newNode->data = ele;
      newNode->next = newNode->prev = NULL;

      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      n++;
    }
  }
  void insert_between(int ele , int pos){
    if(pos > n){
      cout<<"Too large"<<endl;
      return;
    }
    else if(pos < 1){
      cout<<"Negative position!"<<endl;
      return;
    }
    else if(pos == 1){
      prepend_start(ele);
    }
    else if(pos == n){
      append_end(ele);
    }
    else{
      Node *newNode = new Node;
      newNode->data = ele;
      newNode->next = newNode->prev = NULL;

      Node *temp = tail;
      for(int i=n-1;i>=pos;i--){
        temp = temp->prev;
      }

      newNode->next = temp;
      newNode->prev = temp->prev;
      temp->prev->next = newNode;
      n++;
    }
  }

  void delete_element(int pos){
    if(pos<1||pos>n){
      cout<<"Cannot delete"<<endl;
      return;
    }
    else{
      Node *temp = head;
      if(pos == 1){
        head = head->next;
        free(temp);
        n--;
        return;
      }
      for(int i=0;i<pos;i++){
        temp = temp->next;
      }
      if(temp!=NULL){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        n--;
      }
    }
  }

  void reverse_list(){
    Node *temp = NULL;
    Node *current = head;

    while(current!=NULL){
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if(temp!=NULL){ //edge case
      head = temp->prev;
    }
  }
  void display(){
    if(head == NULL){
      cout<<"UnderFlow"<<endl;
      return;
    }
    Node *temp = head;
    while(temp!=NULL){
      cout<<temp->data<<"---->";
      temp = temp->next;
    }
    cout<<"NULL"<<endl;
  }
};
int main()
{
    DoublyLinkedList d;
    d.prepend_start(2);
    d.append_end(3);
    d.display();
    return 0;
}
