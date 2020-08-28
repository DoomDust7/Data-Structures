#include<bits/stdc++.h>
using namespace std;

class DynamicArray
{
  int *arr;//array pointer
  int cap;//actual size
  int n;//no of elements
public:
  DynamicArray()
  {
    arr = new int[2];
    cap = 2;
    n = 0;
  }

  void push(int data)
  {
    if(n==cap)
    {
      int *temp = new int[2*cap];
      for(int i=0;i<cap;i++)
      {
        temp[i]=arr[i];
      }
      delete arr;
      arr=temp;
    }
    arr[n]=data;
    n++;
  }
  void push(int data,int index)
  {
    if(index==cap)
    {
      push(data);
    }
    else
    {
      arr[index]=data;
    }
  }
  void insertElement(int data,int index)
  {
    if(index==cap)
    {
      push(data);
    }
    for(int i=n-1;i>index;i++)
    {
      arr[i]=arr[i-1];
    }
    arr[index]=data;
    n++;
  }
  int pop()
  {
    int ele=arr[n-1];
    n--;
    return ele;
  }
  void pop(int index)
  {
    if(index<n)
    {
      n--;
      for(int i=index;i<n;i++)
      {
        arr[i]=arr[i+1];
      }
    }
  }
  int get(int index)
  {
    if(index<cap)
    {
      return arr[index];
    }
  }
  int length()
  {
    return n;
  }
  void print()
  {
    for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};
int main()
{
    DynamicArray a; // creating instance of the class.
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.insertElement(50, 2);
    cout<<"The array is: ";
    a.print();

    int ele = a.pop();// removing last element
    cout<<"Element Deleted: "<<ele<<endl;
    cout<<"The array after deletion is: ";
    a.print();

    a.pop(0);
    cout<<"The array after deleting index-0 element: ";
    a.print();

    cout<<"The size of array is: "<<a.length()<<endl;

    return 0;
 }
