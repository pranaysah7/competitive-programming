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
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i*i<= n; i++)if (arr[i] == 0) { for (int j = 2 * i; j <= n; j += i)arr[j] = 1;}for(int i=2;i<=n;i++){if(arr[i]==0)vect.push_back(i);} return vect;}
ll phit(ll n){vector<ll> vect(n);vect[0]=0,vect[1]=1;for(ll i=2;i<=n;i++)vect[i]=i; for(ll i=2;i<=n;i++){if(vect[i]==i)for(ll j=i;j<=n;j+=i)vect[j]-=vect[j]/i;	} return vect[n];}
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
ll mulmod(ll x,ll y,ll m)
{
	ll k=0;
	x%=m;
	while(y)
	{
		if(y&1)
		{
			k=(x+k)%m;
			y--;
		}
		else
		{
			x=(x*(2ll))%m;
			y>>=1;
		}
	}
	return k%m;
}
ll binpower(ll a,ll d,ll n)
{
	ll res=1;
	while(d)
	{
		if(d&1)
		{
			res=mulmod(res,a,n);
			d--;
		}
		else
		{
			a=mulmod(a,a,n);
			d>>=1;
		}
	}
	return res%n;
}



bool iscomposite(ll n,ll s,ll d,ll a)
{
ll x=binpower(a,d,n);	
if(x==n-1||x==1)return false;
for(int i=1;i<s;i++)
{
	x=mulmod(x,x,n);//this is factors;
	if(x==n-1)return false;//s-1 is square of s-2
}
return true;
}
bool isPrime(ll n,int iter=5)
{
		if(n <= 4)
	return n == 2 || n == 3;
ll s=0;
ll d=n-1;
while(d%2==0)
{
	d/=2;
	s++;//determine the level of factors
}
for(int i=1;i<=iter;i++)//s->s-1
{
int a=2+rand()%(n-3);
if(iscomposite(n,s,d,a))
return false;
}
return true;
}
int main()
{
	clock_t begin = clock();
	fast_io;
	//write here

ll t,n;

	cin>>t;
	while(t--)
	{
		cin>>n;
		if(isPrime(n)) cout<<"YES"<<endl;
		else		   cout<<"NO"<<endl;
	}





//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t end = clock();
	  	cerr<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif		
}