//lcs


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        int i,j,m,n;
        string s,c,str,x;

        cin>>s;
        c = s;
        reverse(s.begin(),s.end());
        int table[s.length()+1][s.length()+1];

        memset(table , 0, sizeof table);

        for(i=1;i<=s.length();i++)
        {
            for(j=1;j<=s.length();j++)
            {
                if(s[i-1]== c[j-1])
                {
                    table[i][j] =  table[i-1][j-1]+1;
                }
                else
                {
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
            }
        }
        cout<<s.length() - table[s.length()][s.length()]<<endl;
    }
}
