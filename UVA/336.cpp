#include <bits/stdc++.h>
using namespace std;
vector<int> v[32];
int ans[32][32];
struct node
{
    int n,c;
};
int main()
{
    int n,x,y,idx,z,c,tc=1;
    map<int,int>m;
    queue<node> q;
    node cur,nw;
    while(scanf("%d",&n)==1&&n)
    {
        idx=1;
        while(n--)
        {
            scanf("%d%d",&x,&y);
            if(!m[x]) m[x]=idx++;
            if(!m[y]) m[y]=idx++;
            x=m[x],y=m[y];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(ans,-1,sizeof ans);
        for(int i=1;i<idx;i++)
        {
            cur.n=i,cur.c=0;
            q.push(cur);
            while(q.size())
            {
                cur=q.front();
                q.pop();
                if(ans[i][cur.n]!=-1) continue;
                ans[i][cur.n]=cur.c;
                for(int j=0;j<v[cur.n].size();j++)
                {
                    if(ans[i][v[cur.n][j]]==-1)
                    {
                        nw.c=cur.c+1;
                        nw.n=v[cur.n][j];
                        q.push(nw);
                    }
                }
            }
        }
        while(scanf("%d%d",&x,&y)==2&&x+y)
        {
            c=0;
            z=m[x];
            for(int i=1;i<idx;i++)
                if(ans[z][i]>y||ans[z][i]==-1) c++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,c,x,y);

        }
        m.clear();
        for(int i=1;i<idx;i++) v[i].clear();
    }

}
