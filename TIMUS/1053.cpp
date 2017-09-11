#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; long long x;
    cin>>n;
    set<long long> s;
    while(n--)
    {
        cin>>x;
        s.insert(x);
    }
    while(s.size()!=1)
    {
        x=*(--s.end());
        s.erase(--s.end());
        if(x%(*s.begin())!=0) s.insert(x%(*s.begin()));
    }
    cout<<*s.begin()<<endl;

}
