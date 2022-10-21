#include<stdio.h>
#include<string.h>

char X[100],Y[100];
int i,j,m,n,C[100][100],B[100][100];

int max(int a, int b)
{
    return (a>b)?a:b;
}

int LcsLength(int m, int n)
{
    if (m == 0 || n == 0)
       return 0;
    if (X[m-1] == Y[n-1])
       return 1 + LcsLength( m-1, n-1);
    else
       return max(LcsLength( m, n-1), LcsLength( m-1, n));

}

void main()
{
    while (1)
    {
        gets(X);
        if(feof(stdin))
            break;
        gets(Y);

        m=strlen(X);
        n=strlen(Y);

        printf("LCSLength -> %d\n",LcsLength(m, n));

        printf("\n");
    }
}
