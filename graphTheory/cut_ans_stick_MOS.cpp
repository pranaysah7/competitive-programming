#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define mod 1000000007
#define endl "\n"
#define tabl " "
#define mp make_pair
#define inf 1e18
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define pb push_back
#define mem1(x) memset((x),-1,sizeof(x))
#define mem0(x) memset((x),0,sizeof(x))
#define vli vector<ll>
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define deb(x) cerr<<#x<<" = ";_print(x);cerr<<endl
#define deb2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<"="<<y<<endl
#define logarr(arr,a,b)	{cerr<<"[";for(int z=(a);z<=(b);z++) _print(arr[z]),cerr<<" ";cerr<<"]";}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i*i<= n; i++)if (arr[i] == 0) { for (int j = 2 * i; j <= n; j += i)arr[j] = 1;}for(int i=2;i<=n;i++){if(arr[i]==0)vect.push_back(i);} return vect;}
ll phit(ll n){vector<ll> vect(n);vect[0]=0,vect[1]=1;for(ll i=2;i<=n;i++)vect[i]=i; for(ll i=2;i<=n;i++){if(vect[i]==i)for(ll j=i;j<=n;j+=i)vect[j]-=vect[j]/i;	} return vect[n];}
//-------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
//----------------------------------------------------------------------------------------------------------------
static const int N=3e5+10;
const int blk=555;
int currmax=0;
struct query
{
int l,r,idx;
bool operator<(query &o)
{
	if(l/blk!=o.l/blk)
	{
		return l/blk < o.l/blk;
	}
	return r<o.r;
}
};
query q[N];
int arr[N],f[N],ff[N],ans[N];
// bool comp(query a , query b)
// {
// 	if(a.l / blk != b.l/blk)
// 	return a.l/blk < b.l/blk;
 
// 	return a.r < b.r;
// }
void add(int x)
{
	int ele=arr[x];
	int pref=f[ele];
	f[ele]++;
	int curf=f[ele];
	ff[pref]--;
	ff[curf]++;
	if(currmax<curf)
	{
		currmax=curf;
	}
}
void remove(int x)
{
	int ele=arr[x];
	int pref=f[ele];
	f[ele]--;
	int curf=f[ele];
	ff[pref]--;
	ff[curf]++;
	while(ff[currmax]==0)
	{
		currmax--;
	}
}
void solve(int ttc)
{
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
cin>>arr[i];	
}
for(int i=0;i<m;i++)
{
	int x,y;
	cin>>x>>y;
	q[i].l=--x;
	q[i].r=--y;
	q[i].idx=i;
}
sort(q,q+m);
int lb=0,rb=-1;
for(int i=0;i<m;i++)
{
	int l=q[i].l;
	int r=q[i].r;
	// deb(mp(l,r));
	while(lb<l)
	{
		remove(lb++);
	}
	while(rb>r)
	{
		remove(rb--);
	}
	while(lb>l)
	{
		add(--lb);
	}
	while(rb<r)
	{
		add(++rb);
	}
	int total=(r-l)+1;
	int ceil=(total+1)/2;
	// deb(total);
	if(currmax<=ceil)
	{
		ans[q[i].idx]=1;
	}
	else
	{
		ans[q[i].idx]=total-2*(total-currmax);
	}
	// deb(currmax);
}
for(int i=0;i<m;i++)
{
	cout<<ans[i]<<endl;
}
}
int main()
{
	clock_t begin_69 = clock();
	fast_io;
	//write here
	int test_cases=1;
	//cin>>test_cases;////-\/-
	for(int ttc=1;ttc<=test_cases;ttc++)
	{
	solve(ttc);
	}
//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t terminator_69 = clock();
	  	cerr<<"\n\nExecuted In: "<<double(terminator_69 - begin_69) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif		
}
