#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t,m,k,x;
    long long l,ans;
    cin>>t;
    queue<int> f,r;
    string s;
    while(t--)
    {
        ans=0;
        cin>>l>>m;
        l*=100;
        while(m--)
        {
            cin>>k>>s;
            if(s=="left") f.push(k);
            else r.push(k);
        }
        while(r.size()||f.size())
        {
            x=0;
            while(f.size()&&x+f.front()<=l)
            {
                x+=f.front();
                f.pop();
            }
            ans++;
            x=0;
            while(r.size()&&x+r.front()<=l)
            {
                x+=r.front();
                r.pop();
            }
            if(x||f.size()) ans++;
        }
        cout<<ans<<endl;
    }
}
