#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define mod 1000000007
#define endl "\n"
#define tabl " "
#define inf 1e18
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define pb push_back
#define vli vector<ll>
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define deb(x) cerr<<#x<<" = ";_print(x);cerr<<endl
#define deb2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<"="<<y<<endl
#define logarr(arr,a,b)	{cerr<<"[";for(int z=(a);z<=(b);z++) _print(arr[z]),cerr<<" ";cerr<<"]";}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i*i<= n; i++)if (arr[i] == 0) { for (int j = 2 * i; j <= n; j += i)arr[j] = 1;}for(int i=2;i<=n;i++){if(arr[i]==0)vect.push_back(i);}delete [] arr; return vect;}
ll phit(ll n){vector<ll> vect(n);vect[0]=0,vect[1]=1;for(ll i=2;i<=n;i++)vect[i]=i; for(ll i=2;i<=n;i++){if(vect[i]==i)for(ll j=i;j<=n;j+=i)vect[j]-=vect[j]/i;	} return vect[n];}
//-------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

//----------------------------------------------------------------------------------------------------------------
vector<int> adj[100001];
int vis[100001];
int dist[100001];
vli primes;
vli neededprimes;
bool isvalid(int a,int b)
{
	int cnt(0);
	while(a)
	{
		if(a%10==b%10)cnt++;
		a/=10,b/=10;	
	}
	if(cnt==3)return true;
	else
	{
		return false;
	}	
}
void buildGraph(int x,int y)
{
for(int i=0;i<neededprimes.size();i++)
{
	for(int j=i+1;j<neededprimes.size();j++)
	{
		if(isvalid(neededprimes[i],neededprimes[j]))
		{
			adj[neededprimes[i]].pb(neededprimes[j]);
			adj[neededprimes[j]].pb(neededprimes[i]);
		}
	}
}
}
void bfs(int node)
{
	vis[node]=1;
	dist[node]=0;
	queue<int>q;
	q.push(node);
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(auto child:adj[curr])
		{
			if(!vis[child])
			{
				vis[child]=1;
				q.push(child);
				dist[child]=dist[curr]+1;
			}
		}
	}
}
int main()
{
	clock_t begin = clock();
	fast_io;
	//write here
int t,a,b;
cin>>t;
primes=sieve(100000);
for(int i=168;i<primes.size();i++)
{
	if(primes[i]>=1000 and primes[i]<=9999)
	{
		neededprimes.pb(primes[i]);
	}
}
// cout<<neededprimes.size()<<endl;
// deb(neededprimes);
while(t--)
{
	cin>>a>>b;
	for(int i=1000;i<=9999;i++)
	{
		dist[i]=-1;
		vis[i]=0;
	}
	buildGraph(a,b);
	bfs(a);
	if(dist[b]==-1)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		cout<<dist[b]<<endl;
	}
}






//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t end = clock();
	  	cerr<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif		
}