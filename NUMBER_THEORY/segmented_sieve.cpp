#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define mod 1000000007
#define endl "\n"
#define tabl "\t"
#define inf 1e18
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define vli vector<ll>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define deb(x) cerr<<#x<<" = ";_print(x);cerr<<endl
#define deb2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<"="<<y<<endl
#define intl int64_t
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

//-------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

//----------------------------------------------------------------------------------------------------------------
const int N=1000000;
int sieve[N];
vi primes;
void sievee()
{
	for(int i=2;i<=N;i++) sieve[i]=1;

	for(int i=2;i*i<=N;i++)
	{
		if(sieve[i])
		{
		for(int j=i*2;j<=N;j+=i)
		{
			sieve[j]=0;
		}
		}
	}
	for(int i=2;i<=N;i++)
	{
		if(sieve[i])
		{
			primes.push_back(i);
		}
	}	
}
void init(int l,int r)
{
	if(l==1) l++;

	int maxn=r-l+1;
	vi seg(maxn,1);//create an array

	for(int p:primes)
	{
		if(p*p<=r)
		{
			int i=(l/p)*p;//first multiple of prime in range
			if(i<l) i+=p;


			for(;i<=r;i+=p)
			{
			if(i!=p)//it can occur 
			{
				seg[i-l]=0;
			}	
			}
		}
	}
	deb(seg);
	for(int i=0;i<maxn;i++)
	{
		if(seg[i])
		{
			cout<<l+i<<tabl;
		}
	}


	cout<<endl;
}
int main()
{
	clock_t begin = clock();
	fast_io;
	//write here
	sievee();
	// ll t,l,r;
	// cin>>t;
	// while(t--)
	// {
	// 	cin>>l>>r;
	// 	init(l,r);
	// }
for(auto a:primes)
{
	cout<<a<<tabl;
}




//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t end = clock();
	  	cerr<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
		
}