#include<bits/stdc++.h>
using namespace std;
class MagicSpell
{
     public:string fixTheSpell(string s)
     {
          vector<char> v;
          for(int i=0;i<s.size();i++)
          {
               if(s[i]=='A'||s[i]=='Z') v.push_back(s[i]);
          }
          int j=v.size()-1;
          for(int i=0;i<s.size();i++)
          {
               if(s[i]=='A'||s[i]=='Z') s[i]=v[j--];
          }
          return s;
     }
};
