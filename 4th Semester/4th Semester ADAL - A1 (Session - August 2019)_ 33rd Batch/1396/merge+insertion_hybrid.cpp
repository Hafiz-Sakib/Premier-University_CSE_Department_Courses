/*
input:
100
102 216 451 33 470 13 224 20 206 106 130 150 387 363 179 481 493 481 288 251 7 343 410 201 208 258 464 120 6 152 349 335 374 86 404 415 207 221 392 280 240 413 427 305 228 398 24 13 462 152 298 256 241 368 13 298 189 499 194 196 152 255 201 129 484 465 324 368 281 49 121 182 418 107 15 134 370 361 149 416 308 97 470 254 373 417 213 486 233 416 25 30 334 488 261 103 497 475 106 460
*/


#include<bits/stdc++.h>
using namespace std;

int arr[1000];

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

void merge(int arr[], int l, int m, int r)
{
    ///cout<<"merge_sort"<<"\n";
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        if(15 > (r-l))
            insertionSort(arr,l, r);
        else
            merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cout<<"no of element: ";
    cin>> n;

    for (int i=0; i < n; i++)
        cin>>arr[i];
    mergeSort(arr, 0, n - 1);
    cout<<"\nSorted array is \n";
    for (int i=0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
}


