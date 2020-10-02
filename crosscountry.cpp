
//simple LCS .. be careful input and free memory



#include<bits/stdc++.h>

using namespace std;
         vector<int >vc;
        vector<int> run;
int main()
{
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        int i,j,k,l,n,o,p;
         vc.clear();
         run.clear();
          int maxans=0;
        while(1)
        {
                int m;
                cin>>m;
                if(m==0) break;
                vc.push_back(m);
        }


        while(1)
        {
        run.clear();
          int m;
            cin>>m;
            if(m==0) break;
                run.push_back(m);

            while(1)
            {
                cin>>n;
                if(n==0) break;
                 run.push_back(n);
            }

        int table[vc.size()+1][run.size()+1];
        memset(table, 0, sizeof table);

        for(i=1;i<=vc.size();i++)
        {
           for(j=1;j<=run.size();j++)
           {
               if(vc[i-1]==run[j-1])
               {
                   table[i][j] = table[i-1][j-1]+1;
               }
               else
               {
                   table[i][j] = max(table[i-1][j],table[i][j-1]);
               }
           }

        }
         //cout<<table[vc.size()][run.size()]<<endl;

        maxans = max(maxans, table[vc.size()][run.size()]);
    }
    cout<<maxans<<endl;
    maxans=0;

    }
}
