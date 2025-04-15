#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
int dp[1001][1001];
 
int main(){
 
	int n;
	cin>>n;
 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;
			cin>>x;
			if(x == '.'){
 
				dp[i][j] = ( dp[i-1][j] + dp[i][j-1] ) % MOD;
				
				if( (i==1) && (j==1) ){
					dp[i][j] = 1;
				}
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
 
	cout << dp[n][n] << endl;
 

}