/*
we have two cases 
1- if empty creat traingle then we will complete its Parallel rectangles calculate its half voluam and substruct it from the total V
2- if milke creat traingle then calculate its v 
in each case only one distance change from tne big Parallel rectangles to the small and we will use the angle and Sin role to calculate it
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
     double l,w,h,c,c2,v,h2,l2;
     while(~scanf("%lf%lf%lf%lf",&l,&w,&h,&c))
     {
          v=l*w*h;
          c2=(90-c)*acos(-1)/180;
          c=c*acos(-1)/180;
          h2=l*sin(c)/sin(c2);
          if(h2>h)
          {
                l2=h*sin(c2)/sin(c);
                printf("%.3lf mL\n",l2*w*h/2);
          }
          else
          printf("%.3lf mL\n",v-l*w*h2/2);
     }
}
