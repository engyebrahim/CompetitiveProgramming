#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >v,c;
int p[100002][30],n;
long long d[100002];
int pr[100002],l[100002];
bool vis[100002];
void init()
{
     memset(p,-1,sizeof p);
     for(int i=0;i<n;i++) p[i][0]=pr[i];
     for(int j=0;(1<<j)<n;j++)
     {
          for(int i=1;i<n;i++)
          {
               if(p[i][j-1]!=-1)  
                   p[i][j]=p[p[i][j-1]][j-1];
          }
     }
}
void dfs(int node)
{
     vis[node]=1;
     for(int i=0;i<v[node].size();i++)
     {
          if(!vis[v[node][i]]){
               l[v[node][i]]=l[node]+1;
               d[v[node][i]]=d[node]*1ll+c[node][i];
               pr[v[node][i]]=node;
               dfs(v[node][i]);
          }
          
     }
}
int lca(int a,int b)
{
     if(l[a]<l[b]) swap(a,b);
     int log;
     for(log=0;(1<<log)<=l[a];log++);
     log--;
     for(int i=log;i>=0;i--)
     {
          if(l[a]-(1<<i)>=l[b]) a=p[a][i];
     }
     if(a==b) return a;
     
     for(int i=log;i>=0;i--)
     {
          if(p[a][i]!=p[b][i])
              a=p[a][i],b=p[b][i];
     }
     return pr[a];
}
int main()
{
     int k,x,y,q;
     while(cin>>n&&n)
     {
          v.resize(n);
          c.resize(n);
          for(int i=1;i<n;i++)
          {
               scanf("%d%d",&x,&y);
               v[i].push_back(x);
               c[i].push_back(y);
               v[x].push_back(i);
               c[x].push_back(y);
          }
          memset(vis,0,sizeof vis);
          l[0]=0,d[0]=0,pr[0]=-1;
          dfs(0);
          init();
          cin>>k;
          
          while(k--)
          {
               scanf("%d%d",&x,&y);
               q=lca(x,y);
               cout<<d[x]+d[y]-2*d[q];
               if(k) cout<<" ";
          }
          cout<<endl;
          v.clear();
          c.clear();
     }
}  
