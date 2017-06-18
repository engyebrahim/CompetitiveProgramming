#include<bits/stdc++.h>
using namespace std;
int main()
{
     int t;
     cin>>t;
     double x1,y1,a1,b1,x2,y2,a2,b2,i1,j1,k1,i2,j2,k2,n1,n2;
     while(t--)
     {
          cin>>x1>>y1>>a1>>b1>>x2>>y2>>a2>>b2;
          if(abs((y1-y2)*(a1-x2)-(x1-x2)*(b1-y2))<1e-9&&((a1>=min(x1,x2)&&a1<=max(x1,x2)&&b1>=min(y1,y2)&&b1<=max(y1,y2))
          ||(x2>=min(x1,a1)&&x2<=max(x1,a1)&&y2>=min(y1,b1)&&y2<=max(y1,b1)))) n1=0;
          else if(abs((y1-y2)*(a1-x2)-(x1-x2)*(b1-y2))<1e-9) n1=acos(-1.0);
          else{
               i1=sqrt((x1-a1)*(x1-a1)+(y1-b1)*(y1-b1));
               j1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
               k1=sqrt((x2-a1)*(x2-a1)+(y2-b1)*(y2-b1));
               n1=acos((i1*i1+j1*j1-k1*k1)/(2*i1*j1));
          }
          if(abs((y1-y2)*(a2-x2)-(x1-x2)*(b2-y2))<1e-9&&((a2>=min(x1,x2)&&a2<=max(x1,x2)&&b2>=min(y1,y2)&&b2<=max(y1,y2))
          ||(x1>=min(x2,a2)&&x1<=max(x2,a2)&&y1>=min(y2,b2)&&y1<=max(y2,b2)))) n2=0;
          else if(abs((y1-y2)*(a2-x2)-(x1-x2)*(b2-y2))<1e-9) n2=acos(-1.0);
          else
          {
              i2=sqrt((x2-a2)*(x2-a2)+(y2-b2)*(y2-b2));
              j2=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
              k2=sqrt((x1-a2)*(x1-a2)+(y1-b2)*(y1-b2));
              n2=acos((i2*i2+j2*j2-k2*k2)/(2*i2*j2));
          }
          if(abs(n1-n2)<1e-5) cout<<0<<endl;
          else if(n1<n2) cout<<"Hero\n";
          else cout<<"Heroine\n";
     }
}
