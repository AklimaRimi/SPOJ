#use LIS Algorithm with stl 

#include<bits/stdc++.h>
#define mx 2010

using namespace std;

int main()
{
    int i,j,k,l,m,n,o,p,tt,t;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>n;
        int ar[n],br[n],cr[n],dr[n];
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        vector<pair<int ,int>>mp;

        for(i=0;i<n;i++)
        {
            cin>>br[i];
        }
        for(i=0;i<n;i++)
        {
            mp.push_back({ar[i],br[i]});
        }
        j=0;
        sort(mp.begin(),mp.begin()+n);

        for(i=0;i<=n;i++)
        {
            br[i]=1;
        }
        int ans =0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(mp[i].second>=mp[j].second&&br[i]<br[j]+1)
                {
                    br[i] = br[j]+1;
                }
            }
                    ans = max(ans,br[i]);

        }
        cout<<ans<<endl;
    }
}

