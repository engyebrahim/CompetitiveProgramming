/*
we will conect the num of
for test 
  3 3 3
  1 1 1 1 
  2 2 2 2
  3 3 3 3
  this explain it
       f1 -> n1 -> n1 -> d1 \
     / 
   0 - f2 -> n2 -> n2 -> d2 - t
     \
       f3 -> n3 -> n3 -> d3 /
*/
#include<bits/stdc++.h>
using namespace std;
int arr[500][500];
bool vis[500];
int path[500],len;
bool getpath(int s,int e,int l)
{
     path[l]=s;
     if(s==e) {
          len=l+1;
          return 1;
     }
     int ret;
     vis[s]=1;
     for(int i=0;i<500;i++)
       if(!vis[i]&&arr[s][i]==1) 
         {
              ret=getpath(i,e,l+1);
              if(ret) return 1;
         }
     return 0;
}
int fun(int s,int e)
{
     int ret=0;
     while(1){
     memset(vis,0,sizeof vis);
     len=0;
     if(!getpath(s,e,0)) break;
     ret++;
     for(int x,y,i=1;i<len;i++){
       y=path[i],x=path[i-1];
       arr[x][y]--;
       arr[y][x]++;
     }
     }
     return ret;
}
int main() {
     int n,d,f,t;
     cin>>n>>f>>d;
     t=2*n+f+d+1; 
     for(int i=1;i<=f;i++)
       arr[0][i]=1;
     for(int x,y,z,i=0;i<n;i++)
     {
          cin>>x>>y;
          while(x--)
          {
               cin>>z;
               arr[z][1+f+i]=1;
          }
          arr[1+f+i][1+f+n+i]=1;
          while(y--)
          {
               cin>>z;
               arr[1+f+n+i][f+2*n+z]=1;   // input base one so we don't need +1
          }
     }
     for(int i=1;i<=d;i++)
       arr[n*2+f+i][t]=1;
     cout<<fun(0,t)<<endl;
}
