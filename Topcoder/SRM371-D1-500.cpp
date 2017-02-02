#include<bits/stdc++.h>
using namespace std;
class ChessMatchup{
public :int maximumScore(vector <int> us, vector <int> them)
{
sort(us.begin(),us.end());
sort(them.begin(),them.end());
bool vis[55]={},v[55]={};
int s=0,idx;
for(int i=0;i<us.size();i++)
for(int j=0;j<us.size();j++)
if(us[i]>them[j]&&vis[j]==0) {
idx=lower_bound(us.begin(),us.end(),them[j])-us.begin();
if(us[idx]==them[j]&&v[idx]==0&&j!=us.size()-1&&us[i]>them[j+1]) continue;
s+=2;v[i]=1; vis[j]=1; break;
}


for(int i=0;i<us.size();i++)
for(int j=0;j<us.size();j++)
if(us[i]==them[j]&&vis[j]==0&&v[i]==0) {s+=1;v[i]=1; vis[j]=1; break;}
return s;
}
};
