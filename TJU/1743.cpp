#include <bits/stdc++.h>
using namespace std;
int n,vis[240002],p[240002];
vector<vector<int> >v;
vector<int> a;
set<int> s;
struct node
{
     int x,d,p;
};
int par(int idx,int d)
{
     if(!d)
     return idx;
     return par(p[idx],d-1);
}
int bfs(int idx)
{
     memset(vis,-1,sizeof vis);
     memset(p,-1,sizeof p);
     queue<node>q;
     int ret;
     node cur,nw;
     cur.x=idx,cur.d=0;
     cur.p=idx;
     q.push(cur);
     while(q.size())
     {
          cur=q.front();
          q.pop();
          if(vis[cur.x]!=-1) continue;
          ret=cur.x;
          vis[cur.x]=cur.d;
          p[cur.x]=cur.p;
          nw.p=cur.x; nw.d=cur.d+1;
          for(int i=0;i<v[cur.x].size();i++)
          {
               nw.x=v[cur.x][i];
               q.push(nw);
          }
     }
     return ret;
}
int main()
{
     int h,t,idx;
     cin>>t;
     while(t--)
     {
          cin>>n;
          for(int i=0;i<=n;i++)
          v.push_back(a);
          for(int x,i=2;i<=n;i++)
          {
               cin>>x;
               v[i].push_back(x);
               v[x].push_back(i);
          }
          idx=bfs(1);
          idx=bfs(idx);
          //cout<<idx;
          if(vis[idx]%2==0)
            cout<<par(idx,vis[idx]/2)<<endl;
          else
             {
                 h=par(idx,vis[idx]/2);
                 cout<<min(h,p[h])<<" "<<max(h,p[h])<<endl;
             }
          v.clear();
          s.clear();
     }
}
