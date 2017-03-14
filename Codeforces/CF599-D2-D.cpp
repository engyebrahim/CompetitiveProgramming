#include<bits/stdc++.h>
using namespace std;
int main() {
     double long m;
     long long x;
     vector<pair<long long,long long> >v;
     scanf("%lld",&x);
     for(double long i=1;i<10000000;i++)
     {
         m=(x-((2*i*i*i+3*i*i+i)/6-i*i)+i*((i*(i-1))/2))/(i*i-((i*(i-1))/2));
         //cout<<m<<endl;
         if(m<i) break;
         if(abs(m-(long long)m)<=1e-9)(i!=m)? v.push_back(make_pair(i,m)),v.push_back(make_pair(m,i)):v.push_back(make_pair(i,m));
     }
     sort(v.begin(),v.end());
     cout<<v.size()<<endl;
     for(int i=0;i<v.size();i++)
       printf("%lld %lld\n",v[i].first,v[i].second);
}
