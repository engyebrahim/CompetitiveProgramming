#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s,k;
    int n;
    bool f;
    deque<string> d;
    while(cin>>s)
    {
        f=0;
        n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==']'||s[i]=='[')
            {
                if(f&&k.size()) d.push_back(k);
                else if(!f&&k.size()) d.push_front(k);
                k="";
                f=(s[i]==']')?1:0;
            }
            else k+=s[i];
        }
        if(f&&k.size()) d.push_back(k);
        else if(!f&&k.size()) d.push_front(k);
        k="";
        n=d.size();
        for(int i=0;i<n;i++)
            cout<<d[i];
        cout<<endl;
        d.clear();
    }
}
