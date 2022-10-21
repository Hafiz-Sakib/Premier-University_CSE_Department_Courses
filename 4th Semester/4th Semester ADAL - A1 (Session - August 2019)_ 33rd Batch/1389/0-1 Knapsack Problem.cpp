/**
Name : Tamzid Mahmud
ID   : 1703310201389

Topic : 0-1 Knapsack
*/
#include <bits/stdc++.h>

using namespace std;
int c[1000][1000];

int knapsack(int n,int W, int w[], int b[])
{
    for(int i = 0 ; i <= n ; i++)
        c[i][0] = 0;
    for(int j = 1 ; j <= W ; j++)
        c[0][j] = 0;

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= W ; j++)
        {
            if(w[i-1] <= j)
            {
                if(c[i-1][j - w[i-1]] + b[i-1] > c[i-1][j])
                    c[i][j] = c[i-1][j-w[i-1]] + b[i-1];
                else
                    c[i][j] = c[i-1][j];
            }
            else
                c[i][j] = c[i-1][j];
        }
    }

    return c[n][W];
}
int main()
{
    int n;
    while(cin >> n)
    {
//        memset(c, 0, sizeof c);
        int weight[n], benifit[n], w = INT_MIN;

        for(int i = 0 ; i < n ; i++)
        {
            cin >> weight[i] >> benifit[i];
            w = max(weight[i], w);
        }

        int max_benifit = knapsack(n,w, weight, benifit);
        cout << max_benifit << endl;
    }
    return 0;
}

/**
Sample Input:
2 3
3 4
4 5
5 6

Sample Output:
7
*/
