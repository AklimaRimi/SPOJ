#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v[1000009];
ll n;

void update(ll v[],ll index,ll y)
{
    int sum = 0;

    while(index<=n)
    {
        v[index]+= y;
       // cout<<"index "<<index<<"  "<<v[index]<<endl;
        index += index &(-index);
    }
}
ll query(ll index)
{
    int sum = 0;
    while(index>0)
    {
        sum+=v[index];
        index -= index & (-index);
    }
    return sum;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,m,o,i,j,p;
    string s;
    cin>>n;
    //update(v,)
    cin>>x;
    for(i=1;i<=x;i++)
    {
        cin>>s;
        if(s=="find")
        {
            cin>>o>>p;
            cout<<abs(query(o-1)-query(p))<<endl;
        }
        else
        {
            cin>>o>>p;
            update(v,o,p);
        }
    }
}
