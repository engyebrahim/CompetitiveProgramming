/*
-put every node inside the circule in vector
-for every node suppose that it in the diameter then loop in the remaining point calculate points in counter/clockwise 
 and the answer is tha max valu will be calculated
*/
#include<bits/stdc++.h>
using namespace std;
int ccw(int x,int y,int a,int b,int f,int s)
{
    return (a-x)*(s-y)-(b-y)*(f-x) ;
}
int main(){
     vector<pair<int,int> > v;
     int x,y,a,b,n,ans,c1,c2,f; double r;
     while(cin>>x>>y>>r&&r>0)
     {
          cin>>n;
          while(n--){
               cin>>a>>b;
          if((a-x)*(a-x)+(b-y)*(b-y)<=r*r) v.push_back(make_pair(a,b));
          }
          ans=0;
          for(int i=0;i<v.size();i++)
          {
               c1=0,c2=0;
               for(int j=0;j<v.size();j++)
               {
                    f=ccw(x,y,v[i].first,v[i].second,v[j].first,v[j].second);
                    if(f>0) c1++;
                    else if(f==0) c1++,c2++;
                    else c2++;
                    
               }
               ans=max(ans,max(c1,c2));
          }
          cout<<ans<<endl;
          v.clear();
     }
}
