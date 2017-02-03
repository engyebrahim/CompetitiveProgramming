#include <bits/stdc++.h>
using namespace std;

int main()
{
     string s[6];
     for(int i=0;i<6;i++)
     cin>>s[i];
     vector<string> v,ans;
     sort(s,s+6);
     bool f=0;
     string k,l,m;
     do
     {
          if(s[2].size()+1!=s[1].size()+s[4].size()||s[3].size()+1!=s[0].size()+s[5].size()
          ||s[0][0]!=s[1][0]||s[0][s[0].size()-1]!=s[2][0]||s[3][0]!=s[1][s[1].size()-1]
          ||s[3][s[3].size()-1]!=s[4][0]||s[4][s[4].size()-1]!=s[5][s[5].size()-1]
          ||s[2][s[2].size()-1]!=s[5][0]||s[3][s[0].size()-1]!=s[2][s[1].size()-1])
          continue;
          m="",l="";
          for(int i=0;i<s[5].size()-1;i++)
            m+='.';
          v.push_back(s[0]+m);
          for(int i=0;i<s[0].size()-2;i++)
               l+='.';
          for(int i=1;i<s[1].size()-1;i++)
          {
               k="";
               k+=s[1][i];
               k+=l;
               k+=s[2][i];
               v.push_back(k+m);
          }
          v.push_back(s[3]);
          m=l+'.';
          l="";
          for(int i=0;i<s[5].size()-2;i++)
               l+='.';
          for(int i=1;i<s[4].size()-1;i++)
          {
               k="";
               k+=s[2][i+s[1].size()-1];
               k+=l;
               k+=s[4][i];
               v.push_back(m+k);
          }
          v.push_back(m+s[5]);
          
          if(f&&v<ans) ans=v;
          else if(!f) f=1,ans=v;
          v.clear();
     }while(next_permutation(s,s+6));
     if(f)
      for(int i=0;i<ans.size();i++)
       cout<<ans[i]<<endl;
     else 
       cout<<"Impossible"<<endl;
}
