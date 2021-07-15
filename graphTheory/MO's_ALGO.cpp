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
// #define BLOCK 555
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;
int BLOCK;
struct query{
    int l;
    int r;
    int i;
    bool operator<(const query &other)const
    {
        if(l/BLOCK!=other.l/BLOCK)
        {
            return l/BLOCK<other.l/BLOCK;
        }
        return r<other.r;
    }
};
query Q[200001];
int ar[30001] , ans[200001];
int fre[1000001];
int cnt = 0;
 
bool comp(query a , query b)
{
    if(a.l / BLOCK != b.l/BLOCK)
    return a.l/BLOCK < b.l/BLOCK;
    
    return a.r < b.r;
}
 
void add(int pos)
{
    fre[ar[pos]]++;
    if(fre[ar[pos]] == 1)
    cnt++;
}
 
void remove(int pos)
{
    fre[ar[pos]]--;
    if(fre[ar[pos]] == 0)
    cnt--;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int n , q;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>ar[i];
    BLOCK=sqrt(n);
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].i = i , Q[i].l , Q[i].r;
    }
    
    sort(Q , Q+q );
    
    //why ML = 0 , and MR = -1?
    int lb = 1 , rb = 0;
    for(int i=0;i<q;i++)
    {
        int l = Q[i].l;
        int r = Q[i].r;
        
        while(lb<l)
        {
            remove(lb++);
        }
        while(lb>l)
        {
            add(--lb);
        }
        while(rb<r)
        {
            add(++rb);
        }
        while(rb>r)
        {
            remove(rb--);
        }
        ans[Q[i].i] = cnt;
    }
    
    for(int i=0;i<q;i++)
    cout<<ans[i]<<'\n';
}