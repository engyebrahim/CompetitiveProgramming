/*
ff= pow(n,k)
ft=!n/!(n-k)
tt =ft/!k
tf using dp

first char represent value of sorted flag and the second for unick flag
*/
#include<bits/stdc++.h>
using namespace std;
int n,k; long long dp[101][8];
long long fun(int last,int idx)
{
     if(idx==k) return 1;
     if(dp[last][idx]!=-1) return dp[last][idx];
     long long ans=0;
     for(int i=last;i<=n;i++) ans+=fun(i,idx+1);
     return dp[last][idx]=ans;
}
class Lottery
{
     public: vector <string> sortByOdds(vector <string> r)
          {
               vector<pair<long long,string> >v;
               long long t,u,ff,tt,tf,ft,res;
               string s,tmp;
               stringstream ss;
               char c;
               for(int i=0;i<r.size();i++)
               {
                    ss<<r[i];
                    s="";
                    while(ss>>tmp)
                    {
                         if(tmp[tmp.size()-1]==':') {
                              s+=tmp.substr(0,tmp.size()-1);
                              break;
                         }
                         else s+=tmp+' ';
                    }
                    ss>>n; ss>>k;
                    ss>>c;  t=(c=='T')?1:0;
                    ss>>c;  u=(c=='T')?1:0;
                    ss.clear();
                    
                    //ft=!n/!(n-k)
                    ft=1; 
                    for(int i=n;i>n-k;i--) ft=ft*i;
                    
                    //tt =ft/!k
                    tt=1;
                    for(int i=1;i<=k;i++) tt*=i;
                    tt=ft/tt;
                    
                    //tf using dp
                    memset(dp,-1,sizeof dp);
                    tf=fun(1,0);
                    
                    //ff= pow(n,k)
                    ff=1;
                    while(k--) ff*=n;
                    
                    if(!t&&!u) res=ff;
                    else if(!t&&u) res=ft;
                    else if(t&u) res=tt;
                    else res=tf;
                    v.push_back(make_pair(res,s));
                    
               }
               sort(v.begin(),v.end());
               vector<string >ans;
               for(int i=0;i<v.size();i++) ans.push_back(v[i].second);
               return ans;
          }
};
