#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int odd=0,even=0;
		for(int k=2;k<=sqrt(n);k++)
		{
			if(n%k==0)
			{
				int count=0;
				while(n%k==0)
				{
					count++;
					n/=k;
				}
				if(count%2==0)
				even++;
				else
				odd++;
			}
		}
		if(n!=1)
		odd++;
		if(even>odd)
		printf("Psycho Number\n");
		else
		printf("Ordinary Number\n");
	}
	
	return 0;
} 
