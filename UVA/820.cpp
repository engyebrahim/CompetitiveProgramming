#include <bits/stdc++.h>
using namespace std;
int n,arr[101][101],vis[101],path[101];
int len;
int getpath(int s,int e,int l,int ans)
{
     path[l]=s;
     if(s==e)
     {
        len=l+1;
        return ans;
     }
     int ret=0;
     vis[s]=1;
     for(int i=0;i<n;i++)
     {
          if(vis[i]||arr[s][i]<=0) continue;
          ret=getpath(i,e,l+1,min(ans,arr[s][i]));
          if(ret>0) break; 
     }
     return ret;
}
int fun(int s,int e)
{
     int flow=0,p;
     while(1)
     {
          memset(vis,0,sizeof vis);
          p=getpath(s,e,0,1e+9);
          if(!p) break;
          for(int a,b,i=1;i<len;i++)
          {
               b=path[i],a=path[i-1];
               arr[a][b]-=p;
               arr[b][a]+=p;
          }
          flow+=p;
     }
     return flow;
}
int main()
{
     int x,y,z,c,s,e,tc=1;
     while(cin>>n&&n)
     {
          cin>>s>>e>>c;
          s--,e--;
          memset(arr,0,sizeof arr);
          while(c--)
          {
               cin>>x>>y>>z;
               x--,y--;
               arr[x][y]+=z;
               arr[y][x]+=z;
          }
          cout<<"Network "<<tc++<<endl<<"The bandwidth is ";
          cout<<fun(s,e)<<"."<<endl<<endl;;
     }
}
