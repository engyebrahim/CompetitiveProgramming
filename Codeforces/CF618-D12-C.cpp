/*
sort all points
take the first two point 
find the first point is not colinear with them 
it will be the third point
output them
*/
#include<bits/stdc++.h>
using namespace std;
struct point
{
     long long x,y;
};
bool cmp(pair<point,int>a,pair<point,int>b)
{
     if(a.first.x!=b.first.x) return a.first.x<b.first.x;
     return  a.first.y<b.first.y;
}
int main() {
     int n;
     pair<point,int> p[100002];
     scanf("%d",&n);
     for(int i=0;i<n;i++){ 
          scanf("%lld%lld",&p[i].first.x,&p[i].first.y);
          p[i].second=i+1;
     }
     sort(p,p+n,cmp);
     point P=p[0].first,q=p[1].first,r;
     cout<<p[0].second<<" "<<p[1].second<<" ";
     for(int i=2;i<n;i++)
     {
          r=p[i].first;
          if((long long)(q.y - P.y) * (r.x - q.x) -(q.x - P.x) * (r.y - q.y)!=0)
          {
               cout<<p[i].second<<endl;
               break;
          }
     }
} 
