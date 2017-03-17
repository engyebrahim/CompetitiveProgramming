//SCC algorithm
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v,comps;
vector<int> ans; int x,idx,dfn[5003],comp[5003],instack[5003],low[5003];
stack<int> s;
int fun(int node)
{
     low[node]=dfn[node]=idx++;
     instack[node]=1;
     s.push(node);
     for(int i=0;i<v[node].size();i++)
     {
          if(dfn[v[node][i]]==-1)
            fun(v[node][i]),low[node]=min(low[node],low[v[node][i]]);
          else if(instack[v[node][i]])
              low[node]=min(low[node],dfn[v[node][i]]);
     }
     
     if(dfn[node]==low[node])
     {
          comps.push_back(vector<int>());
          x=0;
          while(x!=node)
          {
               x=s.top();
               s.pop(); instack[x]=0;
               comp[x]=comps.size()-1;
               comps[comps.size()-1].push_back(x);
          }
     }
}
int main() {
     int n,m,x,y; bool f;
     while(cin>>n&&n)
     {
          scanf("%d",&m);
          v.resize(n+1);
          memset(dfn,-1,sizeof dfn);
          idx=1;
          while(m--)
          {
               cin>>x>>y;
               v[x].push_back(y);
          }
          for(int i=1;i<=n;i++)
            if(dfn[i]==-1)
              fun(i);
          for(int i=0;i<comps.size();i++)
          {
               f=1;
               for(int j=0;j<comps[i].size();j++)
                    for(int k=0;k<v[comps[i][j]].size();k++)
                       if(comp[v[comps[i][j]][k]]!=i) {f=0; break;}
               if(f) ans.insert(ans.end(),comps[i].begin(),comps[i].end());
          }
          sort(ans.begin(),ans.end());
          for(int i=0;i<ans.size();i++) {
               cout<<ans[i];
               if(i+1!=ans.size()) cout<<" ";
          }
          cout<<endl;
          v.clear(),comps.clear(),ans.clear();
     }
}
