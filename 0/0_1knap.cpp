#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j,k,totalWeight;
    cin>>totalWeight>>n;
    int weight[n+1], values[ n+1];
    for(i=1;i<=n;i++)
    {
        cin>>weight[i]>>values[i];
    }

    int table[n+1][totalWeight+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=totalWeight;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
             else if(weight[i]<=j)
            {
                table[i][j] = max(table[i-1][j],(values[i]+table[i-1][j-weight[i]]));
            }
            else
            {
                table[i][j]= table[i-1][j];
            }
        }
    }
   /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=totalWeight;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }*/
  cout<<table[n][totalWeight]<<endl;
}
