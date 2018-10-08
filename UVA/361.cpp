#include <bits/stdc++.h>
using namespace std;
bool pointOnSegment(pair<int,int>p,pair<int,int>a,pair<int,int>b)
{
    return p.first<=max(a.first,b.first)&&
           p.first>=min(a.first,b.first)&&
           p.second<=max(a.second,b.second)&&
           p.second>=min(a.second,b.second);
}
int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool isInside(pair<int,int>p,vector<pair<int,int> >v  )
{
  int i, j, c = 0;
  for (i = 0, j = v.size()-1; i < v.size(); j = i++) {
    if ( ((v[i].second>p.second) != (v[j].second>p.second)) &&
	 (p.first < (v[j].first-v[i].first) * (p.second-v[i].second) / (double)(v[j].second-v[i].second) + v[i].first) )
       c = !c;
  }
  //on edges
  for(int next=1,i=0;i<v.size();i++,next=(next+1)%v.size())
      if(orientation(v[i],p,v[next])==0)  c|=pointOnSegment(p,v[i],v[next]);
  return c;
}

vector<pair<int,int> > convexHull(pair<int,int>* points, int n)
{
    if(n<3) return vector<pair<int,int> >();
    vector<pair<int,int> > hull;
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].first < points[l].first)
            l = i;
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;

    } while (p != l);
    return hull;
}
int citCas[202],o;
pair<int,int> v[202] ;
void mark(pair<int,int> *setOfPoints,int val,int sz)
{
    vector<pair<int,int> >poly;
    poly=convexHull(setOfPoints,sz);
    if(poly.size()<3) return;
    for(int n=0;n<o;n++)
        if(citCas[n]!=1&&isInside(v[n],poly)) citCas[n]=val;
}
int main()
{
    int c,r,tc=1;
    bool f;
    char cas[3][10]={"neither","safe","robbed"};
    pair<int,int> cop[202], rob[202];
    while(scanf("%d%d%d",&c,&r,&o)==3&&c+r+o)
    {
        for(int x,y,i=0;i<c;i++)
        {
            f=0;
            scanf("%d%d",&x,&y);
            for(int j=0;j<i;j++)
                if(cop[j].first==x&&cop[j].second==y) f=1;
            if(!f) cop[i]=make_pair(x,y);
        }
        for(int x,y,i=0;i<r;i++)
        {
            f=0;
            scanf("%d%d",&x,&y);
            for(int j=0;j<i;j++)
                if(rob[j].first==x&&rob[j].second==y) f=1;
            if(!f) rob[i]=make_pair(x,y);
        }
        for(int x,y,i=0;i<o;i++)
        {
            scanf("%d%d",&x,&y);
            v[i]=make_pair(x,y);
            citCas[i]=0;
        }
        mark(cop,1,c);
        mark(rob,2,r);
        printf("Data set %d:\n",tc++);
        for(int i=0;i<o;i++)
           printf("     Citizen at (%d,%d) is %s.\n",v[i].first,v[i].second,cas[citCas[i]]);
        printf("\n");
    }
    return 0;
}



