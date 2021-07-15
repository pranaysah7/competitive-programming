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
int phi_cp(int n)
{
	int res=n;
	for(int i=2;i*i<=n;i++)//O(sqrt(n))
	{
		if(n%i==0)
		{
			while(n%i==0)//reduce the number while it is divisible by a prime
			{
				n/=i;
			}
			res=res-res/i;//n*(1-1/prime)
		}
		
	}
	if(n>1)
	{
		res-=res/n;
	}
	return res;
}
int sieve[100000];
void ETF()//n(log(log(n))
{
	sieve[0]=0;
	sieve[1]=1;
	for(int i=2;i<=100000;i++)//dp that contains answer of itself
	{
		sieve[i]=i;
	}
	for(int i=2;i<=100000;i++)
	{
		if(sieve[i]==i)
			{
				for(int j=i;j<=100000;j+=i)
				{
					sieve[j]-=sieve[j]/i;
				}	
			}
	}
}

int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here

int t=1,n;

// cin>>t;
while(t--)
{
	cin>>n;
	// cout<<"ETF("<<n<<")="<<phi_cp(n)<<endl;
	ETF();
	// cout<<sieve[n];
	for(int i=0;i<=n;i++)
	{
		cout<<sieve[i]<<" ";
	}
}




//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}