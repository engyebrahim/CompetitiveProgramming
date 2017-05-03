/*
-we will use bits every time we must have the nodes that have judges and the distination node 
-from every mask find shortest path using bfs from distination node to only true nodes in the mask
  then if all judge nodes reachable minimizethe ans with the cost of this bfs 
*/
#include<bits/stdc++.h>
using namespace std;
int n,d,j,f,ans,mask;
vector<vector<int> >v;
vector<vector<int> >c;
vector<int> jd;
int pr[22];
struct node
{
     int u,v,w;
};
bool operator <(node a,node b)
{
     if(a.w!=b.w) return a.w<b.w;
     else if(a.u!=b.u) return a.u<b.u;
     return a.v<b.v;
}
void fun()
{
     node cur,nw;
     set<node>s;
     int vis[22],cost,mask;
     bool flag;
     for(int i=1;i<=(1<<n);i++)
        if((i&f)==f)
        {
             memset(vis,-1,sizeof vis);
             cur.u=-3,cur.v=d,cur.w=0;
             s.insert(cur);
             cost=0;
             while(s.size())
             {
                  cur=*s.begin();
                  s.erase(s.begin());
                  if(vis[cur.v]!=-1) continue;
                  vis[cur.v]=cur.u;
                  cost+=cur.w;
                  nw.u=cur.v;
                  for(int k=0;k<v[cur.v].size();k++)
                  {
                       nw.v=v[cur.v][k]; nw.w=c[cur.v][k];
                       if((i>>nw.v)&1) s.insert(nw);
                  }
             }
             flag=1;
             for(int k=0;k<j;k++) if(vis[jd[k]]==-1) flag=0;
             if(flag)
                  if((ans>cost)||(ans==cost&&__builtin_popcount(i)<__builtin_popcount(mask))||(ans==cost&&__builtin_popcount(i)==__builtin_popcount(mask)&&i<mask))
                  {
                       ans=cost;
                       mask=i;
                       for(int i=0;i<n;i++) pr[i]=vis[i];
                  }
        }
}
int main(){
     int tc=0,m;
     while(cin>>n&&n!=-1)
     {
          tc++;
          v.clear(),v.resize(n);
          c.clear(),c.resize(n);
          f=0;
          cin>>d>>m;
          d--;
          int u,V,w;
          while(m--)
          {
               cin>>u>>V>>w;
               u--,V--;
               v[u].push_back(V); c[u].push_back(w);
               v[V].push_back(u); c[V].push_back(w);
          }
          cin>>j;
          jd.clear(),jd.resize(j);
          f|=(1<<d);
          for(int i=0;i<j;i++)
          {
               cin>>jd[i];
               jd[i]--;
               f|=(1<<jd[i]);
          }
          mask=0;
          ans=1e+9;
          fun();
          printf("Case %d: distance = %d\n",tc,ans);
          for(int i=0;i<j;i++)
          {
               u=jd[i];
               cout<<"   ";
               while(u!=d)
               {
                    cout<<u+1<<'-';
                    u=pr[u];
               }
               cout<<d+1<<endl;
          }
          cout<<"\n";
     }
}
