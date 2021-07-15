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
int f[1000001];
int inv(int base,int n)
{
	int res=1;
	while(n)
	{
		if(n%2)
		{
			res=(res*1ll*base)%mod;
			n--;
		}
		else
		{
			base=(base*1ll*base)%mod;
			n/=2;
		}
	}
	return res;
}
int C(int n,int k)
{
	if(k>n) return 0;
	int res=f[n];
	res=(res*1ll*inv(f[k],mod-2))%mod;
	res=(res*1ll*inv(f[n-k],mod-2))%mod;
	return res;
}
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
f[0]=f[1]=1;
for(int i=2;i<=1000000;i++)
{
	f[i]=(i*1ll*f[i-1]) % mod;
}
int q;
int n,k;
cin>>q;
while(q--)
{
	cin>>n>>k;
	cout<<C(n,k)<<endl;
}



//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}