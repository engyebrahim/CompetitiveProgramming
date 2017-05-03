//http://www.voidcn.com/blog/ck_boss/article/p-2571324.html
#include<bits/stdc++.h>
using namespace std;
struct Point
{
     double x,y;
};
Point p[55];
int n;
double dp[55][55];
double ccw(int i,int j,int k)
{
     return fabs((p[j].x-p[i].x)*(p[k].y-p[j].y)-(p[j].y-p[i].y)*(p[k].x-p[j].x))*.5;
};
double fun(int l,int r)
{
     double a,b,tmp=1e+9; bool f;
     if(l+1==r) return 0;
     if(dp[l][r]>1e-9) return dp[l][r];
     for(int i=l+1;i<r;i++)
     {
          a=ccw(i,l,r);
          f=1;
          for(int j=0;j<n;j++)
          {
               if(i==j||l==j||r==j) continue;
               b=ccw(i,l,j)+ccw(i,j,r)+ccw(j,l,r);
               if(fabs(a-b)<1e-9) f=0;
          }
          if(f) tmp=min(tmp,max(a,max(fun(l,i),fun(i,r))));
     }
     return dp[l][r]=tmp;
}
int main(){
     int t;
     cin>>t;
     while(t--)
     {
          cin>>n;
          for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
          
          for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
               dp[i][j]=-1;
               
          printf("%.1lf\n",fun(0,n-1));
     }
}
