#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 998244353
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;





vector<int> ar[300001];
int col[300001] , vis[300001];
int C[2];

long long int power(lli a , lli n)
{
	long long int res = 1;
	while(n)
	{
		if(n % 2){
			res = (res * a) % mod;
		}
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}

int dfs(int node , int c)
{
	vis[node] = 1;
	C[c]++;
	col[node] = c;
	
	for(int child : ar[node]){
		
		if(vis[child] == 0){
			int code = dfs(child , c ^ 1);
			
			if(code == -1){
				return -1;
			}
		}
		else{
			if(col[child] == col[node]){
				return -1;
			}
		}
		
	}
	
	return 0;
}



int main()
{
	int n , m , a , b , t;
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		ar[i].clear() , vis[i] = 0;
		
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
		
		long long int res = 1;
		bool flag = true;
		
		for(int i=1;i<=n;i++)
		if(vis[i] == 0){
			
			C[0] = C[1] = 0;
			int code = dfs(i , 0);
			
			if(code == -1){
				flag = false;
				break;
			}
			
			res = (res * (power(2 , C[0]) + power(2 , C[1]))) % mod;
			
		}
		
		if(flag == false){
			cout<<0<<endl;
		}
		else{
			cout<<res<<endl;
		}
	}
	
	
}