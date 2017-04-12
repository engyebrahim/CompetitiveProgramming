/*
use maps to transform string to index and vice versa 
then get the articulation points
*/
#include<bits/stdc++.h>
using namespace std;
int n,arr[101][101],dfn[101],low[101],idx;
set<int> s;
bool root;
void fun(int node,int par,int p)
{
     dfn[node]=low[node]=idx++;
     for(int i=1;i<=n;i++)
     {
          if(arr[node][i]==0) continue;
          if(dfn[i]==-1)
          {
               fun(i,node,p);
               low[node]=min(low[i],low[node]);
               if(dfn[node]<=low[i])
               {
                    if(dfn[node]==p&&root==1) root=0;
                    else
                      s.insert(node);
               }
          }
          else if(node!= i)
             low[node]=min(low[node],dfn[i]);
     }
}
int main() {
     map<string,int> index;
     map<int,string> name;
     vector<string> v;
     string k,st;
     int c,x,y,r,tc=0;
     while(cin>>n&&n)
     {
          if(tc) cout<<endl;
          root=1;
          idx=1;
          c=1,tc++;
          memset(dfn,-1,sizeof dfn);
          for(int i=0;i<n;i++)
          {
                cin>>st;
                index[st]=c,name[c]=st,c++;
          }
          cin>>r;
          for(int i=0;i<r;i++)
          {
               cin>>st>>k;
               x=index[st],y=index[k];
               arr[x][y]=1,arr[y][x]=1;
          }
          for(int i=1;i<=n;i++) // graph might be not conected
          if(dfn[i]==-1)
          root=1,fun(i,-1,idx);
          cout<<"City map #"<<tc<<": "<<s.size()<<" camera(s) found"<<endl;
          while(s.size()){ v.push_back(name[*s.begin()]); s.erase(s.begin());} //set sort indexes not the strings
          sort(v.begin(),v.end());
          for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
          v.clear();
          name.clear();
          index.clear();
          memset(arr,0,sizeof arr);
     }
} 
