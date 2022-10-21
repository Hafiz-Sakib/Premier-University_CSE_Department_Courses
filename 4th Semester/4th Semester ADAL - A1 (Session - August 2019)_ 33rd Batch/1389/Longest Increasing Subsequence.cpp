/**
Name : Tamzid Mahmud
ID   : 1703310201389

Topic : LCS(Longest Common Subsequence)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <cctype>
#include <climits>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <algorithm>
#include <ios>
#include <bitset>
#include <sstream>

#define test 0
#define pi acos(-1.0)
#define eps 1e-8
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
using namespace std ;

typedef int I ;
typedef short int SI ;
typedef long L ;
typedef long long LL ;
typedef unsigned long long ULL ;
typedef float F ;
typedef double D ;
typedef long double LD ;
typedef char C ;
typedef bool B ;
typedef string S ;
typedef vector<I> VI ;
typedef vector<I>::iterator VIT ;
typedef vector<L> VL ;
typedef vector<L>::iterator VLT ;
typedef vector<LL> VLL ;
typedef vector<LL>::iterator VLLT ;
typedef vector<C> VC ;
typedef vector<C>::iterator VCT ;
template<typename a>
void SWAP(a &b, a &c)
{
    a d = b ;
    b = c ;
    c = d ;
}

LL power(LL a, LL b)
{
    LL result = 1 ;
    while(b)
    {
        if(b&1)
            result = a * result ;
        a *= a ;
        b >>= 1 ;
    }
    return result ;
}
LL gcd(LL a, LL b)
{
    while(b)
    {
        a = a % b;
        SWAP(a,b);
    }
    return a;

}

LL lcm(LL a, LL b)
{
    return (a * (b / gcd(a,b)));
}
LL lcs(S &a, S b)
{
    LL len1 = a.size(), len2 = b.size();
    if(len1 > len2)
    {
        SWAP(len1,len2);
        SWAP(a,b);
    }
    LL dp[len1+4][len2+4];
    memset(dp, 0, sizeof dp);
    for(LL i = 1 ; i <= len1 ; i++)
    {
        for(LL j = 1 ; j <= len2 ; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = MAX(dp[i-1][j],dp[i][j-1]);
        }
    }
    stack<char> store;
    LL i = len1, j = len2;
    while(dp[i][j] != 0)
    {
        if(dp[i][j-1] == dp[i][j])
            j--;
        else if(dp[i-1][j] == dp[i][j])
            i--;
        else
        {
            store.push(b[j-1]);
            i--;
            j--;

        }
    }
    a.clear();
    while(!store.empty())
    {
        a.push_back(store.top());
        store.pop();
    }
    return dp[len1][len2];
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    S a, b;
    cin >> a >> b;
    LL ans = lcs(a,b);
    cout << endl;
    cout <<"LCS: " << a << endl;
    cout << "Length of LCS: " << ans << endl;

    return 0 ;
}

/**
Sample Input:
abcde
adsfafasdf

Sample Output:
LCS: ad
Length of LCS: 2

*/

