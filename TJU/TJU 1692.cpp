/*
1- if n=0|| n=1 answer is n
2- if graph is not conected answer 0
3- for node n,m,k , n have cable to  m , m have cable to k 
    and k dont have cable to n or other m nodes then number of min k is the answer 
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >v;
bool vis[55];
bool dfs(int node)
{
     vis[node]=1;
     for(int i=0;i<v[node].size();i++){
          if(!vis[v[node][i]]) dfs(v[node][i]);
     }
}
int main() {
    int n,m;
    
    char c;
    while(cin>>n>>m){
    memset(vis,0,sizeof vis);
    v.clear();
    v.resize(n);
    char s[1000];
    for(int x,y,i=0;i<m;i++){
        scanf("%s",s);
	    sscanf(s,"(%d,%d)",&x,&y);
         v[x].push_back(y);
         v[y].push_back(x);
    }
    int mn=1e+9,cur; bool f=0;
    if(n==1||n==0) {cout<<n<<endl; continue;}
    dfs(0);
    for(int i=0;i<n;i++)
       if(vis[i]==0) f=1;
    if(f) {cout<<0<<endl; continue;}
    int k;
    for(int i=0;i<n;i++)
         sort(v[i].begin(),v[i].end());
    for(int i=0;i<n;i++)
    {
         k=0; 
              for(int j=0;j<v[i].size();j++)
              {
                   cur=v[i][j];
                   f=0;
                   for(int k=0;k<v[cur].size();k++)
                   {
                        if(!binary_search(v[i].begin(),v[i].end(),v[cur][k])&&v[cur][k]!=i)
                          f=1;
                   }
                   if(f) k++;
              }
         if(k) mn=min(mn,k);
         
    }
    if(mn==1e+9) mn=n;
    cout<<mn<<endl;
    
  }
     
}
