#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int c1[1001],c2[1001],n;
pair<int,int> dp[1001][1001];
pair<int,int> fun(int last,int idx)
{
     if(idx>n) return make_pair(0,0);
     if(dp[last][idx].first!=-1) return dp[last][idx];
     pair<int ,int> a,ans,b;
     int tmp=upper_bound(v[idx].begin(),v[idx].end(),last)-v[idx].begin();
     ans=fun(last,idx+1);
     if(tmp<v[idx].size()){
          a=fun(v[idx][tmp],idx+1);
          a.first+=c1[idx]+c2[v[idx][tmp]]; a.second++;
          if(ans.first<a.first) ans=a;
          else if(ans.first==a.first&&ans.second>a.second) ans=a;
          a=fun(last+1,idx);                                   
          if(ans.first<a.first) ans=a;
          else if(ans.first==a.first&&ans.second>a.second) ans=a;
     }
     
     return dp[last][idx]=ans;
}
int main() {
     int t,m;
     cin>>t;
     char c[13];
     string s[1001];
     while (t--)
     {
          memset(dp,-1,sizeof dp);
          scanf("%d",&n);
          v.resize(n+1);
          for(int i=1;i<=n;i++)
          {
               scanf("%s%s%d",&c,&c,&c1[i]);
               s[i]=c;
          }
          scanf("%d",&m);
          for(int i=1;i<=m;i++)
          {
               scanf("%s%s%d",&c,&c,&c2[i]);
               for(int j=1;j<=n;j++)
                 if(s[j]==c)
                  v[j].push_back(i);
          }
          pair<int,int> ans;
          ans=fun(0,1);
          cout<<ans.first<<" "<<ans.second<<endl;
          v.clear();
     }
}
