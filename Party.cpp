
//easy 0-1 knapsack problem .. with the maximum bt appoximately minimum cost..
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x,y,z,i,j,k,w;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        {
            break;
        }
        int value[m+1], wei[m+1];

        vector<pair<int,int> >mp, fi;
        map<int, int> mm;
        map<int, int> :: iterator it;

        for(i=1;i<=m;i++)
        {
            cin>>wei[i]>>value[i];
            mp.push_back(make_pair(wei[i],value[i]));
        }

        sort(mp.rbegin(),mp.rend());

        for(i=0,j=1;i<mp.size(),j<=m;i++,j++)
        {
            wei[j] = mp[i].first;
            value[j]=mp[i].second;
        }

        int table[m+5][n+5], party[m+5][n+5];
         for(i=0;i<=m;i++)
         {
             for(w=0;w<=n;w++)
             {
                 if(i==0 || w==0)
                 {
                     party[i][w]=0;
                 }
                 else if( wei[i]<=w)
                 {
                    party[i][w]= max(party[i-1][w],value[i]+party[i-1][w-wei[i]]);
                 }
                 else
                 {
                     party[i][w]= party[i-1][w];
                 }
             }
         }

         vector<int>vc;

      /*  int res = 0,sum=0,weight[vc.size()+5],k=0;

             int w = n;
            for (i = 1; i <=m&& res<=party[m][n] ; i++)
            {
                if (res == party[i-1 ][w])
                    continue;
                else {
                    k++;
                   weight[k]=wei[i];
                    res = res + value[i];
                    w = w + wei[i];
                }
            }*/



                for(j=0;j<=n;j++)
                {
                    if(party[m][n] == party[m][j])
                    {
                        cout<<j<<" ";
                        break;
                    }
                }



             cout<<party[m][n]<<endl;
    }
}
