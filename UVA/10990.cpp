#include <bits/stdc++.h>
using namespace std;
long long dp[2000001],phi[2000001];
long long fun(int n)
{
    if(dp[n]!=-1) return dp[n];
    if(phi[n]==1) return 1;
    return dp[n]=fun(phi[n])+1;

}
int main()
{
    vector<int> p;
    bool f;
    for(int i=2; i*i<=2000000; i++)
    {
        f=1;
        for(int j=2; j*j<=i; j++)
            if(i%j==0) f=0;
        if(f) p.push_back(i);
    }
    memset(dp,-1,sizeof dp);
    int n,m,ans,c;
    for(int i=2;i<2000001;i++)
    {
        ans=m=i;
        for(int j=0; j<p.size()&&m!=1; j++)
        {
            if(m%p[j]==0) ans-=ans/p[j];
            while(m%p[j]==0)
            {
                m/=p[j];
            }
        }
        if(m!=1) ans-=ans/m;
        phi[i]=ans;
    }
    for(int i=2;i<=2000000;i++)
    {
        if(dp[i]==-1) fun(i);
    }
    for(int i=2;i<=2000000;i++)
        dp[i]+=dp[i-1];
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",dp[m]-dp[n-1]);
    }

}
