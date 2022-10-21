/**
Name : Tamzid Mahmud
ID   : 1703310201389

Topic : Merge Sort with Insertion sort
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
void insertion_sort(LL a[], LL low, LL high)
{
	for(LL i = low + 1; i <= high ; i++)
	{
		LL value = a[i];
		LL j = i;

		while (j > low && a[j - 1] > value)
		{
			a[j] = a[j - 1];
			j--;
		}

		a[j] = value;
	}
}
void merge(LL a[], LL start, LL mid, LL end)
{
    LL first = start, second = mid+1, b[end - start+1], index = 0;

    for(LL i = start ; i <= end ; i++)
    {
        if(first > mid)
            b[index++] = a[second++];
        else if(second > end)
            b[index++] = a[first++];
        else if(a[first] > a[second])
            b[index++] = a[second++];
        else
            b[index++] = a[first++];
    }
    for(LL i = 0, j = start ; i < index ; i++, j++)
        a[j] = b[i];
}
void merge_sort(LL a[], LL start, LL end)
{

    while(start < end)
    {
        if(end- start < 15)
        {
            insertion_sort(a, start, end);
            break;
        }
        else
        {
            LL mid = (start + end) / 2;
            merge_sort(a, start, mid);
            merge_sort(a, mid+1, end);
            merge(a, start, mid, end);
        }
    }
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL n;
    cin >> n;
    LL a[n];
    for(LL i = 0 ; i < n ; i++)
        cin >> a[i];

    merge_sort(a, 0, n-1);

    for(LL i = 0 ; i < n ; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0 ;
}

/**
Sample Input:
5
5 23 1 3 1

Sample Output:
1 1 3 5 23

*/
