#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
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
const int maxN = 100001;
const int BLK = 400;
// int BLK;
vi ar[maxN];
int S[maxN] , T[maxN] , FT[2*maxN] , col[maxN];
int nodeF[maxN] , eleF[maxN] , FF[maxN];
int ans[maxN] , n;
int timer;
int bucket[maxN];
struct query{
	int l;
	int r;
	int idx;
	int k;
};

query Q[maxN];

void dfs(int node , int par)
{
	S[node] = timer;
	FT[timer] = node;
	timer++;
	
	for(int child : ar[node])
	if(child != par)
	dfs(child , node);
	
	T[node] = timer;
	FT[timer] = node;
	timer++;
}
int getblock(int x)
{
x=(BLK+x-1)/BLK;
return x;
}
void add(int idx)
{
	int node = FT[idx];
	int c = col[node];
	nodeF[node]++;
	
	if(nodeF[node] == 2)
	{
		eleF[c]++;
		FF[eleF[c]]++;
		bucket[getblock(eleF[c])]++;
		FF[eleF[c]-1]--;
		bucket[getblock(eleF[c]-1)]--;
	}
	
}

void remove(int idx)
{
	int node = FT[idx];
	int c = col[node];
	nodeF[node]--;
	
	if(nodeF[node] == 1)
	{
		eleF[c]--;
		FF[eleF[c]]++;
		bucket[getblock(eleF[c])]++;
		FF[eleF[c]+1]--;
		bucket[getblock(eleF[c]+1)]--;
	}	
}

bool comp(query a , query b)
{
	int x = a.l/BLK;
	int y = b.l/BLK;
	
	if(x != y)
	return x < y;
	
	return a.r<b.r;
}

int sans(int x,int y)
{
int ans=0;
int lb=getblock(x);
int rb=getblock(y);
if(lb==rb)
{
	for(int i=x;i<=y;i++)
	{
		ans+=FF[i];
	}
	return ans;
}
for(int i=x;i<=BLK*(lb);i++)
{
	ans+=FF[i];
}
for(int i=lb+1;i<rb;i++)
{
	ans+=bucket[i];
}
for(int i=rb*BLK;i<=y;i++)
{
	ans+=FF[i];
}
return ans;
}
int getAns(int k , int n)
{
	return sans(k,n);
}
int main()
{
	int q , a , b , k;
	cin>>n>>q;
	// BLK=sqrt(n);
	REP(i , n) cin>>col[i];
	
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	timer = 1;
	dfs(1 , -1);
	
	for(int i=0;i<q;i++)
	{
		cin>>a>>k;
		Q[i].l = S[a];
		Q[i].r = T[a];
		Q[i].k = k;
		Q[i].idx = i;
	}
	
	sort(Q , Q+q , comp);
	
	int ML = 1 , MR = 0;
	
	for(int i=0;i<q;i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
		int idx = Q[i].idx;
		k = Q[i].k;
		
		while(MR < R)
		MR++ , add(MR);
		
		while(ML > L)
		ML-- , add(ML);
		
		while(MR > R)
		remove(MR) , MR--;
		
		while(ML < L)
		remove(ML) , ML++;
		
		ans[idx] = getAns(k , n);
		
	}
	
	for(int i=0;i<q;i++)
	cout<<ans[i]<<endl;
}