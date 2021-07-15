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
// 0 1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8 16 6 18 8 12 10 22 8 20 12 18 12 28 8 30 16 20 16 24 12 36 18 24 16 40 12 42 20 24 22 46 16 42 20 32 24 52 18 40 24 36 28 58 16 60 30 36 32 48 20 66 32 44 24 
map<ll,ll>pf;
ll q2=0;
ll total;
void factorize(ll n)
{
 total=1;
for(ll i=2;i*i<=n;i++)
{	if(n%i==0)
	{ll cnt(0);
		while(n%i==0)cnt++,n/=i;
		total*=(cnt+1);//count divisor
		pf[i]=cnt;
	}
}
if(n>1)pf[n]=1,total*=2;
}
int main()
{
	clock_t begin = clock();
	fast_io;
	//write here
ll t,n,q,k;
cin>>n>>q;
factorize(n);
while(q--)
{
	cin>>t>>k;
	if(t==1)//divisor of both n and k
	{
		ll res=1;
		for(auto p:pf)
		{
			ll cnt(0);
			while(k%p.ff==0)
			{
				cnt++,k/=p.ff;
			}
			res*=min(cnt,p.ss)+1;//power of factor
		}
		cout<<res<<endl;
	}
	else
	{
		if(t==2)
		{
			ll res=1;
			for(auto p:pf)
			{
				ll cnt(0);
				if(k%p.ff==0)
				{
					while(k%p.ff==0)
					{
						cnt++,k/=p.ff;
					}
					if(cnt>p.ss)
					{
						res=0;
						break;
					}
					res*=(p.ss-cnt)+1;
				}
			}
			if(k>1)res=0;
			cout<<res<<endl;
			q2=res;

		}
		else
		{
			ll res=1;
			for(auto p:pf)
			{
				ll cnt(0);
				if(k%p.ff==0)
				{
					while(k%p.ff==0)
					{
						cnt++,k/=p.ff;
					}
					if(cnt>p.ss)
					{
						res=0;
						break;
					}
					res*=(p.ss-cnt)+1;
				}
			}
			if(k>1)res=0;
			cout<<total-res<<endl;
		}
	}
}




//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t end = clock();
	  	cerr<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif		
}