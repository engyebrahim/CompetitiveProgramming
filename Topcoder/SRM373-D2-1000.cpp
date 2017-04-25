/*
first case 
for every rectangle if any end poit inside it (check by cross product) sum its area and mark it as visited
second case
1- if rec is not visited and a point exist in any of its sides
2- if rec is not vis and any of its sides intersect with any segment
*/
#include<bits/stdc++.h>
using namespace std;
struct point
{
int x,y;
};
struct rec
{
point p1,p2,p3,p4;
};
struct seg
{
point p1,p2;
};
vector<rec> r;
vector<seg> s;
vector<bool >vis;
int ccw(point p,point q,point r)
{
int val= (q.x - p.x) * (r.y - q.y)-(q.y - p.y) * (r.x - q.x) ;
if (val>0) return 1;
else if(val<0) return -1;
else return 0;
}
bool on(point p, point r, point q)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
bool inter(point p1, point q1, point p2, point q2)
{
    int o1 = ccw(p1, q1, p2);
    int o2 = ccw(p1, q1, q2);
    int o3 = ccw(p2, q2, p1);
    int o4 = ccw(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;

    return false; 
}
int fun1()
{
int ans=0;
for(int i=0;i<s.size();i++)
{
for(int j=0;j<r.size();j++)
if(!vis[j]&&((ccw(r[j].p1,r[j].p2,s[i].p1)>0&&ccw(r[j].p2,r[j].p3,s[i].p1)>0&&
ccw(r[j].p3,r[j].p4,s[i].p1)>0&&ccw(r[j].p4,r[j].p1,s[i].p1)>0)||
(ccw(r[j].p1,r[j].p2,s[i].p2)>0&&ccw(r[j].p2,r[j].p3,s[i].p2)>0&&
ccw(r[j].p3,r[j].p4,s[i].p2)>0&&ccw(r[j].p4,r[j].p1,s[i].p2)>0)))
{
vis[j]=1;
ans+=(r[j].p2.x-r[j].p1.x)*(r[j].p3.y-r[j].p2.y);
}
}
return ans;
}
int fun2()
{
int ans=0;
for(int i=0;i<s.size();i++)
{
for(int j=0;j<r.size();j++)
if(!vis[j]&&((on(r[j].p1,r[j].p2,s[i].p1)>0||on(r[j].p2,r[j].p3,s[i].p1)>0||
on(r[j].p3,r[j].p4,s[i].p1)>0||on(r[j].p4,r[j].p1,s[i].p1)>0||
on(r[j].p1,r[j].p2,s[i].p2)>0||on(r[j].p2,r[j].p3,s[i].p2)>0||
on(r[j].p3,r[j].p4,s[i].p2)>0||on(r[j].p4,r[j].p1,s[i].p2)>0)||
(inter(r[j].p1,r[j].p2,s[i].p1,s[i].p2)>0||inter(r[j].p2,r[j].p3,s[i].p1,s[i].p2)>0||
inter(r[j].p3,r[j].p4,s[i].p1,s[i].p2)>0||inter(r[j].p4,r[j].p1,s[i].p1,s[i].p2)>0)))
{
vis[j]=1;
ans+=(r[j].p2.x-r[j].p1.x)*(r[j].p3.y-r[j].p2.y);
}
}
return ans;
}
class RectangleCrossings
{
public: vector <int> countAreas(vector <string> rectangles, vector <string> segments)
{
rec tmp;
stringstream ss; 
for(int i=0;i<rectangles.size();i++)
{
ss.clear();
ss<<rectangles[i];
ss>>tmp.p1.x;
ss>>tmp.p1.y;
ss>>tmp.p3.x;
ss>>tmp.p3.y;
tmp.p2.x=tmp.p3.x;
tmp.p2.y=tmp.p1.y;
tmp.p4.x=tmp.p1.x;
tmp.p4.y=tmp.p3.y;
r.push_back(tmp);
}
seg cur;
for(int i=0;i<segments.size();i++)
{
ss.clear();
ss<<segments[i];
ss>>cur.p1.x;
ss>>cur.p1.y;
ss>>cur.p2.x;
ss>>cur.p2.y;
s.push_back(cur);
}
vis.resize(r.size());
vector<int> ans(2);
ans[0]=fun1();
ans[1]=fun2();
return ans;
}
};
