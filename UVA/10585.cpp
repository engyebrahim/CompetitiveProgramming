/* hint in udebug is:
The center of symmetry can be found as average of all points:
add all x coordinates , y coordinates, and make average (divide it with "N").

Then put all points to set. Afterward, search for all mirrors of all points 
(if there would be a mirror missing, print "no", otherwise "yes"). Mirror can be made as "Center*2-Point[i]"
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
     int t,n;
     cin>>t;
     set<pair<long long,long long>> s;
     set<pair<long long,long long>>::iterator it;
     long long sx,sy;
     pair<long long ,long long> ans; bool f;
     while(t--)
     {
          s.clear();
          scanf("%d",&n);
          sx=0; sy=0;
          for(int x,y,i=0;i<n;i++)
          {
               scanf("%d%d",&x,&y);
               s.insert(make_pair(x,y));
               sx+=x,sy+=y;
          }
          sx*=2,sy*=2;
          if(sy%n||sx%n) {cout<<"no\n"; continue;}
          ans.first=sx/n,ans.second=sy/n;
          it=s.begin(); f=0;
          for(int i=0;i<n;i++,it++)
          {
               if(s.end()==s.find(make_pair(ans.first-it->first,ans.second-it->second)))
               {f=1; break;}
          }
          if(f) cout<<"no\n";
          else cout<<"yes\n";
     }
}
