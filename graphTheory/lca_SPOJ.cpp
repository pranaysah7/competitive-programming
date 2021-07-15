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
const int N=1e6;
int lca[N][30];
int level[N];
vector<vi>adj(N,vi());
void bfs(int node,int par,int l)
{
	level[node]=l;
	lca[node][0]=par;
	queue<int>q;
	q.push(node);
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(int child:adj[curr])
		{
			level[child]=level[curr]+1;
			lca[child][0]=curr;
			q.push(child);
		}
	}

}
void buildparent(int n,int m)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(lca[i][j-1]!=-1)
			{
				int par=lca[i][j-1];
				lca[i][j]=lca[par][j-1];
			}
		}
	}
}
int binarylift(int a,int b,int p)
{
	if(level[b]>level[a])swap(a,b);
	int d=level[a]-level[b];
	while(d)
	{
		int i=log2(d);
		a=lca[a][i];
		d-=1<<i;
	}
	if(a==b)return a;
	for(int i=p;i>=0;i--)
	{
		if(lca[a][i]!=-1 and lca[a][i]!=lca[b][i])
		{
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}
void solve(int ttc)
{
int n;
cin>>n;
// adj.assign(n+1,vi());
for(int i=1;i<=n;i++)
{
	int x;
	scanf("%d",&x);
	if(x==0)continue;
	while(x--)
	{
		int a;
		scanf("%d",&a);
		adj[i].pb(a);
	}
}
mem0(level);
mem1(lca);
bfs(1,-1,1);
logarr(level,1,n);
int q;
scanf("%d",&q);
int p=log2(n);
buildparent(n,p);
printf("Case %d:\n",ttc);
while(q--)
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",binarylift(x,y,p));
}
for(int i=1;i<=n;i++)adj[i].clear();
}
int main()
{
	clock_t begin_69 = clock();
	// fast_io;
	//write here
	int test_cases;
	scanf("%d",&test_cases);////-\/-
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