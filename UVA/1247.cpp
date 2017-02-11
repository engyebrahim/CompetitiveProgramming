#include <bits/stdc++.h>
using namespace std;
struct node
{
     int idx,c;
     string s;
};
bool operator <(node a,node b)
{
     if(a.c!=b.c) return a.c<b.c;
     if(a.s.size()!=b.s.size()) return a.s.size()<b.s.size();
     return a.idx<b.idx;
}
int main()
{
     int n,m;
     vector<vector<int> >v(30,vector<int>());
     vector<vector<int> >c(30,vector<int>());
     scanf("%d%d",&n,&m);
     char x,y;
     for(int z,i=0;i<m;i++)
     {
          cin>>x>>y>>z;
          v[x-'A'].push_back(y-'A');
          v[y-'A'].push_back(x-'A');
          c[x-'A'].push_back(z);
          c[y-'A'].push_back(z);
     }
     //cout<<x-'A'<<endl;
     scanf("%d",&m);
     node cur,nw;
     set<node> s;
     string vis[26];
      while(m--)
     {
          cin>>x>>y;
          cur.idx=x-'A',cur.c=0,cur.s=x;
          for(int i=0;i<26;i++)vis[i]="-1";
          s.insert(cur);
          while(s.size())
          {
               cur=*s.begin();
               s.erase(s.begin());
               if(vis[cur.idx]!="-1") continue;
               vis[cur.idx]=cur.s;
               //cout<<cur.idx<<" "<<cur.s<<" "<<cur.c<<endl;
               for(int i=0;i<v[cur.idx].size();i++)
               {
                    nw.idx=v[cur.idx][i],nw.c=cur.c+c[cur.idx][i],nw.s=cur.s;
                    nw.s+='A'+v[cur.idx][i];
                    s.insert(nw);
               }
          }
          for(int i=0;i<vis[y-'A'].size();i++)
          { cout<<vis[y-'A'][i]; if(i+1!=vis[y-'A'].size()) cout<<" ";}
         cout<<endl;
     }
    
     
}
