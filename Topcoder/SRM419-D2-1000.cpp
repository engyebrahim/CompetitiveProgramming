/*
normal dfs but 
count for every node number of visiting after it being visited
if any node visited more than 1 the it not belong to simple cycle
*/
#include<bits/stdc++.h>
using namespace std;
bool v[201][201], vis[201];
int c[201],n;
class CactusCount
{
void fun(int node,int p)
{
if(vis[node]){ c[node]++; return;}
vis[node]=1;
for(int i=1;i<=n;i++)
if(v[node][i]&&i!=p) fun(i,node);
}
public:int countCacti(int u, vector <string> edges)
{
n=u;
string s;
for(int i=0;i<edges.size();i++) s+=edges[i];
stringstream ss;
s+=',';
ss<<s;
int x,y; char ch;
while(ss>>x){
ss>>y; ss>>ch;
v[x][y]=v[y][x]=1;
}
int ans=0; bool f;
memset(vis,0,sizeof vis);
for(int i=1;i<=n;i++){

memset(c,0,sizeof c);
if(!vis[i])
{
f=1;
fun(i,-1);
for(int j=1;j<=n;j++)
if(c[j]>=2) f=0;
if(f) ans++;
}
}
return ans;
}
};
