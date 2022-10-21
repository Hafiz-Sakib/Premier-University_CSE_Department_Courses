#include<stdio.h>

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int part(int a[],int low, int high)
{
    int pivot=a[low];
    int i=low, j=high;
    while(i<j){
    do
    {
        i++;
    }while(a[i]<=pivot);
    do
    {
        j--;
    }while(a[j]>pivot);
    if(i<j)
        swap(a,i,j);
    }
    swap(a,low,j);

    return j;
}

void quick_sort(int a[], int low, int high)
{
	if (low < high)
    {
        int x = part(a,low, high+1);
        quick_sort(a, low, x-1);
        quick_sort(a, x+1, high);
	}
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    quick_sort(a,0,n-1);

    printf("sorted array: ");
    for(int j=0;j<n;j++)
        printf("%d ", a[j]);

    return 0;

}

