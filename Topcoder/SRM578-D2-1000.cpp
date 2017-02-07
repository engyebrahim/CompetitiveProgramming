#include<bits/stdc++.h>
using namespace std ;
vector<vector<int> >v(303,vector<int>());
int arr[303][303],n;
class WolfInZooDivTwo
{
int fun(int idx,int last)
{
if(idx>n) return 1;
if(arr[idx][last]!=-1)
return arr[idx][last];
int ret=fun(idx+1,idx)%1000000007;
bool f=1;
for(int i=0;i<v[idx].size();i++)
if(v[idx][i]>last) f=0;
if(f)
ret=(ret%1000000007+fun(idx+1,last)%1000000007)%1000000007;
return arr[idx][last]=ret;
}
public:int count(int N, vector <string> l, vector <string> r)
{
n=N;
stringstream sr,sl;
for(int i=0;i<l.size();i++) sl<<l[i];
for(int i=0;i<r.size();i++) sr<<r[i];
int x,y;
while(sl>>x)
{
sr>>y;
x++,y++;
v[y].push_back(x);
}
memset(arr,-1,sizeof arr);
return fun(1,0);
}

};
