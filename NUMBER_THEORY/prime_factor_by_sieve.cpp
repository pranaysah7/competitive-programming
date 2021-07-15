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
int arr[1000001];
void sieve()
{
for(int i=2;i<=1000000;i++)
{
	if(arr[i]==-1)
	{
		for(int j=i;j<=1000000;j+=i)
		{
			if(arr[j]==-1)
			arr[j]=i;
		}
	}
}
}
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
int n;
cin>>n;
memset(arr,-1,sizeof(arr));
sieve();
if(n==1)
{
	cout<<1<<" ";
}
while(n!=1)
{
	cout<<arr[n]<<" ";
	n/=arr[n];
}


//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}