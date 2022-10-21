/**
Name : Tamzid Mahmud
ID   : 1703310201389

Topic : Hybrid Quick Sort (quick sort with insertion sort & randomized pivot)
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
void insertion_sort(I a[], I low, I high)
{
	for(I i = low + 1; i <= high ; i++)
	{
		I value = a[i];
		I j = i;

		while (j > low && a[j - 1] > value)
		{
			a[j] = a[j - 1];
			j--;
		}

		a[j] = value;
	}
}
int partition(I a[], I low, I high, I turn)
{
    I pivot = low + (rand()% (high - low + 1));
    I i = low+1;
    swap(a[pivot], a[low]);
    if(turn == 1)
    {
        for(I j = low+1; j <= high ; j++)
        {
            if(a[j] < a[low])
            {
                swap(a[j], a[i]);
                i++;
            }
        }
    }
    else
    {
        for(I j = low+1; j <= high ; j++)
        {
            if(a[j] > a[low])
            {
                swap(a[j], a[i]);
                i++;
            }
        }
    }
    swap(a[low], a[i-1]);
    return i-1;
}
void quick_sort(I a[], I low, I high, I turn)
{

    while(low < high)
    {
        if(high - low < 15)
        {
            insertion_sort(a, low, high);
            break;
        }
        else
        {
            I pivot = partition(a, low, high, turn);
            quick_sort(a, low, pivot-1, turn);
            quick_sort(a, pivot+1, high, turn);
        }
    }
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    I n ;
    cin >> n;
    I a[n];
    for(LL i = 0 ; i < n ; i++)
        cin >> a[i];
    quick_sort(a, 0, n-1, 1);
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
