//editorial : http://onlycodes.tumblr.com/post/56218925524/uva-11130-billiard-bounces
#include <bits/stdc++.h>
using namespace std;

int main() {
     double a,b,v,A,s,d,H,V;
     while(scanf("%lf%lf%lf%lf%lf",&a,&b,&v,&A,&s)&&a+b+v+A+s)
     {
          A=A*acos(-1)/180;
          d=v*s/2;
          V=a/2+d*cos(A);
          H=b/2+d*sin(A);
          printf("%d %d\n",(int)(V/a),(int)(H/b));
     }
}
