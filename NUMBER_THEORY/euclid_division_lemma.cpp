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
int arr[100001],pre[100005],suf[100005];
int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
//for A and B a positive integer 
	// A=B*q+r
 int t,q,n,r,l;
 cin>>t;
 while(t--)
 {
cin>>n>>q;
for(int i=1;i<=n;i++)
{
	cin>>arr[i];
}
 pre[0]=suf[n+1]=0;
for(int i=1;i<=n;i++)
{
	pre[i]=gcd(arr[i],pre[i-1]);
}
for(int i=n;i>=1;i--)
{
	suf[i]=gcd(arr[i],suf[i+1]);
}
while(q--)
{
	cin>>l>>r;
	cout<<gcd(pre[l-1],suf[r+1])<<endl;//exclude range l and r
}
}




//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}