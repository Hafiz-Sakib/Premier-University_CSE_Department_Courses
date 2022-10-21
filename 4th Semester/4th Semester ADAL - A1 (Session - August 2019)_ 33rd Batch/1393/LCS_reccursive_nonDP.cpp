/**
 * mohsin riad [1393]
 * LCS using recursion (Top Down approach)
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char A[] = "ECDGI";
char B[] = "ABCDEFGHIJ";

int Max(ll x, ll y);
int LCS_rec(ll i,ll j);

int main()
{
    cout<<"LCS is: "<<LCS_rec(0,0)<<endl;
    return (0);
}

int LCS_rec(ll i,ll j)
{
    if(A[i]=='\0' || B[j]=='\0') return 0;
    else if(A[i] == B[j]) return 1+LCS_rec(i+1, j+1);
    else return Max(LCS_rec(i+1,j), LCS_rec(i,j+1));
}

int Max(ll x, ll y)
{
    return (x > y)? x:y;
}
