// #include<bits/stdc++.h>
// using namespace std;
// using namespace chrono;
// typedef long long ll;
// #define mod 1000000007
// #define endl "\n"
// #define tabl " "
// #define mp make_pair
// #define inf 1e18
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define ff first
// #define ss second
// #define pb push_back
// #define vli vector<ll>
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define deb(x) cerr<<#x<<" = ";_print(x);cerr<<endl
// #define deb2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<"="<<y<<endl
// #define logarr(arr,a,b)	{cerr<<"[";for(int z=(a);z<=(b);z++) _print(arr[z]),cerr<<" ";cerr<<"]";}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
// vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i*i<= n; i++)if (arr[i] == 0) { for (int j = 2 * i; j <= n; j += i)arr[j] = 1;}for(int i=2;i<=n;i++){if(arr[i]==0)vect.push_back(i);} return vect;}
// ll phit(ll n){vector<ll> vect(n);vect[0]=0,vect[1]=1;for(ll i=2;i<=n;i++)vect[i]=i; for(ll i=2;i<=n;i++){if(vect[i]==i)for(ll j=i;j<=n;j+=i)vect[j]-=vect[j]/i;	} return vect[n];}
// //-------------------------------------------------------------------------------------------------------------
// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(double t) {cerr << t;}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(vector <T> v);
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

// //----------------------------------------------------------------------------------------------------------------
// vector<vi>adj(1000,vi());
// int vis[1000];
// int low[1000];
// int in[1000],timer;
// set<int>s;
// void dfs(int node,int par=-1)
// {
// vis[node]=1;
// // deb(par);
// in[node]=low[node]=timer++;
// int children=0;
// for(auto child:adj[node])
// {
// 	if(child==par)continue;
// 	if(vis[child])
// 	{	
// 		low[node]=min(low[node],in[child]);
// 	}
// 	else
// 	{
// 		dfs(child,node);
// 		++children;
// 		low[node]=min(low[node],low[child]);
// 		if(low[child]>=in[node] and par!=-1)
// 		{
// 			s.insert(node);
// 		}

// 	}
// 	if(par==-1 and children>1)
// 	{
// 		s.insert(node);
// 	}
// }
// }
// int main()
// {
// 	clock_t begin_69 = clock();
// 	fast_io;
// 	//write here
// int n,m;
// cin>>n>>m;
// // int temp[n+1][m+1]
// {
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=m;j++)
// 		{
// 			char x;
// 			cin>>x;
// 			if(x=='#')
// 			{
// 				adj[i].pb(j);
// 				adj[j].pb(i);
// 			}

// 		}
// 	}
// }
// dfs(1);
// // deb(s);
// cout<<s.size()<<endl;


// //-----------------------------------------------------------------------------------------------------------------------------//
// #ifndef ONLINE_JUDGE
	
//   		clock_t terminator_69 = clock();
// 	  	cerr<<"\n\nExecuted In: "<<double(terminator_69 - begin_69) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
// #endif		
// }