//articulation point
#include<bits/stdc++.h>
using namespace std;
int n,arr[101][101],dfn[101],low[101],idx;
set<int> s;
bool root;
void fun(int node,int par)
{
     dfn[node]=low[node]=idx++;
     for(int i=1;i<=n;i++)
     {
          if(arr[node][i]==0) continue;
          if(dfn[i]==-1)
          {
               fun(i,node);
               low[node]=min(low[i],low[node]);
               if(dfn[node]<=low[i])
               {
                    if(dfn[node]==1&&root==1) root=0;
                    else
                      s.insert(node);
               }
          }
          else if(node!= i)
             low[node]=min(low[node],dfn[i]);
     }
}
int main() {
     int x,y;
     string k;
     stringstream ss;
     while(cin>>n&&n)
     {
          root=1;
          idx=1;
          memset(dfn,-1,sizeof dfn);
          getline(cin,k);
          while(getline(cin,k)&&k!="0")
          {
               ss<<k;
               ss>>y; 
               while(ss>>x) arr[y][x]=1,arr[x][y]=1;
               ss.clear();
          }
          fun(1,-1);
          cout<<s.size()<<endl;
          s.clear();
          memset(arr,0,sizeof arr);
     }
} 
