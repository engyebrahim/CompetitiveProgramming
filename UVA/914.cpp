#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> p;
    bool vis[1000001]={};
    for(long long i=2;i<=1000000;i++)
    {
        if(!vis[i]){
        for(long long j=i*i;j<=1000000;j+=i)
            vis[j]=1;
        p.push_back(i);
        }
    }
    int t,n,m,s,e,mx,ans;
    bool f;
    map<int,int> mp;
    map<int,int>::iterator it;
    scanf("%d",&t);
    while(t--)
    {
        f=1;
        scanf("%d%d",&n,&m);
        s=lower_bound(p.begin(),p.end(),n)-p.begin();
        e=upper_bound(p.begin(),p.end(),m)-p.begin();
        mx=-1;
        for(int i=s+1;i<e;i++)
        {
            mp[p[i]-p[i-1]]++;
        }
        for(it=mp.begin();it!=mp.end();it++)
            if(it->second>mx) mx=it->second,ans=it->first;
            else if(it->second==mx) f=0;
        if(f&&s+1<e) printf("The jumping champion is %d\n",ans);
        else printf("No jumping champion\n");
        mp.clear();
    }
}
