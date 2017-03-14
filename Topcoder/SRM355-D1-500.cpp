//http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm355
#include<bits/stdc++.h>
using namespace std;
class Tetrahedron
{
public: string exists(vector <string> d)
{
double arr[4][4];
stringstream ss;
for(int i=0;i<4;i++)
{
ss.clear();
ss<<d[i];
for(int j=0;j<4;j++)
{
ss>>arr[i][j];
}
}

double xc=arr[0][2]*((arr[0][2]*arr[0][2]+arr[0][1]*arr[0][1]-arr[1][2]*arr[1][2])/(2*arr[0][2]*arr[0][1])),
yc=sqrt(arr[0][2]*arr[0][2]-xc*xc),
xd=arr[0][3]*((arr[0][3]*arr[0][3]+arr[0][1]*arr[0][1]-arr[1][3]*arr[1][3])/(2*arr[0][3]*arr[0][1])),
yd=sqrt(arr[0][3]*arr[0][3]-xd*xd),

mnd=sqrt((xd-xc)*(xd-xc)+(yd-yc)*(yd-yc)),
mxd=sqrt((xd-xc)*(xd-xc)+(-yd-yc)*(-yd-yc));

if((arr[2][3]<mxd||abs(arr[2][3]-mxd)<=1e-9)&&(arr[2][3]>mnd||abs(arr[2][3]-mnd)<=1e-9)) return "YES";
return "NO";
}
};
