#include <stdio.h>
void merge(int array[ ],int l,int r,int m)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=array[l+i];
    for(j=0;j<n2;j++)
        R[j]=array[m+1+j];


    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            array[k]=L[i];
            i++;
        }
        else
        {
            array[k]=R[j];
            j++;
        }
        k++;
    }


    while(i<n1)
    {
        array[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
            array[k]=R[j];
            j++;
            k++;
    }
}

void mergesort(int array[ ],int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(array,l,m);
        mergesort(array,m+1,r);
        merge(array,l,m,r);
    }
}


void printarray(int a[ ],int size)
{
    int i;
    for(i=0;i<size;i++)
    printf("%d",a[i]);
    printf("\n");
}

int main()
{
    int array[]={10,8,3,81,9};
    int array_size=sizeof(array)/sizeof(array[0]);
    printf("input\n");
    printarray(array,array_size);
    mergesort(array,0,array_size-1);
    printf("\nsorted array\n");
    printarray(array,array_size);
    return 0;
}
