#include <bits/stdc++.h>
using namespace std;

void rev(string str)
{
    int n = str.size();
    char temp;
    for(int i=0;i<n/2;i++)
    {
        temp = str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=temp;
    }
}
void main()
{
    string s;
    cin>>s;
    rev(s);
}