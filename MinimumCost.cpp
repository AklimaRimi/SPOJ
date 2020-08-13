#include<bits/stdc++.h>

using namespace std;

int len[2001][2001];

string s1,s2;

int edit_distance(string s1, string s2)
{

    for(int i=0;i<=s1.length();i++)
    {
        len[i][0]=i;
    }
    for(int i=0;i<=s2.length();i++)
    {
        len[0][i]=i;
    }
    for(int i=1;i<=s1.length();i++)
    {
        for(int j=1;j<= s2.length(); j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                len[i][j] = len[i-1][j-1];
            }
            else
            {
                len[i][j] = 1+ min(len[i-1][j],min(len[i][j-1],len[i-1][j-1]));
            }
        }
    }

    return len[s1.length()][s2.length()];

}
int main()
{
    int t,tt;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        cin>>s1>>s2;
        printf("%d\n")edit_distance(s1,s2);
    }
}
