/**
 * mohsin riad [1393]
 * LCS (dp approach)
**/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define Max(a,b) ((a)<(b)?(a):(b))

const ll N = 1e4;

string A = "ECDGI";
string B = "ABCDEFGHIJ";

int LCS_temp[N][N];
int print[N][N];

void display(ll a, ll b)
{
    if(a!=0 && b!=0)
    {
        if(print[a][b] == 1)
        {
            display(a-1,b-1);
            cout<<A[a-1]<<" ";
        }
        else if(print[a][b] == 2) display(a-1,b);
        else display(a,b-1);
    }
}

int LCS_rec(ll a,ll b)
{
    memset(LCS_temp,0,sizeof(LCS_temp));
    //memset(print,0,sizeof(print));

    for(ll i=1; i<=a ;i++)
        for(ll j=1; j<=b ;j++)
        {
            if(A[i-1] == B[j-1])
            {
                LCS_temp[i][j] = 1+LCS_temp[i-1][j-1];
                print[i][j] = 1;
            }
            else if(LCS_temp[i-1][j] >= LCS_temp[i][j-1])
            {
                LCS_temp[i][j] = LCS_temp[i-1][j];
                print[i][j] = 2;
            }
            else
            {
                LCS_temp[i][j] = LCS_temp[i][j-1];
                print[i][j] = 3;
            }
        }
    return LCS_temp[a][b];
}

int main()
{
    cout<<"LCS is: "<<LCS_rec(A.length(),B.length())<<endl;
    cout<<"sequence is: ";
    display(A.length(),B.length());
    return (0);
}
