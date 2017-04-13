/*
suppose sticks as a nodes in graph if any two sticks intersect make an adge between them 
then run dfs to count number of connected graphs 
any two sticks(node) in one connected graph can be reachable
tutorial for check if two sticks intersect :http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
*/
#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
};
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
     return true;
     
     return false;
}
int orientation(Point p, Point q, Point r)
{
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);  
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
int t,n,m;
vector<vector<int> >v;
vector<pair<Point,Point > >p;
int arr[1001],idx,x,y;
void dfs(int node)
{
     arr[node]=idx;
     for(int i=0;i<v[node].size();i++)
        if(arr[v[node][i]]==-1) dfs(v[node][i]);
}
int main() {
     cin>>t;
     while(t--)
     {
          scanf("%d%d",&n,&m);
          memset(arr,-1,sizeof arr);
          v.resize(n);
          p.resize(n);
          for(int i=0;i<n;i++)
               scanf("%d%d%d%d",&p[i].first.x,&p[i].first.y,&p[i].second.x,&p[i].second.y);
          for(int i=0;i<n;i++)
               for(int j=i+1;j<n;j++)
                    if(doIntersect(p[i].first,p[i].second,p[j].first,p[j].second)) 
                       v[i].push_back(j),v[j].push_back(i);
          idx=0;
          for(int i=0;i<n;i++)
               if(arr[i]==-1) {idx++; dfs(i);}
          while(m--)
          {
               scanf("%d%d",&x,&y);
               x--,y--;
               if(arr[x]==arr[y]) cout<<"YES\n";
               else cout<<"NO\n";
          }
          
          p.clear(),v.clear();
     }
} 
