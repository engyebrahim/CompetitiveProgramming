#include <iostream>
using namespace std;
int main ()
{
	int n,r,c,k;
	int arr[101][101];
	int ar[101][101];
	while(cin>>n>>r>>c>>k&&n+c+r+k!=0)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			cin>>arr[i][j];
 
	for(int t=0;t<k;t++)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(j+1!=c&&arr[i][j]==arr[i][j+1]+1||j!=0&&arr[i][j]==arr[i][j-1]+1||i!=0&&arr[i][j]==arr[i-1][j]+1||i+1!=r&&arr[i][j]==arr[i+1][j]+1)
					ar[i][j]=arr[i][j]-1;
				else if(arr[i][j]==0&&(j+1!=c&&arr[i][j+1]==n-1||j!=0&&arr[i][j-1]==n-1||i+1!=r&&arr[i+1][j]==n-1||i!=0&&arr[i-1][j]==n-1))
					ar[i][j]=n-1;
				else
					ar[i][j]=arr[i][j];
          
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				arr[i][j]=ar[i][j];
	}
	for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{cout<<arr[i][j]; if(j+1!=c) cout<<" ";}
			cout<<endl;
		}
  }
}
