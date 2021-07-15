#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define mod 1000000007
#define endl "\n"
#define inf 1e18
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define vli vector<ll>
#define vi vector<int>
#define deb(x) cout<<#x<<" = "<< x << endl
#define deb2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<"="<<y<<endl
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

//-------------------------------------------------------------------------------------------------------------
ll arr[3];
ll I[3][3],T[3][3];
void mul(ll A[3][3],ll B[3][3],int dim)
{
ll res[dim+1][dim+1];	
for(int i=1;i<=dim;i++)
{
	for(int j=1;j<=dim;j++)
	{
		res[i][j]=0;
		for(int k=1;k<=dim;k++)
		{
			res[i][j]=(res[i][j]+(A[i][k]*B[k][j])%mod)%mod;
		}

	}
}
for(int i=1;i<=dim;i++)
{
	for(int j=1;j<=dim;j++)
	{
		A[i][j]=res[i][j];
	}
}
}
ll getfeb(int n)
{
if(n<=2)
{
	return arr[n];
}
I[1][1]=I[2][2]=1;
	I[1][2]=I[2][1]=0;
	T[1][1]=0;
	T[1][2]=T[2][2]=T[2][1]=1;
	 n=n-1;
	while(n)
	{
		if(n%2)
		{
			mul(I,T,2);
			n--;
		}
		else
		{
			mul(T,T,2);
			n/=2;
		}
	}
	ll x=(arr[1]*I[1][1]+arr[2]*I[2][1])%mod;
	return x;
}

int main()
{
	auto start1=high_resolution_clock::now();
	fast_io;
	//write here
int t;
cin>>t;
while(t--)
{
	int n;
cin>>arr[1]>>arr[2]>>n;
cout<<getfeb(++n)<<endl;;
}





//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}