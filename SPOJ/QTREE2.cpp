/*
for dist a b
find dist from root to all nodes then find lca(a,b) , ans=dist(root,a)+dist(root,b)-2*dist(root,lca(a,b))
for kth
if kth in a&lca(a,b) tree then find kth ancestor for a
else k-no.node in a&lca(a,b) tree ,find no.node in lca(a,b)&b-k ancestor for b
*/
#include<bits/stdc++.h>
using namespace std;
int idx,n;
vector<vector<int> >v,c;
int l[100002],d[10003],pr[10002],p[10003][20];
bool vis[10003];
void dfs(int node)
{
     vis[node]=1;
     for(int i=0;i<v[node].size();i++)
     {
          if(!vis[v[node][i]]){
               l[v[node][i]]=l[node]+1;
               d[v[node][i]]=d[node]+c[node][i];
               pr[v[node][i]]=node;
               dfs(v[node][i]);
          }
     }
}
void pre() {
     memset(p,-1,sizeof p);
     for(int i=1;i<=n;i++) p[i][0]=pr[i];
     
     for(int j=1;(1<<j)<=n;j++)
          for(int i=1;i<=n;i++)
               if(p[i][j-1] != -1)
                    p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int a,int b)
{
     if(l[a]<l[b]) swap(a,b);
     int log;
     for(log=1;(1<<log)<=l[a];log++);
     log--;
     
     for(int i=log;i>=0;i--)
          if(l[a]-(1<<i)>=l[b]) a=p[a][i];
     if(a==b) return a;
     
     for(int i=log;i>=0;i--)
     {
          if(p[a][i]!=-1&&p[a][i]!=p[b][i])
               a=p[a][i],b=p[b][i];
     }
     return pr[a];
}
int kth(int a,int k)
{
     k--;
     if(k==0) return a; 
     int log;
     for(log=1;(1<<log)<=l[a];log++);
     log--;
     k=l[a]-k;
     for(int i=log;i>=0;i--)
     {
          if(l[a]-(1<<i)>=k)
               a=p[a][i];
     }
     return a;
}
int main()
{
     int t,x,y,z;
     scanf("%d",&t);
     string s;
     while(t--)
     {
          scanf("%d",&n);
          v.resize(n+1);
          c.resize(n+1);
          for(int i=0;i<n-1;i++)
          {
               scanf("%d%d%d",&x,&y,&z);
               v[x].push_back(y);
               v[y].push_back(x);
               c[x].push_back(z);
               c[y].push_back(z);
          }
          memset(vis,0,sizeof vis);
          l[1]=1,d[1]=0,pr[1]=-1;
          dfs(1);
          pre();
          int lc;
          while(cin>>s&&s!="DONE")
          {
               if(s=="DIST")
               {
                    scanf("%d%d",&x,&y);
                    lc=lca(x,y);
                    printf("%d\n",d[x]+d[y]-d[lc]*2);
               }
               else
               {
                    scanf("%d%d%d",&x,&y,&z);
                    lc=lca(x,y);
                    if(l[x]-l[lc]+1>=z) printf("%d\n",kth(x,z));
                    else printf("%d\n",kth(y,l[y]-l[lc]-(z-(l[x]-l[lc]+1)-1)));
               }
          }
          cout<<endl;
          v.clear();
          c.clear();
     }
}   
