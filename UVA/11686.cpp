//normal Topological sorting
#include<bits/stdc++.h>
using namespace std;
int main(){
     
     int n,m;
     int cnt[1000002];
     vector<vector<int> >v;
     vector<int> fin;
     while(cin>>n>>m&&n+m)
     {
          v.clear(); fin.clear();
          v.resize(n+1);
          memset(cnt,0,sizeof cnt);
          for(int i=0,x,y;i<m;i++)
          {
               cin>>x>>y;
               cnt[y]++;
               v[x].push_back(y);
          }
          for(int i=1;i<=n;i++)
          if(cnt[i]==0) fin.push_back(i);
          for(int i=0;i<fin.size();i++)
          {
               for(int j=0;j<v[fin[i]].size();j++)
               {
                    cnt[v[fin[i]][j]]--;
                    if(cnt[v[fin[i]][j]]==0) fin.push_back(v[fin[i]][j]);
               }
          }
          if(fin.size()!=n) cout<<"IMPOSSIBLE\n";
          else
          for(int i=0;i<fin.size();i++) 
          {
               cout<<fin[i]<<endl;
          }
     }
}
