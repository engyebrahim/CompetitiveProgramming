#include <bits/stdc++.h>
using namespace std;
vector<int> v[30001];
bool vis[30001];
int dfs(int node)
{
    int ans=1;
    vis[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        if(!vis[v[node][i]])
        {
            ans+=dfs(v[node][i]);
        }
    }
    return ans;
}
int main()
{
    int t,n,m,x,y,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(vis,0,sizeof vis);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ans=max(ans,dfs(i));
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            v[i].clear();
    }
}
