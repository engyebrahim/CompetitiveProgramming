/*
at first we will try find all cases 
- answer = 4
 if two rings not intersect or intersect in one point from inside or outside
- no answer = 3
-answer = 2
1- two inside circles don intersect or intersect in one point from inside or outside
2- one ring hidin under the second
-answer 1
if only one case from answer=2 get
-otherwise answer is 0
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
     int R1,R2,r1,r2,x1,x2,y1,y2;
     cin>>x1>>y1>>r1>>R1>>x2>>y2>>r2>>R2;
     if(R1<R2) swap(R1,R2),swap(r1,r2),swap(x1,x2),swap(y1,y2);
     double d=sqrt((double)(y1-y2)*(y1-y2)+(x1-x2)*(x1-x2));
     
     if(R1+R2<=d||R2+d<=r1) cout<<4<<endl;
     else if((d>=R1+r2&&d>=R2+r1)||(d+min(r1,r2)<=max(r1,r2)&&R2+d<=R1)||(d>=r1+R2&&d+R2<=R1)) cout<<2<<endl;
     else if(d>=R1+r2||d>=R2+r1||d+min(r1,r2)<=max(r1,r2)||R2+d<=R1||d+R2<=R1) cout<<1<<endl;
     else cout<<0<<endl;
}
