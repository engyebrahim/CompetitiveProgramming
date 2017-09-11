#include<bits/stdc++.h>
using namespace std;
class LightsCube
{
    struct node
    {
        int x,y,z,c;
    };
    int px[6]={1,-1,0,0,0,0},py[6]={0,0,1,-1,0,0}, pz[6]={0,0,0,0,1,-1};
    public:vector <int> count(int n, vector <string> s)
    {
        vector<int> ans(s.size(),0);
        bool vis[41][41][41]={};
        stringstream ss;
        queue<node> q;
        node cur,nw;
        for(int i=0;i<s.size();i++)
        {
            ss.clear();
            ss<<s[i];
            ss>>cur.x>>cur.y>>cur.z;
            cur.c=i;
            //cout<<cur.x<<" "<<cur.y<<" "<<cur.z<<" "<<cur.c<<endl;
            q.push(cur);
        }
        while(q.size())
        {
            cur=q.front();
            q.pop();
            if(vis[cur.x][cur.y][cur.z]) continue;
            vis[cur.x][cur.y][cur.z]=1;
            ans[cur.c]++;
            for(int i=0;i<6;i++)
            {
                nw.x=cur.x+px[i],nw.y=cur.y+py[i],nw.z=cur.z+pz[i];
                if(nw.x<0||nw.x>=n||nw.y<0||nw.y>=n||nw.z<0||nw.z>=n) continue;
                nw.c=cur.c;
                q.push(nw);
            }
        }
        //for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
        return ans;
    }
};
