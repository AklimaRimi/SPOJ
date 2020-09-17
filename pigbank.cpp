//unbounded knapsack ... but but buttttt you have to minimize value :)


#include<bits/stdc++.h>

using namespace std;

int main()
{

    int tt,t;
    cin>>t;
    for(tt=1;tt<=t;tt++){

    int i,j,m,n,x,z,y;
    cin>>x>>n>>m;

    int maxi=100000100;
    int value[m+3],wei[m+2];
    for(i=0;i<m;i++)
    {
        cin>>value[i]>>wei[i];
    }
    int table[n+1];
     int sum=0;

     for(i=1;i<=n+1;i++)
     {
         table[i]=maxi;
     }

    table[0]=0;
    n = abs(n-x);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
            if (wei[j] <= i)
            {
                table[i] = min(table[i], table[i-wei[j]]+value[j]);
            }
        }
    }

    if(table[n]== maxi)
        {
                printf("This is impossible.\n");
    }
    else
        {            printf("The minimum amount of money in the piggy-bank is %d.\n",table[n]);

    }
    }
}
