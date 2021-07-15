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
vi arr(1000001,1);
vi pp(1000001,0);
void sieve()
{int cnt(0);
	pp.clear();
arr[0]=arr[1]=0;	
for(int i=2;i*i<=1000001;i++)
{
	if(arr[i])
	{
		for(int j=i*i;j<=1000001;j+=i)
		{
			arr[j]=0;
		}
	}
}
for(int i=1;i<=1000001;i++)
{
	if(arr[i])
	{
		cnt++;
	}
	if(arr[cnt]==1)
	{
		pp[i]=1;
	}
}
for(int i=1;i<=1000001;i++)
{
	pp[i]+=pp[i-1];
	
}
}
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
int l,r,t;
cin>>t;
sieve();
while(t--)
{
cin>>l>>r;
cout<<pp[r]-pp[l-1]<<endl;
}








//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}