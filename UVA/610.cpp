#include<bits/stdc++.h>
using namespace std;
int n,dfn[1002],low[1002];
vector<vector<int> >v;
set<pair<int,int> >s;
int idx;
void fun(int node,int per)
{
     low[node]=dfn[node]=idx++;
     for(int i=0;i<v[node].size();i++)
     {
     	  if(s.find(make_pair(node,v[node][i]))==s.end()) s.insert(make_pair(v[node][i],node));
          if(dfn[v[node][i]]==-1)
          {
               fun(v[node][i],node);
               low[node]=min(low[node],low[v[node][i]]);
               if(dfn[node]<low[v[node][i]]) {s.insert(make_pair(v[node][i],node));s.insert(make_pair(node,v[node][i]));}
          }
          else if(v[node][i]!=per) low[node]=min(low[node],dfn[v[node][i]]);
     }
     
}
int main() {
     int x,y,m,cs=0;
     while(cin>>n>>m&&n+m)
     {
     	  s.clear();
          cs++;
          idx=1;
          memset(dfn,-1,sizeof dfn);
          v.clear();
          v.resize(n+1);
          for(int i=0;i<m;i++)
          {
               scanf("%d%d",&x,&y);
               v[x].push_back(y);
               v[y].push_back(x);
          }
          cout<<cs<<endl<<endl;
          fun(1,-1);
          set<pair<int,int> >::iterator it=s.begin();
          while(it!=s.end())
          {
               cout<<it->first<<" "<<it->second<<endl;
               it++;
          }
          cout<<'#'<<endl;
     }
} 
