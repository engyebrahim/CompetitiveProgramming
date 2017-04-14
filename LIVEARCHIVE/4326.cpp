/*
-first creat vector for each combination of m nodes
-for every vector sum the nodes weight
-get the sum of edges in its MST
-calculate the ratio
-output the smallest ratio vector 
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[20],w[20][20],k;
vector<vector<int > > v;
vector<pair<double,int> >p;
vector<int> tmp;
void creat(int c,int last)
{
     if(c==m)
     {
          v.push_back(tmp);
          return;
     }
     for(int i=last+1;i<=n;i++)
     {
          tmp.push_back(i);
          creat(c+1,i);
          tmp.pop_back();
     }
}
struct node
{
     int x,w;
};
bool operator <(node a,node b)
{
     if(a.w!=b.w) return a.w<b.w;
     return a.x<b.x;
}
int main() {
     long long sum,ss;
     set<node> s;
     bool vis[20];
     node cur,nw;
     while(cin>>n>>m&&n+m)
     {
          for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
          for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) 
               scanf("%d",&w[i][j]);
          creat(0,0);
          for(int i=0;i<v.size();i++)
          {
               sum=0,ss=0;
               memset(vis,0,sizeof vis);
               for(int j=0;j<m;j++) sum+=arr[v[i][j]],vis[v[i][j]]=1;
               cur.x=v[i][0],cur.w=0;
               s.insert(cur);
               while(s.size())
               {
                    cur=*s.begin();
                    s.erase(s.begin());
                    if(vis[cur.x]==0) continue;
                    vis[cur.x]=0;
                    ss+=cur.w;
                    for(int i=1;i<=n;i++)
                    {
                         if(vis[i]==0) continue;
                         nw.x=i,nw.w=w[cur.x][i];
                         s.insert(nw);
                    }
               }
               //cout<<i<<" "<<ss<<" "<<sum<<endl;
               p.push_back(make_pair((double)ss/sum,i));
          }
          sort(p.begin(),p.end());
          int idx=p[0].second;
          for(int i=0;i<m;i++) {
               cout<<v[idx][i];
               if(i+1!=m) cout<<" ";
          }
          cout<<endl;
          p.clear(); v.clear();
     }
} 
