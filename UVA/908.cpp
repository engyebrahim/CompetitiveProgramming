#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> v[1000001],c[1000001];
bool vis[1000001];
struct node
{
    int n,c;
};
bool operator<(node a,node b)
{
    if(a.c!=b.c) return a.c<b.c;
    return a.n<b.n;;
}
int main()
{
    long long ans;
    int x,y,z;
    set<node> s;
    bool f=0;
    node cur,nw;
    string t;
    do
    {
        if(f) printf("\n");
        f=1;
        scanf("%d",&n);
        ans=0;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            ans+=z;
        }
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(y);
            c[x].push_back(z);
            v[y].push_back(x);
            c[y].push_back(z);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(y);
            c[x].push_back(z);
            v[y].push_back(x);
            c[y].push_back(z);
        }
        printf("%d\n",ans);
        cur.c=0,cur.n=1;
        s.insert(cur);
        ans=0;
        memset(vis,0,sizeof vis);
        while(s.size())
        {
            cur=*s.begin();
            s.erase(s.begin());
            if(vis[cur.n]) continue;
            vis[cur.n]=1;
            ans+=cur.c;
            for(int i=0;i<v[cur.n].size();i++)
            {
                nw.c=c[cur.n][i];
                nw.n=v[cur.n][i];
                if(!vis[v[cur.n][i]]) s.insert(nw);
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) v[i].clear(),c[i].clear();
        getline(cin,t);
    }while(getline(cin,t));

}
