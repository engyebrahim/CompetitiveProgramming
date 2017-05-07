#include<bits/stdc++.h>
using namespace std;
class GridPointsOnCircle
{
     public:int countPoints(int r)
     {
          int ans=0,k,s;
          for(int i=0;i*i<=r;i++)
          {
               k=r-i*i;
               s=sqrt(k);
               if(abs(s*s-k)<1e-9) ans+=(i!=0)?2:0,ans+=(r-i*i!=0)?2:0;
          }
          return ans;
     }
};
