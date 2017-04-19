/*
-find all bcc 
-check if bcc has odd cycles (bipartite graph has only even cycles)
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,dfn[1002],low[1001],idx,clr[1001],bi_clr[1001];
bool arr[1001][1001];
vector<vector<int> >v,bc;
stack<pair<int,int> > s;
pair<int,int> cur;
void bcc(int p,int node)
{
     dfn[node]=low[node]=idx++;
     int ch;
     for(int i=0;i<v[node].size();i++)
     {
          ch=v[node][i];
          if(dfn[node]>dfn[ch])  s.push(make_pair(node,ch));
          if(dfn[ch]==-1)
          {
               bcc(node,ch);
               low[node]=min(low[node],low[ch]);
               if(dfn[node]<=low[ch])
               {
                    bc.push_back(vector<int>());
                    do
                    {
                         cur=s.top();
                         s.pop();
                         bc[bc.size()-1].push_back(cur.second);
                    }while(cur!=make_pair(node,ch));
               }
          }
          else if(ch!=p) low[node]=min(low[node],dfn[ch]);
     }
}
bool bi(int node)
{
     bool ans=1;
     for(int i=0;i<v[node].size();i++)
     {
          if(clr[node]!=clr[v[node][i]]) continue;
          if(bi_clr[v[node][i]]==-1)
          {
               bi_clr[v[node][i]]=!bi_clr[node];
               ans*=bi(v[node][i]);
          }
          else if(bi_clr[node]==bi_clr[v[node][i]])return 0;
     }
     return ans;
}
int main(){
     int ans,vis[1001];
     while(scanf("%d%d",&n,&m)&&n+m)
     {
          ans=n;
          memset(arr,0,sizeof arr);
          memset(vis,0,sizeof vis);
          memset(dfn,-1,sizeof dfn);
          v.clear(); v.resize(n+1); bc.clear();
          for(int x,y,i=0;i<m;i++)
          {
               scanf("%d%d",&x,&y);
               arr[x][y]=arr[y][x]=1;
          }
          for(int i=1;i<=n;i++)
           for(int j=1;j<=n;j++)
            if(i!=j&&!arr[i][j]) v[i].push_back(j);
          idx=1;
          for(int i=1;i<=n;i++) bcc(-1,i);
          
          for(int i=0;i<bc.size();i++)
          {
               memset(bi_clr,-1,sizeof bi_clr);
               memset(clr,-1,sizeof clr);
               for(int j=0;j<bc[i].size();j++) clr[bc[i][j]]=i;
               bi_clr[bc[i][0]]=0;
               if(!bi(bc[i][0]))
                 for(int j=0;j<bc[i].size();j++)
                   vis[bc[i][j]]=1;
          }
          for(int i=1;i<=n;i++) if(vis[i]) ans--;
          printf("%d\n",ans);
     }
     
}
