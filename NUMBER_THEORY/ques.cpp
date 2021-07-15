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
void solve()
{
	int l;
	int cou1(0),cou2(0);
	cin>>l;
	int arr[l];
	string s;
	cin>>s;
	int size=s.length();
	for(int i=0;i<l/2;i++)
	{
		
		if(s[i]=='1')
		{
			cou1++;
		}
		if(s[i]=='0')
		{
			cou2++;
		}

	}
	
	int ans=(cou1*100)/2;
	if(ans>=50)
	{
		cout<<"YES\n";
		return;
	}
	if(cou1>cou2)
	{
		cout<<"YES\n";
		return;
	}
	else
	{
		cout<<"NO\n";
		return;
	}


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
	solve();
}





//-----------------------------------------------------------------------------------------------------------------------------//
auto stop1=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
	
		cerr << "\nTime: "<<duration.count()/1000<<"ms"<<endl;
#endif		
}