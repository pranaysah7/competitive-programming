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
const int N=1e5;
vi st[4*N];
int arr[N];
void buildtree(int si,int ss,int se)
{
	if(ss==se)
	{
		st[si].pb(arr[ss]);
		return;
	}
	int mid=ss+(se-ss)/2;
	buildtree(si*2+1,ss,mid);
	buildtree(si*2+2,mid+1,se);

	int i=0;
	int j=0;
	while(i<st[si*2+1].size() and j<st[si*2+2].size())
	{
		if(st[si*2+1][i]<=st[si*2+2][j])
		{
			st[si].pb(st[si*2+1][i++]);
		}
		else
		{
			st[si].pb(st[si*2+2][j++]);
		}
	}
	while(i<st[si*2+1].size())
	{
		st[si].pb(st[si*2+1][i++]);
	}
	 while(j<st[si*2+2].size())
	 {
	 	st[si].pb(st[si*2+2][j++]);
	 }
}

int query(int si,int ss,int se,int qs,int qe,int k)
{
if(qe<ss or qs>se)return 0;
if(ss>=qs and se<=qe)
{
	int re;
	re=lower_bound(all(st[si]),k)-st[si].begin();
	return re;
}
int mid=ss+(se-ss)/2;
return query(si*2+1,ss,mid,qs,qe,k)+query(si*2+2,mid+1,se,qs,qe,k);
}
void solve(int ttc)
{
int n,q,l,r,k;
cin>>n>>q;
for(int i=0;i<=n-1;i++)cin>>arr[i];
buildtree(0,0,n-1);
while(q--)
{
	cin>>l>>r>>k;
	cout<<query(0,0,n-1,l,r,k)<<endl;
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