/*
-number of intersection squares= (n*2-1)*4
to calculate inside squares 
-center of circle is (0,0) 
-deal with each square by its up right point
-make loop from 1 to radius  for x&y to get all points
-if distance from (0,0) to the point < radios then the square of this point is inside the circule
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
     int n; bool f=0;
     while(cin>>n)
     {
          if(f) cout<<endl;
          f=1;
          double r=n-.5; int c=0;
          for(int i=1;i<n;i++)
          {
               for(int j=1;j<n;j++)
               {
                    if(sqrt(i*i+j*j)<r) c++;
               }
          }
          printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n",n,(2*n-1)*4,c*4);
     }
}
