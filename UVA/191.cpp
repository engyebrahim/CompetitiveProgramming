#include<bits/stdc++.h>
using namespace std;
struct Point
{
     int x,y;
};
Point r[4];
Point s[2];
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
int orientation(Point p, Point q, Point r)
{
     int val = (q.y - p.y) * (r.x - q.x)-(q.x - p.x) * (r.y - q.y) ;
 
    if (val == 0) return 0; 
 
    return (val > 0)? 1: 2; 
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}  

bool in(Point p)
{
     if(orientation(r[0],r[1],p)==orientation(r[1],r[2],p)
       &&orientation(r[1],r[2],p)==orientation(r[2],r[3],p)
       &&orientation(r[2],r[3],p)==orientation(r[3],r[0],p)) return 1;
        return 0;
}
bool fun()
{
     if(doIntersect(s[0],s[1],r[0],r[1])||
        doIntersect(s[0],s[1],r[1],r[2])||
        doIntersect(s[0],s[1],r[2],r[3])||
        doIntersect(s[0],s[1],r[3],r[0])||
        in(s[0])||in(s[1]))return 1;
        return 0;
}
int main(){
     int n;
     cin>>n;
     while(n--)
     {
          cin>>s[0].x>>s[0].y>>s[1].x>>s[1].y>>r[3].x>>r[3].y>>r[1].x>>r[1].y;
          r[0].x=r[3].x,r[0].y=r[1].y;
          r[2].x=r[1].x,r[2].y=r[3].y;
          if(fun()) cout<<"T\n";
          else cout<<"F\n";
     }
}
