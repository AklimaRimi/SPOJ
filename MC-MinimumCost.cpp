#include<bits/stdc++.h>

using namespace std;
int ar[1001][1001];

int edit_distance(string s1,string s2)
{

    for(int i=0;i<= s1.length();i++)
    {
        for(int j=0;j<= s2.length();j++)
        {
            if(i==0||j==0)
            {
                ar[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                ar[i][j] = 1+ ar[i-1][j-1];
            }
            else if (s1[i-1]!=s2[j-1])
            {
                ar[i][j] = max(ar[i-1][j],ar[i][j-1]);
            }

        }
    }

    int m = ar[s1.length()][s2.length()];
    return ((s1.length()-m)*15 + (s2.length()-m)*30);
}
int main()
{
    int i,j,k,l;
    string s1,s2;
    while(cin>>s1)
    {
        if(s1=="#")
        {
            break;
        }
        else
        {
            cin>>s2;
            printf("%d\n",edit_distance(s1,s2));
        }
    }
}
