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
vi adj[2001];
int vis[2001];
int col[2001];
bool dfs(int v,int c)
{
	vis[v]=1;
	col[v]=c;
	for(int child:adj[v])
	{
		if(!vis[child])
		{
			
			// bool res=dfs(child,c^1);
			if(!dfs(child,c^1))
			{
				return false;
			}	
		}	
			else
				{
					if(col[v]==col[child])
					{
						return false;
					}
				}
		}
	
	return true;
}
int main()
{
	clock_t begin = clock();
	fast_io;
	//write here
int t,n,m,a,b;
cin>>t;
for(int tc=1;tc<=t;tc++)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)adj[i].clear(), vis[i]=0 ,col[i]=0;
	while(m--)
	{
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bool ans=dfs(i,0);
				if(ans==false)
				flag=false;
		}
	}
cout<<"Scenario #"<<tc<<":"<<endl;
if(flag)
{
	cout<<"No suspicious bugs found!"<<endl;
}
else
{
	cout<<"Suspicious bugs found!"<<endl;
}
}





//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t end = clock();
	  	cerr<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif		
}