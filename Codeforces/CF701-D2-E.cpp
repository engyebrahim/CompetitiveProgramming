//http://codeforces.com/blog/entry/46283
#include<bits/stdc++.h>
using namespace std;
vector<bool> u;
vector<vector<int> >v;
long long ans, n,k;
int fun(int node,int p)
{
     long long ret=u[node];
     for(int i=0;i<v[node].size();i++)
     {
          if(v[node][i]==p) continue;
          ret+=fun(v[node][i],node);
     }
     ans+=min(ret,k*2-ret);
     return ret;
}
int main(){
     cin>>n>>k;
     u.resize(n+1,0);
     v.resize(n+1);
     for(int x,i=0;i<k*2;i++) {scanf("%d",&x); u[x]=1;}
     for(int x,y,i=0;i<n-1;i++) {
          scanf("%d%d",&x,&y);
          v[x].push_back(y);
          v[y].push_back(x);
     }
     fun(1,0);
     cout<<ans<<endl;
}
