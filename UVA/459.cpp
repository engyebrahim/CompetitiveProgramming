#include <bits/stdc++.h>
using namespace std;
vector<int> v[30];
bool vis[30];
void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        if(!vis[v[node][i]])
        {
            dfs(v[node][i]);
        }
    }
}
int main()
{
    int t,n,x,y,ans;
    string s;
    scanf("%d",&t);
    getline(cin,s);
    getline(cin,s);
    while(t--)
    {
        getline(cin,s);
        n=s[0]-'A';
        while(getline(cin,s)&&s.size())
        {
            x=s[0]-'A';
            y=s[1]-'A';
            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(vis,0,sizeof vis);
        ans=0;
        for(int i=0;i<=n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=n;i++)
            v[i].clear();
        if(t) cout<<endl;
    }
}
