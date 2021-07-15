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
static const int N=2e5+10;
vi adj[N];
int scan[N];
int lca[N][30],level[N];
void dfs(int node,int par,int l)
{
	level[node]=l;
	lca[node][0]=par;
	for(int child:adj[node])
	{
		if(child!=par)
		{
			dfs(child,node,l+1);
		}
	}
}
void buildparent(int n,int m)
{
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		int par=lca[i][j-1];
		if(par!=-1)
		{
			lca[i][j]=lca[par][j-1];
		}
	}
}
}
int binarylift(int a,int b,int p)
{
	if(level[a]>level[b])swap(a,b);
	int d=level[b]-level[a];
	while(d)
	{
		int i=log2(d);
		b=lca[b][i];
		d-=1<<i;
	}
	if(a==b)return a;
	for(;p>=0;p--)
	{
		if(lca[a][p]!=-1 and lca[a][p]!=lca[b][p])
		{
			a=lca[a][p];
			b=lca[b][p];
		}
	}
	return lca[a][0];
}
void dfs1(int node,int par)
{
	int ans=scan[node];
	for(int child:adj[node])
	{
		if(child!=par)
		{
			dfs1(child,node);
			ans+=scan[child];
		}
	}
	scan[node]=ans;
}
void solve(int ttc)
{
int n,m;
cin>>n>>m;
for(int i=1;i<=n-1;i++)
{
	int x,y;
	cin>>x>>y;
	adj[x].pb(y);
	adj[y].pb(x);
}
mem1(lca);
dfs(1,-1,1);
int p=log2(n);
buildparent(n,p);
for(int i=1;i<=n;i++)
	{
		cout<<lca[i][0]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<lca[i][1]<<" ";
	}
	cout<<endl;
while(m--)
{
	int a,b;
	cin>>a>>b;
	int x=binarylift(a,b,p);
	deb(x);
	scan[a]+=1;
	scan[b]+=1;
	scan[x]-=1;
	if(lca[x][0]!=-1)
	{
		scan[lca[x][0]]-=1;
	}
}
dfs1(1,-1);
for(int i=1;i<=n;i++)
{
	// cout<<scan[i]<<tabl;
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