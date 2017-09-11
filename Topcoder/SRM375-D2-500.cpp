#include<bits/stdc++.h>
using namespace std;
class DukeOnChessBoard
{
    public:string dukePath(int n, string s)
    {
        string ans="";
        int vis[9][9]={},x,y, px[]={1,-1,0,0},py[]={0,0,1,-1};
        int a=s[0]-'a',b=s[1]-'0';
        queue<pair<int,int> >q;
        pair<int,int> cur,nw;
        q.push(make_pair(a,b));
        while(q.size())
        {
            cur=q.front();
            q.pop();
            if(vis[cur.first][cur.second]) continue;
            ans+=cur.first+'a';
            ans+=cur.second+'0';
            ans+='-';
            vis[cur.first][cur.second]=1;
            x=-1,y=-1;
            for(int i=0;i<4;i++)
            {
                nw.first=cur.first+px[i],nw.second=cur.second+py[i];
                if(nw.first<0||nw.first>=n||nw.second<=0||nw.second>n||vis[nw.first][nw.second]) continue;
                if(x<nw.first||x==nw.first&&y<nw.second) x=nw.first,y=nw.second;
            }
            if(x!=-1) q.push(make_pair(x,y));
        }
        if(ans.size()>41) ans=ans.substr(0,20)+"..."+ans.substr(ans.size()-21,20);
        else ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};
