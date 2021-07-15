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
int powerof(int a,int m,int n)
{
	int res=1;
	while(m)
	{
		if(m%2)
		{
			res=(res*a)%n;
			m--;
		}
		else
		{
			a=(a*a)%n;
			m/=2;
		}
	}
	return res;
}
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
int t,a,b,m;
cin>>t;
while(t--)
{
	cin>>a>>m;
	cout<<"a^-1"<<" "<<powerof(a,m-2,m)<<endl;
}





//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}