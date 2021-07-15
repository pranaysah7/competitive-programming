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
const int N=1e5+10;
int arr[N],lz[4*N];
pair<int,pair<int,int>>st[4*N];//first denote no mod3==0 and etc
void buildtree(int si,int ss,int se)
{
	if(ss==se)
	{
		st[si].ff=1;
		st[si].ss.ff=0;
		st[si].ss.ss=0;
		return;
	}
	int mid=ss+(se-ss)/2;
	buildtree(si*2+1,ss,mid);
	buildtree(si*2+2,mid+1,se);
	st[si].ff=st[si*2+1].ff+st[si*2+2].ff;
	st[si].ss.ff=st[si*2+1].ss.ff+st[si*2+2].ss.ff;
	st[si].ss.ss=st[si*2+1].ss.ss+st[si*2+2].ss.ss;
}
void shift(auto& p)
{
	int temp=p.ff;
	p.ff=p.ss.ss;
	p.ss.ss=p.ss.ff;
	p.ss.ff=temp;
}
void update(int si,int ss,int se,int qs,int qe)
{
if(lz[si]!=0)
{
	int dx=lz[si];
	lz[si]=0;
	int t=dx%3;//cost of shifting is same as t%n where n is size of array of bounds
	while(t--)
	{
		shift(st[si]);
	}			
	if(ss!=se)
	{
		lz[si*2+1]+=dx;
		lz[si*2+2]+=dx;
	}
}
if(qs>se or qe<ss)return;
if(ss>=qs and se<=qe)
{
	shift(st[si]);
	if(se!=ss)
	{
		lz[si*2+1]+=1;
		lz[si*2+2]+=1;
	}
	return;
}
int mid=ss+(se-ss)/2;
update(si*2+1,ss,mid,qs,qe);
update(si*2+2,mid+1,se,qs,qe);
st[si].ff=st[si*2+1].ff+st[si*2+2].ff;
st[si].ss.ff=st[si*2+1].ss.ff+st[si*2+2].ss.ff;
st[si].ss.ss=st[si*2+1].ss.ss+st[si*2+2].ss.ss;
}
int query(int si,int ss,int se,int qs,int qe)
{
if(lz[si]!=0)
{
	int dx=lz[si];
	lz[si]=0;
	int t=dx%3;//cost of shifting is same as t%n where n is size of array of bounds
	while(t--)
	{
		shift(st[si]);
	}			
	if(ss!=se)
	{
		lz[si*2+1]+=dx;
		lz[si*2+2]+=dx;
	}
}
if(qe<ss or qs>se)return 0;
if(ss>=qs and se<=qe)return st[si].ff;
int mid=ss+(se-ss)/2;
return query(si*2+1,ss,mid,qs,qe)+query(si*2+2,mid+1,se,qs,qe);

}
void solve(int ttc)
{
int n,m;
cin>>n>>m;
// buildtree(0,0,n-1);
while(m--)
{
	int code;
	cin>>code;
	if(code==0)
	{
		int a,b;
		cin>>a>>b;
		update(0,0,n-1,a,b);
	}
	else
	{
		int a,b;
		cin>>a>>b;
		cout<<query(0,0,n-1,a,b)<<endl;
	}
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