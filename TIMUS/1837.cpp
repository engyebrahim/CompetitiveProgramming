#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> >v;
map<string ,int> num;
struct node
{
  int idx,c;   
};
int main(){
     cin>>n;
     string a,b,c;
     int idx=1;
     v.resize(400);
     bool f=0;
     for(int i=0;i<n;i++)
     {
          cin>>a>>b>>c;
          if(num[a]==0) num[a]=idx++;
          if(num[b]==0) num[b]=idx++;
          if(num[c]==0) num[c]=idx++;
          v[num[a]].push_back(num[b]); v[num[a]].push_back(num[c]);
          v[num[b]].push_back(num[a]); v[num[b]].push_back(num[c]);
          v[num[c]].push_back(num[a]); v[num[c]].push_back(num[b]);
          if(a=="Isenbaev"||b=="Isenbaev"||c=="Isenbaev") f=1;
     }
     int vis[400];
     memset(vis,-1,sizeof vis);
     queue<node> q;
     node cur,nw;
     
     if(f) {
          cur.idx=num["Isenbaev"];
          cur.c=0;
          q.push(cur);
     }
     while(q.size())
     {
          cur=q.front();
          q.pop();
          if(vis[cur.idx]!=-1) continue;
          vis[cur.idx]=cur.c;
          for(int i=0;i<v[cur.idx].size();i++)
          {
               nw.idx=v[cur.idx][i],nw.c=cur.c+1;
               q.push(nw);
          }
     }
     map<string ,int>::iterator it=num.begin();
     while(it!=num.end())
     {
          cout<<it->first<<" ";
          if(vis[it->second]==-1) cout<<"undefined"<<endl;
          else cout<<vis[it->second]<<endl;
          it++;
     }
     
}
