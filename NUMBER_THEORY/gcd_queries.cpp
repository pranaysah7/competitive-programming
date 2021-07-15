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
ll power(ll a,ll n,ll d)
{
	ll res=1;
	while(n)
	{
		if(n%2)
		{
			res=((res%d)*(a%d)%d);
			n--;
		}
		else
		{
			a=((a%d)*(a%d)%d);
			n/=2;
		}
	}
	return res;
}
ll gcde(ll a,ll b,ll n)
{
if(a==b)
{
	return((power(a,n,mod)+power(b,n,mod))%mod);
}
ll candidate=1;
ll num=a-b;
for(ll i=1;i*i<=num;i++)
{
if(num%i==0)
{
	ll temp=((power(a,n,i)+power(b,n,i))%i);
	if (temp==0)
	{
		candidate=max(candidate,i);
	}
	 temp=((power(a,n,num/i)+power(b,n,num/i))%(num/i));
	if (temp==0)
	{
		candidate=max(candidate,num/i);
	}

}
}
return candidate%mod;
}
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here

ll a,b,n,t;
cin>>t;
while(t--)
{
	cin>>a>>b>>n;
	cout<<gcde(a,b,n)<<endl;
}




//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}