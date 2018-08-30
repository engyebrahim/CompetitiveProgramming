//Disjoint Set
#include <bits/stdc++.h>
using namespace std;
bool vis[8][8];
struct node
{
    int x,y,c;
};
int x[]={-1,1,-1,1,2,2,-2,-2},y[]={2,2,-2,-2,1,-1,1,-1};
int main()
{
    string s,k;
    node cur,nw,d;
    queue<node> q;
    while(cin>>s>>k)
    {
        d.x=k[0]-'a',d.y=k[1]-'1';
        cur.x=s[0]-'a';
        cur.y=s[1]-'1';
        cur.c=0;
        q.push(cur);
        memset(vis,0,sizeof vis);
        while(q.size())
        {
            cur=q.front();
            q.pop();
            if(vis[cur.x][cur.y]) continue;
            vis[cur.x][cur.y]=1;
            if(cur.x==d.x&&cur.y==d.y) {d.c=cur.c; break;}
            for(int i=0;i<8;i++)
            {
                nw.x=cur.x+x[i];
                nw.y=cur.y+y[i];
                nw.c=cur.c+1;
                if(nw.x>=0&&nw.x<8&&nw.y>=0&nw.y<8&&!vis[nw.x][nw.y])
                    q.push(nw);
            }
        }
        while(q.size()) q.pop();
        cout<<"To get from "<<s<<" to "<<k<<" takes "<<d.c<<" knight moves.\n";
    }
}
