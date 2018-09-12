#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
int n,p,idx;
void check(pair<int,int> p1,pair<int,int> p2)
{
    int val;
    for(int i=0;i<v.size();i++)
    {
        val=(p2.second - p1.second) * (v[i].first - p2.first) -
              (p2.first - p1.first) * (v[i].second - p2.second);
        if(val==0) idx=max(idx,i);
        else if(val>0) p++;
        else n++;
    }
}
int main()
{
    string s;
    int x,y,mn;
    while(cin>>s&&s!="#")
    {
        mn=2e9;
        cin>>x>>y;
        do
        {
            v.push_back(make_pair(x,y));
            cin>>x>>y;

        }while(!(x==0&&y==0));
        for(int i=1;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if(!((v[0].first>=min(v[i].first,v[j].first)&&v[0].first<=max(v[i].first,v[j].first))
                  ||(v[0].second>=min(v[i].second,v[j].second)&&v[0].second<=max(v[i].second,v[j].second)))) continue;

                idx=max(i,j);
                p=n=0;
                check(v[i],v[j]);
                if(n==0||p==0) mn=min(mn,idx);
            }
        }
        cout<<s<<" "<<mn<<endl;
        v.clear();
    }
}
