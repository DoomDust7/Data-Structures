#include<iostream>
#include<cstdlib>
using namespace std;

class Node  { // each node
public:
    int data;
    Node *next;
};

class LinkedList {
  Node *tail;
  Node *head;
  int n;
public:
  LinkedList(){
    head = NULL;
    tail = NULL;
    n = 0;
  }
  void append_end(int ele)
  { // inserting at the end of the list , O(1) TC
    Node *newNode = new Node; //allocate memory
    newNode->data = ele; // filling the data
    newNode->next = NULL; // initial link will be null as next will have no data

    if(head == NULL) //list is empty
    {
      head = newNode;
      tail = newNode;
      n++;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
      n++;
    }
  }
  void append_beg(int ele)
  { // inserting at the begining of the list , O(1) TC
    Node *newNode = new Node; //allocate memory
    newNode->data = ele; // filling the data
    newNode->next = NULL; // initial link will be null as next will have no data

    if(head == NULL)
    {
      head = newNode;
      tail = newNode;
      n++;
    }
    else
    {
      newNode->next = head;
      head = newNode;
      n++;
    }
  }
  void insertNode(int ele, int pos)
  { // inserting in between the nodes O(n) TC
    //pos = 0 means head node position
    if(pos<0)
    {
      cout<<"Cannot Insert Node at this position"<<endl;
      return;
    }
    if(pos==0) // if first position (head)
    {
      append_beg(ele);
    }
    else if(pos >= n)
    {
      append_end(ele);
    }
    else
    {
      Node *newNode = newNode;
      Node *prev = head;
      newNode->data = ele;
      newNode->next = NULL;
      for(int i=0;i<pos-1;i++)
      {
        prev = prev->next;
      }
      newNode->next = prev->next;
      prev->next = newNode;
      n++;
    }
  }

  void deleteNode(int pos)
  {
    //removing an element
    if(pos<1)
    {
      return;
    }
    else
    {
      if(pos>n)
      {
        cout<<"Cannot delete a Node"<<endl;
        return;
      }
      Node *temp = head;
      if(pos == 1)
      {
        head = head->next;
        free(temp);
        n--;
        return;
      }
      else
      {
        for(int i=0;temp!=NULL && i<pos-1;i++)
        {
          temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL)
        {
          return;
        }
        Node *next = temp->next->next;
        free(temp->next);
        temp->next = next;
        n--;
        return;
      }
    }
  }
  void display()
  {
    if(head == NULL)
    {
      cout<<"Pls insert an element before displaying"<<endl;
      return;
    }
    Node *temp = head;
    for(int i=0;i<n;i++)
    {
      cout<<temp->data<<"-->";
      temp = temp->next;
    }
    cout<<endl;
  }

};
int main()
{
    LinkedList l;
    l.append_beg(2);
    l.append_beg(5);
    l.append_beg(7);
    l.append_beg(8);
    l.append_end(10);
    l.insertNode(15,2);
    l.deleteNode(0);
    l.display();
    return 0;
}
