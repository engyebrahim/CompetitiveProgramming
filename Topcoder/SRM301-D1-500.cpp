#include<bits/stdc++.h>
using namespace std ;
bool vis[55];
vector<vector<int > >v(55,vector<int>());
map<char,int>m;
int n;
class EscapingJail
{
void dfs(int node)
{
vis[node]=1;
for(int i=0;i<n;i++)
if(v[node][i]!=-1&&vis[i]==0) dfs(i);
}


public:int getMaxDistance(vector <string> chain)
{
n=chain.size();
m[' ']=-1;
for(int i=0;i<10;i++) m[char(i+'0')]=i;
for(int j=0,i=10;i<36;j++,i++) m[char(j+'a')]=i;
for(int j=0,i=36;i<62;j++,i++) m[char(j+'A')]=i;

for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
      v[i].push_back(m[chain[i][j]]); 

dfs(0);
for(int i=0;i<n;i++)
  if(!vis[i]) return -1;

int mx=-1;
for(int k=0;k<n;k++)
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
        if(i==j||j==k||i==k) continue;
        else if(v[i][k]!=-1&&v[k][j]!=-1) v[i][j]=(v[i][j]!=-1)?min(v[i][j],v[i][k]+v[k][j]):v[i][k]+v[k][j];
for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
mx=max(mx,v[i][j]); 
return mx;

}
};
