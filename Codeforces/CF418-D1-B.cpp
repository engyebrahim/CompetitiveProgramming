#include<bits/stdc++.h>
using namespace std;
int n,m,pm; long long b;
bitset<20> s;
struct frnd
{
     int k,c,v;
};
bool cmp(frnd a,frnd b)
{
     if(a.k!=b.k) return a.k<b.k;
     if(a.c!=b.c) return a.c<b.c;
     return a.v>b.v;
}
int main(){
     bool vis[20]={};
     scanf("%d%d%d",&n,&m,&b);
     vector<frnd> f(n);
     for(int y,x,i=0;i<n;i++)
     {
          scanf("%d%d%d",&f[i].c,&f[i].k,&x);
          s.reset();
          for(int j=0;j<x;j++)
          {
               scanf("%d",&y);
               y--;
               vis[y]=1;
               s[y]=1;
          }
          f[i].v=s.to_ulong();
     }
     for(int i=0;i<m;i++)
     if(vis[i]==0) {printf("%d\n",-1); return 0;}
     pm=1;
     for(int i=0;i<m;i++) pm*=2;
     vector<vector<long long> > dp(2,vector< long long >(pm));
     pm--;
     bool p=0;
     for(int j=0;j<=pm;j++) dp[p][j]=-1,dp[!p][j]=-1;
     dp[p][0]=0;
     sort(f.begin(),f.end(),cmp);
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<=pm;j++)
          {
               if(dp[p][j]!=-1)
               {
                    if(dp[!p][j]==-1||dp[!p][j]>dp[p][j])
                    dp[!p][j]=dp[p][j];
                    if((j|f[i].v)==pm&&(dp[!p][j|f[i].v]==-1||dp[!p][j|f[i].v]>dp[p][j]+f[i].c+f[i].k*b))
                    dp[!p][j|f[i].v]=dp[p][j]+f[i].c+f[i].k*b;
                    if((j|f[i].v)!=pm&&(dp[!p][j|f[i].v]==-1||dp[!p][j|f[i].v]>dp[p][j]+f[i].c))
                      dp[!p][j|f[i].v]=dp[p][j]+f[i].c;
               }
               dp[p][j]=-1;
          }
          p=!p;
     }
     printf("%lld\n",dp[p][pm]);
}
