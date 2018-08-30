//Disjoint Set
#include <bits/stdc++.h>
using namespace std;
int p[20000001];
int get_pr(int i)
{
    if(p[i]==i) return i;
    return p[i]=get_pr(p[i]);
}
void st(int a,int b)
{
    p[get_pr(a)]=get_pr(b);
}
int main()
{
    int tt,t,f,n,a,b;
    scanf("%d",&tt);
    string s;
    stringstream ss;
    char c;
    while(tt--)
    {
        t=f=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) p[i]=i;
        getline(cin,s);
        while(getline(cin,s)&&s.size())
        {
            ss<<s;
            ss>>c;
            ss>>a;
            ss>>b;

            ss.clear();
            if(c=='q')
            {
                if(get_pr(a)==get_pr(b)) t++;
                else f++;
            }
            else
            {
                st(a,b);
            }
        }
        printf("%d,%d\n",t,f);
        if(tt) printf("\n");
    }

}
