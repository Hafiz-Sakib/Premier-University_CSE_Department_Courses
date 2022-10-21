/*
input:
100
102 216 451 33 470 13 224 20 206 106 130 150 387 363 179 481 493 481 288 251 7 343 410 201 208 258 464 120 6 152 349 335 374 86 404 415 207 221 392 280 240 413 427 305 228 398 24 13 462 152 298 256 241 368 13 298 189 499 194 196 152 255 201 129 484 465 324 368 281 49 121 182 418 107 15 134 370 361 149 416 308 97 470 254 373 417 213 486 233 416 25 30 334 488 261 103 497 475 106 460
*/
#include<bits/stdc++.h>
using namespace std;

int a[1000];
void insertionSort(int arr[],int l, int r)
{
    ///cout<<"insertion_Sort"<<"\n";
	for (int i = l; i <= r; i++)
	{
		int key = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > key)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}
int partition( int p, int q)
{
    int pivot = a[q];
	int pIndex = p;
    int i;
	for (i = p; i < q; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	swap (a[pIndex], a[i]);
	return pIndex;
}

void quick_sort(int p,int q)
{
    //cout<<"quicksort"<<"\n";
    if (p < q)
    {
        int j = partition(p,q);

        if(15 > (q-p)) insertionSort(a,p, q);

        else
        {
            quick_sort(p,j-1);
            quick_sort(j+1,q);
        }
    }
}

int main()
{
    int n;
    cout<<"total numbers: ";
    cin>>n;
    cout<<"elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    quick_sort(0,n-1);
    cout<<"elements after sorting: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}



