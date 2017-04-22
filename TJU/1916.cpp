#include<bits/stdc++.h>
using namespace std;
double ccw(int x,int y,double a,double b,int f,int s)
{
    return (a-x)*(s-y)-(b-y)*(f-x) ;
}
int main(){
     vector<pair<int,int> > v;
     int x,y,a,b,n,ans,c; double nx,ny,r;
     while(cin>>x>>y>>r&&r>0)
     {
          cin>>n;
          while(n--){
               cin>>a>>b;
          if((a-x)*(a-x)+(b-y)*(b-y)<=r*r) v.push_back(make_pair(a,b));
          }
          ans=0;
          for(double i=0;i<=180;i+=.1)
          {
               ny=r*sin(i*acos(-1)/180)+y,nx=r*cos(i*acos(-1)/180)+x; // center not the origin
               c=0;
               for(int j=0;j<v.size();j++)
               {
                    if(ccw(x,y,nx,ny,v[j].first,v[j].second)+1e-9>=0) c++;
               }
               ans=max(ans,c);
          }
          cout<<ans<<endl;
          v.clear();
     }
}
