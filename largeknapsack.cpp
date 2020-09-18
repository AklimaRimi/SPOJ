//basic unbounded knapsack nothing else


#include<bits/stdc++.h>

using namespace std;

int main()
{

    int i,j,k,x,z,m,n;

    scanf("%d %d",&n,&m);
    int wei[m+5],value[m+5];

    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&value[i],&wei[i]);
    }
    int table[n+2];

    memset(table , 0 , sizeof table);

    for(i=1;i<=m;i++)
    {
        for(j=n;j>=wei[i];j--)
        {
            table[j]=  max(table[j], value[i]+table[j-wei[i]]);
        }

    }
    printf("%d\n",table[n]);

}
