#include <bits/stdc++.h>
using namespace std;
//polygon area with ordered vertices
//https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/
double polygon_area(vector<pair<double,double> >p)
{
    // | 1/2 [ (x1y2 + x2y3 + ... + xn-1yn + xny1) -(x2y1 + x3y2 + ... + xnyn-1 + x1yn) ] |
    double ans=p[p.size()-1].first*p[0].second-p[p.size()-1].second*p[0].first;
    for(int i=0; i<p.size()-1; i++)
        ans+=p[i].first*p[i+1].second;
    for(int i=0; i<p.size()-1; i++)
        ans-=p[i].second*p[i+1].first;
    ans*=1.0/2;
    return fabs(ans);
}
//check if point lies on segment ab
bool pointOnSegment(pair<double,double>p,pair<double,double>a,pair<double,double>b)
{
    return (p.first<max(a.first,b.first)||fabs(p.first-max(a.first,b.first))<1e-7)&&
           (p.first>min(a.first,b.first)||fabs(p.first-min(a.first,b.first))<1e-7)&&
           (p.second<max(a.second,b.second)||fabs(p.second-max(a.second,b.second))<1e-7)&&
           (p.second>min(a.second,b.second)||fabs(p.second-min(a.second,b.second))<1e-7);
}
//get intersection point for two lines
//https://www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines/
bool ex_point;
pair<double,double> intersection_point(pair<double,double>a,pair<double,double>b,pair<double,double>c,pair<double,double>d)
{
    
    ex_point=0;
    // Line AB represented as a1x + b1y = c1
    double a1 = b.second - a.second;
    double b1 = a.first - b.first;
    double c1 = a1*(a.first) + b1*(a.second);

    // Line CD represented as a2x + b2y = c2
    double a2 = d.second - c.second;
    double b2 = c.first - d.first;
    double c2 = a2*(c.first)+ b2*(c.second);

    double det = a1*b2 - a2*b1;
    if(fabs(det)<1e-7)//parallel
        return make_pair(FLT_MAX,FLT_MAX);
        
    double x = (b2*c1 - b1*c2)/det;
    double y = (a1*c2 - a2*c1)/det;
    //make sure that the intersection point lies on the two segments

    if(!(pointOnSegment(make_pair(x,y),a,b)&&pointOnSegment(make_pair(x,y),c,d)))
        return make_pair(FLT_MAX,FLT_MAX);
    
    ex_point=1;
    return make_pair(x, y);
}
//get intersection points for two polygons
vector<pair<double,double> > get_intersection_points(vector<pair<double,double> > v1,vector<pair<double,double> > v2)
{
    vector<pair<double,double> > ans;
    pair<double,double> tmp;
    for(int nexti=1,i=0; i<v1.size(); i++,nexti=(i+1==v1.size())?0:i+1)
    {
        for(int j=0,nextj=1; j<v2.size(); j++,nextj=(j+1==v2.size()?0:j+1))
        {
            tmp=intersection_point(v1[i],v1[nexti],v2[j],v2[nextj]);
            if(ex_point)
            {
                ans.push_back(tmp);
            }
        }
    }
    return ans;
}
//delete duplicate points from vector
vector<pair<double,double> > delete_dup_points(vector<pair<double,double> >v)
{
    vector<pair<double,double> >ans;
    for(int i=0; i<v.size(); i++)
    {
        bool f=0;
        for(int j=0; j<ans.size(); j++)
        {
            if(fabs(v[i].first-ans[j].first)<=1e-7&&fabs(v[i].second-ans[j].second)<=1e-7)
                f=1;
        }
        if(!f) ans.push_back(v[i]);
    }
    return ans;
}
//point inside polygon  
//https://wrf.ecse.rpi.edu//Research/Short_Notes/pnpoly.html
bool isInside(pair<double,double>p,vector<pair<double,double> > v)
{
  int i, j, c = 0;
  for (i = 0, j = v.size()-1; i < v.size(); j = i++) {
    if ( ((v[i].second>p.second) != (v[j].second>p.second)) &&
	 (p.first < (v[j].first-v[i].first) * (p.second-v[i].second) / (v[j].second-v[i].second) + v[i].first) )
       c = !c;
  }
  return c;
}
//polygons Intersection 
//tutorial: https://www.swtestacademy.com/intersection-convex-polygons-algorithm/
vector<pair<double,double> >polygonsIntersection(vector<pair<double,double> >v1,vector<pair<double,double> >v2)
{
    vector<pair<double,double> > ans,tmp;
    ans=get_intersection_points(v1,v2);
    for(int i=0; i<v1.size(); i++)
    {
        if(isInside(v1[i],v2)) ans.push_back(v1[i]);
    }

    for(int i=0; i<v2.size(); i++)
    {
        if(isInside(v2[i],v1)) ans.push_back(v2[i]);
    }
    return delete_dup_points(ans);
}
double avgx,avgy;
//sort polygon points
//https://math.stackexchange.com/questions/978642/how-to-sort-vertices-of-a-polygon-in-counter-clockwise-order 
bool fun(pair<double,double>a,pair<double,double>b)
{
    double x=atan2(a.first-avgx,a.second-avgy)*180.0/acos(-1)+360,
           y=atan2(b.first-avgx,b.second-avgy)*180.0/acos(-1)+360;
    x=fmod(x,360.0),y=fmod(y,360.0);
    return x<y;
}
int main()
{
    int n,x,y;
    double ans;
    vector<pair<double,double> > v1,v2,tmp;
    while(scanf("%d",&n)==1&&n)
    {
        while(n--)
        {
            scanf("%d%d",&x,&y);
            v1.push_back(make_pair(x,y));
        }
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&x,&y);
            v2.push_back(make_pair(x,y));
        }
        if(v1.size()<3&&v2.size()<3)
        {
            ans=0;
        }
        else if(v1.size()<3)
        {
            ans=polygon_area(v2);
        }
        else if(v2.size()<3)
        {
            ans=polygon_area(v1);
        }
        else
        {
            tmp=polygonsIntersection(v1,v2);
            ans=0;
            if(tmp.size()>2)
            {
                avgx=avgy=0;
                for(int i=0; i<tmp.size(); i++)
                    avgx+=tmp[i].first,avgy+=tmp[i].second;
                //mass point to sort according it
                avgx/=tmp.size();
                avgy/=tmp.size();
                sort(tmp.begin(),tmp.end(),fun);
                ans=-2*polygon_area(tmp);
            }
            ans+=polygon_area(v1)+polygon_area(v2);
        }
        stringstream ss;
        string s;
        ss<<(int)ans;
        ss>>s;
        n=5-s.size();
        while(n--) printf(" ");
        printf("%.2lf",ans);
        v1.clear(),v2.clear();
    }
    cout<<endl;
    return 0;
}
