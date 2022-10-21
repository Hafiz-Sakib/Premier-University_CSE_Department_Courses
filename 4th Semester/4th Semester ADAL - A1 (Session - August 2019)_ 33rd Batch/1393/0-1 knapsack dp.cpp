/**
 * mohsin riad [1393]
 * 0-1 Knapsack (dp approach)

test case :
4
5
2 3
3 4
4 5
5 6
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll v[N], wt[N];
ll c[N][N];

void knap(ll w,ll n)
{
    int i, j;
    for(i=0;i<=w;i++) c[i][0] = 0;
    for(j=1;j<=n;j++) c[0][j] = 0;
    ///memset(c,0,sizeof(c));
    for(i=1;i<=w;i++)
        for(j=1;j<=n;j++)
        {
            if(j >= wt[i])
            {
                if(c[i-1][j-wt[i]] + v[i] > c[i-1][j])
                    c[i][j] = c[i-1][j-wt[i]] +v[i];
                else
                    c[i][j] = c[i-1][j];
            }
        }
    ///testing
    /*cout<<"table :\n";
    for(i=0;i<=w;i++){
        for(j=0;j<=n;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
    */
    cout<<"\nMaximum benefit :"<<c[n-1][w-1]<<endl;

}

void display(int i, int j)
{
    cout<<"\nMaximum benefit from weight: ";
    while(i != 0 && j != 0)
    {
        if(c[i][j] == c[i-1][j]) i = i-1;
        else
        {
            cout<<wt[i]<<" ";
            i = i - 1;
            j = j - wt[i];
        }
    }
}

int main()
{
    ///IOS

    ll n,w;
    cout<<"enter the number of weight: ";
    cin >> n;
    cout<<"enter the total weight: ";
    cin >> w;
    cout<<"weight:\tbenefits:\n";
    for(int i=1;i<=n;i++) cin>>wt[i]>>v[i];
    knap(w+1,n+1);
    display(w+1,n+1);
    return (0);
}

