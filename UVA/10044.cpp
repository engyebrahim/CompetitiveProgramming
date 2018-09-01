//Disjoint Set
#include <bits/stdc++.h>
using namespace std;
int vis[100001];
vector<int>v[100001],g;
struct node
{
    int n,c;
};
int main()
{
    int t,p,n,idx,c;
    scanf("%d",&t);
    string s,k;
    node cur,nw;
    queue<node> q;
    map<string,int>m;
    bool f;
    int tc=1;
    while(t--)
    {
        scanf("%d%d",&p,&n);
        idx=1;
        getline(cin,s);
        while(p--)
        {
            getline(cin,s);
            c=0;
            f=1; k="";
            for(int i=0;f&&i<s.size();i++)
            {
                if(s[i]==',') c++;
                else if(s[i]==':') c++,f=0;
                k+=s[i];
                if(c==2) {
                    k=k.substr(0,k.size()-1);
                    if(!m[k]) m[k]=idx++;
                    g.push_back(m[k]);
                    k="";
                    i++;
                    c=0;
                }
            }
            for(int i=0;i<g.size();i++)
            {
                for(int j=0;j<g.size();j++)
                   if(i!=j) v[g[i]].push_back(g[j]);
            }
            g.clear();
        }
        cur.n=m["Erdos, P."];
        cur.c=0;
        q.push(cur);
        memset(vis,-1,sizeof vis);
        while(q.size())
        {
            cur=q.front();
            q.pop();
            if(vis[cur.n]!=-1) continue;
            vis[cur.n]=cur.c;
            for(int i=0;i<v[cur.n].size();i++)
            {
                nw.n=v[cur.n][i];
                nw.c=cur.c+1;
                q.push(nw);
            }
        }
        cout<<"Scenario "<<tc++<<endl;
        while(n--)
        {
            getline(cin,s);
            cout<<s<<" ";
            if(vis[m[s]]==-1) cout<<"infinity";
            else cout<<vis[m[s]];
            cout<<endl;
        }
        for(int i=1;i<idx;i++) v[i].clear();
        m.clear();
    }
}
