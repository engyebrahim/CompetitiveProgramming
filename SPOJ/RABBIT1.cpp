#include<bits/stdc++.h>
using namespace std;
 
#define matrix vector< vector<long long> >
long long M=  (1<<20) ;
matrix zero(int n,int m)
{
     return matrix(n,vector<long long>(m,0));
}
matrix mul( matrix a, matrix b)
{
     matrix ans=zero(a.size(),b[0].size());
     for(int i=0;i<a.size();i++)
     {
          for(int k=0;k<a[i].size();k++)
          {
               for(int j=0;j<b[0].size();j++)
               {
                    ans[i][j]+=(a[i][k]*b[k][j])%M;
                    ans[i][j]%=M;
               }
          }
     }
     return ans;
}
matrix iden (int n)
{
     matrix ret=zero(n,n);
     for(int i=0;i<n;i++) ret[i][i]=1;
     return ret;
}
matrix pow(matrix a,long long p)
{
     if(p==0) return iden(a.size());
     if(p%2==1) return mul(a,pow(a,p-1));
     else return pow(mul(a,a),p/2);
}
long long sum(int n)
{
     if(n<=0) return 0;
     if(n==1) return 1;
     matrix t=zero(3,3);
     t[0][1]=1,t[1][0]=1,t[1][1]=1,t[1][2]=1,t[2][2]=1;
     matrix p=pow(t,n-1);
     matrix init = zero(3,3);
     init[0][1]=1,init[0][2]=1;
     matrix ans=mul(init,p);
     return ans[0][2];
}
int main() {
     int t,x,y,pp;
     cin>>t;
     while(t--)
     {
          pp=2;
          cin>>x>>y;
          for(int i=1;i<y;i++) pp*=2;
          cout<<sum(x)%pp<<endl;
     }
}   
