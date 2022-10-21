#include<stdio.h>

void merging(int a[],int low,int mid,int high)
{
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;

    int sub1[n1],sub2[n2];
    for(int i=0;i<n1;i++)
        sub1[i]=a[low+i];
    for(int j=0;j<n2;j++)
        sub2[j]=a[mid+1+j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (sub1[i] <= sub2[j])
        {
            a[k] = sub1[i];
            i++;
        }
        else
        {
            a[k] = sub2[j];
            j++;
        }
        k++;
    }

     while (i < n1)
    {
        a[k] = sub1[i];
        i++;
        k++;
    }

     while (j < n2)
    {
        a[k] = sub2[j];
        j++;
        k++;
    }

}

void merge_sort(int a[],int low,int high)
{
    if (low < high)
    {
      int mid=(low+high)/2;
      merge_sort(a, low,mid);
      merge_sort(a, mid+1,high);
      merging(a,low,mid,high);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    merge_sort(a,0,n-1);

    printf("sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
