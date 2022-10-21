#include<bits/stdc++.h>
using namespace std;

int fibo_bu(int n)
{
    int fib[1000];
    fib[1] = fib[2] = 1;

    for(int i = 3 ; i <= n ; i++)
        fib[i] = fib[i-1] + fib[i-2];

    return fib[n];
}

int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;

    for(int i = 1 ; i <= n ; i++)
        cout<<"fibo("<<i<<") = " << fibo_bu(i)<<endl;

    return 0;
}
