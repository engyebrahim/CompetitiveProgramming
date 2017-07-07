//http://ideone.com/6hrrr2
#include<bits/stdc++.h>
using namespace std;
long long n,m,d,dp[100009];
struct mach
{
     long long d,p,r,g;
     bool operator < (mach b) 
     {
          return d<b.d;
     }
}c[100003];
set<pair<long long,long long> >s;
bool ch(pair<long long,long long> i1,pair<long long,long long> i2,pair<long long,long long> i3)
{
     double a,b;
     a=(i3.second-i1.second)/(i1.first-i3.first)*1.0;
     b=(i3.second-i2.second)/(i2.first-i3.first)*1.0;
     if(a>b) return 0;
     return 1;
}
int main()
{
     int tc=1;
     long long v1,v2;
     long long cc,mm;
     while(cin>>n>>m>>d&&n+m+d)
     {
          s.clear();
          for(int i=0;i<n;i++)
               scanf("%lld%lld%lld%lld",&c[i].d,&c[i].p,&c[i].r,&c[i].g);
          sort(c,c+n);
          c[n].d=d+1;
          for(int i=0;i<=n;i++)
          {
               dp[i]=m;
               while(s.size()>=2){
                    
                    v1=(*s.begin()).first*c[i].d+(*s.begin()).second;
                    v2=(*(++s.begin())).first*c[i].d+(*(++s.begin())).second;
                    if(v1<v2) s.erase(s.begin());
                    else break;
               }
               if(s.size())
               dp[i]=max(dp[i],(*s.begin()).first*c[i].d+(*s.begin()).second);
               
               if(i!=n&&dp[i]>=c[i].p)
               {
                    cc=dp[i]+c[i].r-c[i].p-c[i].d*c[i].g-c[i].g;
                    mm=c[i].g;
                    set<pair<long long,long long> >::iterator it1,it2,it3,cur;
                    it1=it2=it3=cur=s.insert(make_pair(mm,cc)).first;
                    it1--;it3++;
                    if(it2!=s.begin()&&it1->first==it2->first)
                    {
                         s.erase(it1);
                         continue;
                    }
                    if(it3!=s.end()&&it3->first==it2->first)
                    {
                         s.erase(it2);
                         continue;
                    }
                    if(it2!=s.begin()&&it3!=s.end())
                    {
                         if(!ch(*it1,*it2,*it3)) 
                         {
                              s.erase(it2);
                              continue;
                         }
                    }
                    while(1)
                    {
                         it1=it2=it3=cur;
                         if(it3==s.begin()) break;
                         it2--,it1--;
                         if(it2==s.begin()) break;
                         it1--;
                         if(!ch(*it1,*it2,*it3)) s.erase(it2);
                         else break;
                         
                    }
                    while(1)
                    {
                         it1=it2=it3=cur;
                         it2++,it3++;
                         if(it2==s.end()) break;
                         it3++;
                         if(it3==s.end()) break;
                         if(!ch(*it1,*it2,*it3)) s.erase(it2);
                         else break;
                    }
               }
          }
          cout<<"Case "<<tc++<<": "<<dp[n]<<endl;
     }
     
}
