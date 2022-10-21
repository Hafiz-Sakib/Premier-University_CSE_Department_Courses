/**
Name : Tamzid Mahmud
ID   : 1703310201389

Topic : Matrix Chain Multiplication
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n];
    for(int i = 0 ; i < n ; i++)
        cin >> p[i];

    int m[n+1][n+1], s[n+1][n+1];
    memset(m, 0, sizeof m);
    memset(s, 0, sizeof s);

    int j, minimum, q; ///min  = minimum
    for(int d = 1 ; d < n-1 ; d++)
    {
        for(int i = 1 ; i < n-d ; i++)
        {
            j = i+d;
            minimum = INT_MAX;
            for(int k = i ; k <= j-1 ; k++)
            {
                q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q < minimum)
                {
                    minimum = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = minimum;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    return 0;
}

/**
Sample Input:
5
5 4 6 2 7

Sample Output:
0 0 0 0 0
0 0 1 1 3
0 0 0 2 3
0 0 0 0 3
0 0 0 0 0
*/
