/*
use normal bfs with small edits
use node and its parent to access vis array  and parent array
*/
#include<bits/stdc++.h>
using namespace std;
int n, x,y;
int parent [3003][3003];  // to find path
bool vis[3003][3003];   
vector<vector<int> >v(3003,vector<int>());
set<pair<int,pair<int,int>>> s;  //  save  forbidden triplets
struct node{
     int pp,p,x,c;  //x cur node ,c saves cost, p saves parent and pp saves grandparent
};
void fun(){
     node cur,nw;
     queue<node> q;
     cur.pp=1,cur.x=1,cur.p=1,cur.c=0;
     q.push(cur);
     int ans=1e+9;
     while(q.size())
     {
          cur=q.front();
          q.pop();
          if(vis[cur.p][cur.x]) continue;
          vis[cur.p][cur.x]=1;
          parent[cur.p][cur.x]=cur.pp;  
          if(cur.x==n) {
               ans=cur.c;
               x=cur.p;
               break;
          }
          for(int i=0;i<v[cur.x].size();i++){
          if(s.find(make_pair(cur.p,make_pair(cur.x,v[cur.x][i])))!=s.end()) continue;
          nw.pp=cur.p,nw.p=cur.x,nw.x=v[cur.x][i],nw.c=cur.c+1;
          q.push(nw);
          }
     }
     if(ans==1e+9) {
          cout<<-1<<endl;
          return;
     }
     cout<<ans<<endl;
     vector<int> a; int tmp;
     y=n;
     a.push_back(y);
     while(1)
     {
          a.push_back(x);
          if(x==1) break;
          tmp=x;
          x=parent[x][y];
          y=tmp;
     }
     for(int i=a.size()-1;i>=0;i--)
      cout<<a[i]<<" ";
      cout<<endl;
}
int main() {
    int m,k;
    cin>>n>>m>>k;
    while(m--)
    {
         cin>>x>>y;
         v[x].push_back(y);
         v[y].push_back(x);
    }
    int z;
    while(k--)
    {
         cin>>x>>y>>z;
         s.insert(make_pair(x,make_pair(y,z)));
    }
    fun();
}
