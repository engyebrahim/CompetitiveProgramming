#include<bits/stdc++.h>
using namespace std;
int main(){
     int t,n;
     cin>>t;
     map<string ,int> name;
     map<int,int> m;
     map<int,int> o;
     map<int,int> ::iterator it;
     vector<vector<pair<int,int>> > v;
     int x,y,b; string s,k;
     int idx=1;
     int val,tmp,ans;
     int mx=2e+9,mn=0;
     while(t--)
     {
          v.clear(); m.clear();name.clear(); o.clear();
          cin>>n>>b;
          v.resize(n+1);
          idx=1;
          for(int i=0;i<n;i++)
          {
               cin>>s>>k>>x>>y;
               if(!name[s]) name[s]=idx++;
               v[name[s]].push_back(make_pair(x,y));
               m[y]=-1;
          }
          it=m.begin();
          n=idx;
          idx=1;
          while(it!=m.end())
          {
               o[idx]=it->first;
               it->second=idx;
               it++; idx++;
          }
          for(int i=1;i<n;i++)
          {
               for(int j=0;j<v[i].size();j++)
               {
                    v[i][j].second=m[v[i][j].second];
               }
          }
          for(int i=1;i<idx;i++)
          {
               tmp=b;
               for(int j=1;j<n;j++)
               {
                    val=2e+9;
                    for(int k=0;k<v[j].size();k++)
                    {
                         if(v[j][k].second>=i) val=min(v[j][k].first,val);
                    }
                    tmp-=val;
                    if(tmp<0) break;
               }
               if(tmp>=0) ans=i;
          }
          cout<<o[ans]<<endl;
     }
}
