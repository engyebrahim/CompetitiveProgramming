
#include <bits/stdc++.h>
using namespace std;

int main() {
     int arr[17][3],idx=0,mn,ans;
     while(cin>>arr[idx][0]>>arr[idx][1]>>arr[idx][2])
     {
          if(arr[idx][0]==-1&&arr[idx][1]==-1&&arr[idx][2]==-1) break;
          if(idx==16)
          {
               mn=1e+9;
               for(int i=0;i<16;i++)
               {
                    if(mn>(arr[i][0]-arr[16][0])*(arr[i][0]-arr[16][0])
                          +(arr[i][1]-arr[16][1])*(arr[i][1]-arr[16][1])
                          +(arr[i][2]-arr[16][2])*(arr[i][2]-arr[16][2]))
                          mn=(arr[i][0]-arr[16][0])*(arr[i][0]-arr[16][0])
                          +(arr[i][1]-arr[16][1])*(arr[i][1]-arr[16][1])
                          +(arr[i][2]-arr[16][2])*(arr[i][2]-arr[16][2]),ans=i;
               }
               printf("(%d,%d,%d) maps to (%d,%d,%d)\n",arr[16][0],arr[16][1],arr[16][2]
                                                        ,arr[ans][0],arr[ans][1],arr[ans][2]);
          }
          else idx++;
     }
}
