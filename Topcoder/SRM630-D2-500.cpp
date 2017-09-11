#include<bits/stdc++.h>
using namespace std;
bool vis[11]; int dis[11][11],x,N,mx;
vector<vector<int> >v,c;
class Egalitarianism3Easy
{
    void fun(int node,int d)
    {
        vis[node]=1;
        dis[x][node]=d;
        for(int i=0;i<v[node].size();i++)
        {
            if(!vis[v[node][i]]) fun(v[node][i],d+c[node][i]);
        }
    }
    void culc(int node)
    {
        if(node==N+1)
        {
            int g=0,d=-1;
            for(int i=1;i<=N;i++)
                if(vis[i]) g++;
            if(g>2)
                for(int i=1;i<=N;i++)
                    if(vis[i])
                        for(int j=i+1;j<N+1;j++)
                            if(vis[j])
                                if(d==-1) d=dis[i][j];
                                else if(d!=dis[i][j]) return;

            mx=max(mx,g);
            return;
        }
        culc(node+1);
        vis[node]=1;
        culc(node+1);
        vis[node]=0;
    }
    public:int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
    {
        N=n;
        v.resize(n+1);
        c.resize(n+1);
        for(int i=0;i<a.size();i++)
        {
            v[a[i]].push_back(b[i]);
            v[b[i]].push_back(a[i]);
            c[a[i]].push_back(len[i]);
            c[b[i]].push_back(len[i]);
        }
        for(int i=1;i<=n;i++) {memset(vis,0,sizeof vis); x=i,fun(x,0);}
        memset(vis,0,sizeof vis);
        mx=-1;
        culc(1);
        return mx;
    }
};

