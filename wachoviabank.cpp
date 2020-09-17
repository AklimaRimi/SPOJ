//0-1 knapsack

#include<bits/stdc++.h>
using namespace std;
int main()
{

    int tt,t;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++){


    int i,j,k,l,m,n,x,y,z;

    scanf("%d %d",&n,&m);
    int wei[m+4],value[m+4];
    for(i=1;i<=m;i++)
    {
            scanf("%d %d",&wei[i],&value[i]);
    }

    int table[m+1][n+1];

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j==0 || i==0)
            {
                table[i][j]=0;
            }
            else if( wei[i]<=j)
            {
                table[i][j] =max(value[i]+table[i-1][j-wei[i]], table[i-1][j]);
            }
            else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }

    printf("Hey stupid robber, you can get %d.\n",table[m][n]);
    }
}
