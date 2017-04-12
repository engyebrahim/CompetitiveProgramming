//bridges
#include<bits/stdc++.h>
using namespace std;
int n,dfn[102],low[102],v[102][102];
vector<pair<int,int> >ans;
int idx;
void fun(int node,int per)
{
     
     low[node]=dfn[node]=idx++;
     for(int i=0;i<n;i++)
     {
          if(v[node][i]==0) continue;
          if(dfn[i]==-1)
          {
               fun(i,node);
               low[node]=min(low[node],low[i]);
               if(dfn[node]<low[i]) ans.push_back(make_pair(min(node,i),max(node,i)));
          }
          else if(i!=per) low[node]=min(low[node],dfn[i]);
     }
}
int main() {
     int x,y,m;
     while(cin>>n)
     {
          idx=1;
          memset(dfn,-1,sizeof dfn);
          memset(v,0,sizeof v);
          for(int i=0;i<n;i++)
          {
               scanf("%d ", &x);
			         scanf("(%d)", &m);
               while(m--)
               {
                    cin>>y;
                    v[x][y]=v[y][x]=1;
               }
          }
          for(int i=0;i<n;i++)
           if(dfn[i]==-1) fun(i,-1);
          cout<<ans.size()<<" critical links"<<endl;
          sort(ans.begin(),ans.end());
          for(int i=0;i<ans.size();i++)
          cout<<ans[i].first<<" - "<<ans[i].second<<endl;
          cout<<endl;
          ans.clear();
     }
} 
