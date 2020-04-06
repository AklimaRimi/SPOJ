#include <bits/stdc++.h>

using namespace std;

vector< vector<int> >v;
vector<int>vv;
map<int ,int>mp;

int n,m,s;
int ar[10010];
int par[10010];
stack<int>st;
int parent(int n)
{
    return (par[n]==n)?n:parent(par[n]);
}
void DFS(int s)
{
    int i,j,k,l,m;
    ar[s]=1;
    for(i=0;i<v[s].size();i++)
    {
        int x = v[s][i];
        if(ar[x]== 0)
        {
           DFS(x);
        }
    }
    vv.push_back(s);
}

int main()
{
    int i,j,k1,k2;
    scanf("%d %d",&n,&m);
    v.assign(n+1, vector<int>());
    vector<int >indegree(n+1,0);
    priority_queue<int>que;
    int maxi=-1;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&k1,&k2);
        indegree[k2]++;
        v[k1].push_back(k2);
        //mp.insert(make_pair(k1,k2));

    }
    for(i=1;i<=n;i++)
    {

        //cout<<i<<" "<<indegree[i]<<"\n";
        if(indegree[i]==0)
        {
            que.push(-i);
        }
    }
    int node=0;
    vector<int> ans;
    while(!que.empty())
    {
        node++;
        int u = -que.top();
        ans.push_back(u);
        que.pop();
        for(int x=0;x<v[u].size();x++)
        {
            int uu = v[u][x];
            indegree[uu]--;
            if(indegree[uu]==0)
            {
                que.push(-uu);
            }

        }
    }
    if(node <n)
    {
        printf("Sandro fails.\n");
        return 0;
    }
    for(int xx =0;xx<ans.size();xx++)
    {
        printf("%d ",ans[xx]);
    }
    printf("\n");



    return 0;
}
