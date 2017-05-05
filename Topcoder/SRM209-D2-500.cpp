#include<bits/stdc++.h>
using namespace std;
struct node
{
     int g,s,b;
     string k;
};
bool fun(node a,node b)
{
     if(a.g!=b.g) return a.g>b.g ;
     if(a.s!=b.s) return a.s>b.s ;
     if(a.b!=b.b) return a.b>b.b ;
     return a.k<b.k;
}
class MedalTable
{
     public:vector <string> generate(vector <string> v)
     {
          int idx=1;
          map<string,int> num;
          map<int,string> name;
          stringstream ss; string s; 
          int arr[3][55]={};
          for(int j,i=0;i<v.size();i++)
          {
               ss.clear();
               ss<<v[i];
               j=0;
               while(ss>>s)
               {
                    if(num[s]==0) num[s]=idx,name[idx]=s,idx++;
                    arr[j++][num[s]]++;
               }
          }
          vector<node> ans;
          node cur;
          for(int i=1;i<idx;i++)
          {
               cur.g=arr[0][i],cur.s=arr[1][i],cur.b=arr[2][i],cur.k=name[i];
               ans.push_back(cur);
          }
          sort(ans.begin(),ans.end(),fun);
          vector<string >fin(ans.size(),"");
          for(int i=0;i<ans.size();i++)
          {
               ss.clear();
               ss<<ans[i].k;
               ss>>s;
               fin[i]+=s;
               fin[i]+=' ';
               
               ss.clear();
               ss<<ans[i].g;
               ss>>s;
               fin[i]+=s;
               fin[i]+=' ';
               
               ss.clear();
               ss<<ans[i].s;
               ss>>s;
               fin[i]+=s;
               fin[i]+=' ';
               
               ss.clear();
               ss<<ans[i].b;
               ss>>s;
               fin[i]+=s;
               cout<<fin[i]<<endl;
          }
          return fin;
     }
};
