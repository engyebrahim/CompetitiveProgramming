#include<bits/stdc++.h>
using namespace std;
int main(){
 double n,m;
 cin>>n>>m;
 int arr[10002]={};
 for(int x,i=0;i<m;i++) {cin>>x; arr[x]++; }
 for(int i=1;i<=n;i++) printf("%.2lf%\n",100*(arr[i]/m));
 
}
