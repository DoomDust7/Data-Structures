#include<iostream>
#include<cstdlib>
#define SIZE 128

using namespace std;

class Stack {
  int top;
  int *arr;

public:
  Stack(){
    top = -1;
    arr = new int[SIZE];
  }

  void push(int data){
    if(top >= SIZE - 1){
      cout<<"Overflow of Stack!"<<endl;
      return;
    }
    top++;
    arr[top] = data;
  }

  int pop(){
    if(top == -1){
      cout<<"Underflow of Stack!"<<endl;
      return 0;
    }
    int data = arr[top];
    top--;
    return data;
  }

  int peek(){
    return arr[top];
  }

  void display(){
    if(top>=0){
      cout<<"The elements of the Stack are :"<<endl;
      for(int i = top;i>=0;i--){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
    else{
      cout<<"Stack is empty! Insert elements to display them!"<<endl;
    }
  }

};

int main(){
  Stack s;
  s.push(10);
  s.push(15);
  s.push(25);
  s.push(100);
  cout<<s.pop()<<endl;
  cout<<s.peek()<<endl;
  s.display();
  return 0;
}
