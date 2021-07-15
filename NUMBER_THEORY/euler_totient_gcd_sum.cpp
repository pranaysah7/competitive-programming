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
vi arr(1000001);
int getcount(int d,int n)
{
return arr[n/d];
}
void ETF()
{
arr[0]=0;
arr[1]=1;
for(int i=2;i<=1000000;i++)
{
	arr[i]=i;
}
for(int i=2;i<=1000000;i++)
{
if(arr[i]==i)
{
	for(int j=i;j<=1000000;j+=i)
	{
		arr[j]=arr[j]-arr[j]/i;
	}
}
}
}
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
int q,n;
ETF();
cin>>q;
while(q-->0)
{
	cin>>n;
	int res=0;
	for(int i=1;i*i<=n;i++)
	{
	if(n%i==0)
	{
			int d1=i;
		int d2=n/i;
	res+=d1*getcount(d1,n);
	//perfect square dont count the same number again
	if(d1!=d2)
	{
		res+=d2*getcount(d2,n);	
	}
	}
	}
	cout<<res<<endl;
	cout<<arr[2];

}





//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}