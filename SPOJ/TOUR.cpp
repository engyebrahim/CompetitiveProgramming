/*
1- reverse the direction of all adges
2- get all SCC
3- suppose each scc as node and make a new graph between them 
4- from each scc node make a dfs if all node reachable then sum the number of node in this scc to the answer  
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >v,comps;
vector<set<int> >fin;
int dfn[1002],idx,low[1002],comp[1002];
bool instack[1002];
stack<int> s;
void fun(int node)
{
     dfn[node]=low[node]=idx++; instack[node]=1;
     s.push(node);
     for(int i=0;i<v[node].size();i++)
     {
          if(dfn[v[node][i]]==-1)
          {
               fun(v[node][i]);
               low[node]=min(low[node],low[v[node][i]]);
          }
          else if(instack[v[node][i]]) low[node]=min(low[node],dfn[v[node][i]]);
     }
     if(low[node]==dfn[node])
     {
          comps.push_back(vector<int>());
          int x=-1;
          while(node!=x)
          {
               x=s.top(); s.pop(); comps[comps.size()-1].push_back(x); instack[x]=0; 
               comp[x]=comps.size()-1;
          }
     }
}
bool vis[1008];
int dfs(int node){
     vis[node]=1;
     int ret=1;
     set<int>::iterator it=fin[node].begin();
     for(;it!=fin[node].end();it++)
       if(!vis[*it]) ret+=dfs(*it);
     return ret;
}
int main() {
     int t,n;
     scanf("%d",&t);
     bool f;
     int ans;
     while(t--)
     {
          ans=0;
          scanf("%d",&n);
          v.resize(n+1);
          for(int m,i=1;i<=n;i++)
          {
               scanf("%d",&m);
               for(int x,j=0;j<m;j++)
               {
                    scanf("%d",&x);
                    v[x].push_back(i);
               }
          }
          
          idx=1;
          memset(dfn,-1,sizeof dfn);;
          for(int i=1;i<=n;i++)
            if(dfn[i]==-1)
              fun(i);
          fin.resize(comps.size());
          for(int i=0;i<comps.size();i++)
          {
               for(int j=0;j<comps[i].size();j++)
               {
                    for(int k=0;k<v[comps[i][j]].size();k++)
                       fin[i].insert(comp[v[comps[i][j]][k]]);
               }
          }
          for(int i=0;i<comps.size();i++)
          {
               memset(vis,0,sizeof vis);
               if(dfs(i)==comps.size()) ans+=comps[i].size();
          }
          cout<<ans<<endl;
          comps.clear(),v.clear(),fin.clear();
     }
     
     
}
