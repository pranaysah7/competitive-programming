#include<cstdlib> 
#include<cstring> 
#include<iostream> 
using namespace std; 
 
int dp[2000][2000]; 
 
int die_hard( int step , int hp , int ar ) { 
 
	if( hp<1 || ar<1 )	return 0; 
 
	if( dp[hp][ar] != -1 )	return dp[hp][ar]; 
 
	if( step )	return die_hard( 0 , hp+3 , ar+2 ) + 1; 
 
	dp[hp][ar] = max ( die_hard( 1 , hp-20 , ar+5 ), die_hard( 1 , hp-5, ar-10 ) ) + 1; 
 
	return dp[hp][ar]; 
 
} 
 
int main() { 
 
	ios::sync_with_stdio(false); 
	 
	int tt; 
	cin >> tt; 
	 
	
	 
	while(tt--){ 
	 
		int hp , ar; 
		cin >> hp >> ar;
		memset( dp , -1 , sizeof dp );  
		cout << die_hard( 0 , hp+3 , ar+2 ) << endl; 
	 
	} 
 
	return 0; 
 
} 