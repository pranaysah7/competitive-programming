#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"FALSE";
	
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			cout<<"FALSE";
			return 0;
		}
	}
	cout<<"TRUE";
	return 0;
}
