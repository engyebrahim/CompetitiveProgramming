#include<bits/stdc++.h>
using namespace std;
class FoxStones
{public:
int getCount(int N, int M, vector <int> sx, vector <int> sy)
{
vector<vector<int> > v(20001,vector<int>() );
int idx=0;
bool vis[202][202]={};

for(int l=0;l<sx.size();l++)
vis[sx[l]][sy[l]]=1;

for(int i=1;i<=N;i++)
for(int j=1;j<=M;j++)
{
if(vis[i][j]) continue;

for(int l=0;l<sx.size();l++)
v[idx].push_back(max(abs(i-sx[l]),abs(j-sy[l])));

idx++;
}
sort(v.begin(),v.begin()+idx);
long long ans=1,j=1;
for(int i=0;i<idx;i++){
if(!i||v[i]!=v[i-1])
j=1;
else j++;
ans=(j%1000000009*ans%1000000009)%1000000009;
}
return ans;
}
};
