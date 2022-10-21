//quick sort

#include<stdio.h>


void swap(int arr[],int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }


int Partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j)
    {
        do
        {
            i++;
        }while(arr[i]<=pivot);
        do
        {
            j--;
        }while(arr[j]>pivot);
        if(i<j)
            swap(arr,i,j);

    }
    swap(arr,low,j);
    return j;

}

void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int j=Partition(arr,low,high+1);
        quick_sort(arr,low,j-1);
        quick_sort(arr,j+1,high);
    }
}



int  main()
{
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("Sorted array:  ");
    for(int j=0;j<n;j++)
        printf("%d ", arr[j]);
    return 0;
}
