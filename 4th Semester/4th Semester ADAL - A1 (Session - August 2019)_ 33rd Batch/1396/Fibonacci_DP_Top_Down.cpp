#include<bits/stdc++.h>
using namespace std;

int mem[1000];

int fibo_td(int n)
{
    if(n==1 || n==2)
        mem[n]=1;
    else
        mem[n]=fibo_td(n-1) + fibo_td(n-2);

    return mem[n];
}

int main()
{
    int n;
    cout<<"enter a number:";
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<"fibo("<<i<<") = "<<fibo_td(i)<<"\n";
    return 0;
}
