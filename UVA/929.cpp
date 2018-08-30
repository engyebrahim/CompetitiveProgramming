#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
struct node
{
    int i,j;
    long long c;
};
bool operator<(node a,node b)
{
    if(a.c!=b.c) return a.c<b.c;
    if(a.i!=b.i) return a.i<b.i;
    return a.j<b.j;
}
int x[]={1,-1,0,0},y[]={0,0,1,-1};
bool vis[1000][1000];
int main()
{
    int t,n,m;
    long long ans;
    scanf("%d",&t);
    node cur,nw;
    set<node> s;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
              scanf("%d",&arr[i][j]);
        cur.i=cur.j=0,cur.c=arr[0][0];
        memset(vis,0,sizeof vis);
        ans=0;
        s.insert(cur);
        while(s.size())
        {
            cur=*s.begin();
            s.erase(s.begin());
            if(vis[cur.i][cur.j]) continue;
            if(cur.i==n-1&&cur.j==m-1)
            {
                ans=cur.c;
                break;
            }
            vis[cur.i][cur.j]=1;
            for(int i=0;i<4;i++)
            {
                nw.i=cur.i+x[i];
                nw.j=cur.j+y[i];
                if(nw.i>=0&&nw.i<n&&nw.j>=0&&nw.j<m&&!vis[nw.i][nw.j])
                {
                    nw.c=arr[nw.i][nw.j]+cur.c;
                    s.insert(nw);
                }
            }
        }
        s.clear();
        printf("%lld\n",ans);
    }
}
