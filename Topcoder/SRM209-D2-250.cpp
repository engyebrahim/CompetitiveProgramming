#include<bits/stdc++.h>
using namespace std;
class MovingAverages
{
     public:vector <int> calculate(vector <string> v, int n)
     {
          int x,sum;
          string s;
          vector <int>ans;
          for(int i=0;i<=v.size()-n;i++)
          {
               sum=0;
               for(int j=i;j<i+n;j++) 
               {
                    s=v[j];
                    
                    x=s[0]-'0';
                    x=x*10+s[1]-'0';
                    sum+=x*60*60;
                    x=s[3]-'0';
                    x=x*10+s[4]-'0';
                    sum+=x*60;
                    x=s[6]-'0';
                    x=x*10+s[7]-'0';
                    sum+=x;
               }
               ans.push_back(floor(sum/n));
          }
          return ans;
     }
};
