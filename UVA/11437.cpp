#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x ,y ;
};

point get(point A,point B)
{
    point ret ;
    ret.x = (A.x-B.x)/3.0+B.x;
    ret.y = (A.y-B.y)/3.0+B.y;

    return ret ;
}

point find(point x1,point y1,point x2,point y2)
{
    point ret ;

    double A1 = y1.y-x1.y , B1 = x1.x-y1.x , C1 = A1*x1.x+B1*x1.y ; 
    double A2 = y2.y-x2.y , B2 = x2.x-y2.x , C2 = A2*x2.x+B2*x2.y ; 

    double det = A1*B2 - A2*B1 ;

    ret.x = (B2*C1-B1*C2)/det ;
    ret.y = (A1*C2-A2*C1)/det ;

    return ret ;
}

double area (point A , point B , point C)
{
    return fabs(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y))/2.0 ;
}

int main()
{
    int t ;
    scanf("%d",&t);
    while( t-- )
    {
        point a,b,c;
        scanf("%lf%lf",&a.x,&a.y);
        scanf("%lf%lf",&b.x,&b.y);
        scanf("%lf%lf",&c.x,&c.y);

        point d= get(c,b);
        point e= get(a,c);
        point f= get(b,a);

        point p= find(a,d,b,e);
        point q= find(c,f,b,e);
        point r= find(a,d,c,f);

        printf("%.0lf\n",area(p,q,r)) ;
    }
    return 0;
}
