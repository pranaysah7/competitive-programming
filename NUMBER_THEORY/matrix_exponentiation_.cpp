#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define mod 1000000007
#define endl "\n"
#define inf 1e18
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define vli vector<ll>
#define vi vector<int>
#define deb(x) cout<<#x<<" = "<< x << endl
#define deb2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<"="<<y<<endl
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

//-------------------------------------------------------------------------------------------------------------
int arr[101][101];
int I[101][101];
void mul(int dim)
{
	int j=1;
int res[dim+1][dim+1];
for(int i=1;i<=dim;i++)
{
	for(j=1;j<=dim;j++)
		res[i][j]=0;
	{
		for(int k=1;k<=dim;k++)
		{
			res[i][j]+=arr[i][k]*I[k][j];
		}
	}
}
for(int i=1;i<=dim;i++)
{
	for(int j=1;j<=dim;j++)
	{
		I[i][j]=res[i][j];
	}
}
}
void power(int dim,int n)
{
	for(int i=1;i<=dim;i++)
	{
		for(int j=1;j<=dim;j++)
		{
			if(i==j)
			{
				I[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		mul(dim);
	}//unanle to solve
	//efficient method
	while(n)
	{
		if(n%2)
		{
			mul(arr,I);
			n--;
		}
		else
		{
			mul(arr,arr);
			n/=2;
		}
	}
	for(int i=1;i<=dim;i++)
{
	for(int j=1;j<=dim;j++)
	{
		arr[i][j]=I[i][j];
	}
}
}

int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
int t;
cin>>t;
int dim,n;
while(t--)
{
	cin>>dim>>n;
	for(int i=1;i<=dim;i++)
	{
		for(int j=0;j<=dim;j++)
		{
			cin>>arr[i][j];
		}
	}
	power(dim,n);
	for(int i=1;i<=dim;i++)
{
	for(int j=1;j<=dim;j++)
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}
}





//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}