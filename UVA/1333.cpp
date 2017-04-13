/*
editorial :https://wcr1996.com/2016/09/25/uva-1333-model-rocket-height/
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
     double h,d,a,b,c;
     scanf("%lf%lf",&d,&h);
     while(scanf("%lf%lf%lf",&a,&b,&c)&&a>0&&b>0&&c>0)
     {
          a=tan(a*acos(-1)/180),b=tan(b*acos(-1)/180),c=tan(c*acos(-1)/180);
          cout<<round(sqrt(2/(1/a/a+1/c/c-2/b/b))*d+h)<<endl;
     }
} 
