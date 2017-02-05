#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     int tc=0,y[22],a[22],b[22],mx,x,nw;
     bool f;
     while(cin>>n&&n)
     {
          tc++;
          mx=-1;
          for(int i=0;i<n;i++)
          {
               cin>>y[i]>>a[i]>>b[i];
               mx=max(a[i],mx);
          }
          x=mx;
          cout<<"Case #"<<tc<<":\n";
          while(x<10000)
          {
                    f=1;
                    for(int i=0;i<n;i++)
                    {
                         nw=a[i]+(x-a[i])%(b[i]-a[i]);
                         //cout<<i<<" "<<nw<<endl;
                         if(nw!=y[i])
                         {
                              f=0;
                              break;
                         }
                    }
                    if(f)
                    {
                         cout<<"The actual year is "<<x<<"."<<endl;
                         break;
                    }
               x++;
          }
          if(!f)
          cout<<"Unknown bugs detected.\n";
          cout<<"\n";
          
     }
}
