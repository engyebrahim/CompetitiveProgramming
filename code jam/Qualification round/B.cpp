#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t,n;
    scanf("%d",&t);
    string s;
    for(int tc=1;tc<=t;tc++)
    {
            cin>>s;
            n=s.size();
            for(int i=n-2;i>=0;i--)
            {
                if(s[i]>s[i+1]) 
                {
                     s[i]--;
                     for(int j=i+1;j<n;j++) s[j]='9';
                }    
            }
            if(s[0]=='0') s=s.substr(1,n-1);
            printf("Case #%d: ",tc);
            cout<<s<<endl;
    }
    return 0;
}
