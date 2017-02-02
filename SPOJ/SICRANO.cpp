#include <bits/stdc++.h>
using namespace std;
struct point
{
     double x,y;
};
struct seg
{
     double x,y,a,b;
};
point p[55];
seg s[55];
bool IsOnLine(int i,int j)
{
     
     double m1=(p[j].y-s[i].b)/(p[j].x-s[i].a),
            m2=(s[i].y-s[i].b)/(s[i].x-s[i].a),
            l1=sqrt((s[i].x-s[i].a)*(s[i].x-s[i].a)+(s[i].y-s[i].b)*(s[i].y-s[i].b)),
            l2=sqrt((p[j].x-s[i].a)*(p[j].x-s[i].a)+(p[j].y-s[i].b)*(p[j].y-s[i].b)),
            l3=sqrt((p[j].x-s[i].x)*(p[j].x-s[i].x)+(p[j].y-s[i].y)*(p[j].y-s[i].y));
     if(m1==m2&&l1==l2+l3)
     return 1;
     if((p[j].x==s[i].x&&p[j].y==s[i].y)||(p[j].x==s[i].a&&p[j].y==s[i].b))
        return 1;
   return 0;
}
int main()
{
   int t,n,m,sum;
   cin>>t;
   while(t--)
   {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
         scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=0;i<m;i++)
          scanf("%lf%lf%lf%lf",&s[i].x,&s[i].y,&s[i].a,&s[i].b);
        for(int i=0;i<m;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            if(IsOnLine(i,j)) sum++;
            printf("%d\n",sum);
        }
        
   }
     
} 
