//lcs with trick


//apple peach = appleach
#include<bits/stdc++.h>

using namespace std;

int main()
{
     int i,j,m,n,k,l,o,p;

     string s,c,str;
     int table[101][101];

     while(cin>>s>>c)
     {
         str = c;
         memset(table, 0 , sizeof table);
         for(i=1;i<=s.length();i++)
         {
             for(j=1;j<=c.length();j++)
             {
                 if(s[i-1]==c[j-1])
                 {
                        table[i][j] = table[i-1][j-1]+1;
                 }
                 else
                 {
                     table[i][j] = max(table[i-1][j],table[i][j-1]);
                 }
             }
         }
         string  s1;
          vector<char>vc;
     i = s.length(),j = c.length();
     n = j;
     while(i>0 && j>0)
     {
         if(s[i-1]==c[j-1])
         {
             //cout<<j-1<<" "<<n-j-1;
             vc.push_back(s[i-1]);
             i--;
             j--;

         }
         else if(table[i-1][j]>table[i][j-1])
         {
             i--;
         }
         else
         {
             j--;
         }
     }
     j=0;
     //cout<<s1<<endl;
     reverse(vc.begin(),vc.end());


     int l1=0, l2=0;
        for(int i=0; i<vc.size(); ++i)
        {
            while(l1<s.length() && s[l1] != vc[i])
            {
                cout<<s[l1];//if uncommon then print
                ++l1;
            }
            while(l2 < c.length() && c[l2]!=vc[i])
            {
                cout << c[l2];// it uncommon then print 
                ++l2;
            }

            cout<<vc[i];// print common
            ++l1;
            ++l2;
        }
        for(i=l1;i<s.length();i++)
        {
            cout<<s[i];//rest of the string 
        }
        for(j=l2;j<c.length();j++)
        {
            cout<<c[j];// rest of the string
        }
        cout<<endl;

     }


}
