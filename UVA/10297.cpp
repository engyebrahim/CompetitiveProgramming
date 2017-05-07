/*
Volume of cylinder is: pi * r^2 * height
Volume of cone is: 1/3 * pi * r^2 * height
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
     
     int d,v;
     double cl,cn,r;
     while(cin>>d>>v&&d+v)
     {
          cl=acos(-1)*(d/2.0)*(d/2.0)*d;
          cn=2*acos(-1)*(1/3.0)*(d/2.0)*(d/2.0)*(d/2.0);
          r=cl-cn-v;
          printf("%.3lf\n",cbrt((r*6)/acos(-1)));
     }
}
