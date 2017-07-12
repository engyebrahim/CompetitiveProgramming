//find max edge in the mst if graph is conected
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> >v,c;
struct nod
{
     int x,c;
};
bool vis[201];
bool operator <(nod a,nod b)
{
     if(a.c!=b.c) return a.c<b.c;
     return a.x<b.x;
}
int mst()
{
     memset(vis,0,sizeof vis);
     int ans=-1;
     set<nod> s;
     nod cur,nw;
     cur.x=1,cur.c=0;
     s.insert(cur);
     while(s.size())
     {
          cur=*s.begin();
          s.erase(s.begin());
          if(vis[cur.x]) continue;
          vis[cur.x]=1;
          ans=max(ans,cur.c);
          for(int i=0;i<v[cur.x].size();i++)
          {
               nw.x=v[cur.x][i];
               nw.c=c[cur.x][i];
               s.insert(nw);
          }
     }
     return ans;
}
void dfs(int node)
{
     //cout<<node <<endl;
     vis[node]=1;
     for(int i=0;i<v[node].size();i++)
     {
          if(!vis[v[node][i]])
          {
               dfs(v[node][i]);
          }
     }
}
int main()
{
     int t;
     cin>>t;
     int x,y,z;
     while(t--)
     {
          cin>>n>>m;
          v.resize(n+1);
          c.resize(n+1);
          while(m--)
          {
               cin>>x>>y>>z;
               v[x].push_back(y);
               v[y].push_back(x);
               c[x].push_back(z);
               c[y].push_back(z);
          }
          memset(vis,0,sizeof vis);
          bool f=0;
          dfs(1);
          for(int i=1;i<=n;i++) 
              if(!vis[i]) f=1;
          if(f) cout<<-1<<endl;
          else  cout<<ceil(mst()/10.0)<<endl;
          v.clear();
          c.clear();
     }
}  
