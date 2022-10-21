//lcs

#include<stdio.h>
#include<string.h>

char X[100],Y[100];
int i,j,m,n,C[100][100],B[100][100];


int LcsLength()
 {
    m=strlen(X);
    n=strlen(Y);
    for (i=1;i<=m;i++)
        C[i][0]=0;
    for (j=0;j<=n;j++)
        C[0][j]=0;
    for(i=1;i<=m;i++)
    for (j=1;j<=n;j++)
    {
 if (X[i-1]==Y[j-1])
  {
 C[i][j]=C[i-1][j-1]+1;
 B[i][j]=1;
  }
 else if (C[i-1][j]>=C[i][j-1])
  {
 C[i][j]=C[i-1][j];
 B[i][j]=2;
 }
 else
    {
 C[i][j]=C[i][j-1];
 B[i][j]=3;
    }
 }
 return C[m][n];
}

void printLCS(int i,int j)
 {
 if (i==0 || j==0)
    return;
 if (B[i][j]==1)
 {
 printLCS(i-1,j-1);
 printf("%c",X[i-1]);
 }
 else if (B[i][j]==2)
 printLCS(i-1,j);
 else
 printLCS(i,j-1);
}
void main()
 {
 while (1)
    {
 gets(X);
 if (feof(stdin))
    break;
 gets(Y);
 printf("LCSLength -> %d\n",LcsLength());
 printLCS(m,n);
 printf("\n");
 }
}
