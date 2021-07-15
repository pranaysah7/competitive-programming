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
int n,m;
char arr[1001][1001];
int vis[1001][1001];
int dis[1001][1001];
pair<int,int> par[1001][1001];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
string ans="";
bool isvalid(int a,int b)
{
	return (a>0 and a<n+1 and b>0 and b<m+1 and !vis[a][b] and arr[a][b]!='#');
}
void bfs(int x,int y)
{
	vis[x][y]=1;
	dis[x][y]=0;
	queue<pair<int,int>>q;
	q.push(mp(x,y));
	par[x][y]=mp(-110,-110);
	while(!q.empty())
	{
		int cx=q.front().ff;
		int cy=q.front().ss;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=cx+dx[i];
			int ny=cy+dy[i];
			if(isvalid(nx,ny))
			{
				vis[nx][ny]=1;
				dis[nx][ny]=dis[cx][cy]+1;
				par[nx][ny]=mp(cx,cy);
				q.push(mp(nx,ny));
			}
		}
	}
}
int main()
{
	clock_t begin_69 = clock();
	fast_io;
	//write here
cin>>n>>m;
memset(dis,-1,sizeof(dis));
pair<int,int>p1,p2;
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		cin>>arr[i][j];
		if(arr[i][j]=='A')p1=mp(i,j);
		if(arr[i][j]=='B')p2=mp(i,j);
	}
}
bfs(p1.ff,p1.ss);
deb(p1);
deb(p2);
if(dis[p2.ff][p2.ss]==-1)
{
	cout<<"NO";
}
else
{
	cout<<"YES\n";
	cout<<dis[p2.ff][p2.ss]<<endl;
	int i=p2.ff,j=p2.ss;
 
 
	while(i!=-110 and j!=-110)
	{
		pair<int,int>k;
		k.ff=par[i][j].ff;
		k.ss=par[i][j].ss;
		int xp,yp;
		xp=i-k.ff;
		yp=j-k.ss;
		// deb2(xp,yp);
		if(xp==-1 and yp==0)
		{
			ans.pb('U');
		}
		if(xp==0 and yp==1)
		{
			ans.pb('R');
		}
		if(xp==1 and yp==0)
		{
			ans.pb('D');
		}
		if(xp==0 and yp==-1)
		{
			ans.pb('L');
		}
		i=k.ff;
		j=k.ss;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	// cout<<ans.length()<<endl;
}
 
 
 
//-----------------------------------------------------------------------------------------------------------------------------//
#ifndef ONLINE_JUDGE
	
  		clock_t terminator_69 = clock();
	  	cerr<<"\n\nExecuted In: "<<double(terminator_69 - begin_69) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif		
}