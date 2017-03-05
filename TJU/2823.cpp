/*
1- make start node conected with all food nodes
2- put given pathes from food nodes to cow nodes
3- make a copy from cow nodes then conect every node with its copy
4- path from each copy node to its drink nodes 
5- finally path from each drink node to the end node
all costs =1
note,
path from cow nodes to its copy ,for take the same node once

for test 
  4 3 3
  2 2 1 2 3 1
  2 2 2 3 1 2
  2 2 1 3 1 2
  2 1 1 3 3 
 
       f1  n1 -> n1  d1 
     /                \
  0 -> f2  n2 -> n2  d2 -> t
     \                /
       f3  n3 -> n3  d3

           n4 -> n4  
   then from fi put given pathies to ni and from copy of ni put given pathes to di
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
     t=f+2*n+d+1;  
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
