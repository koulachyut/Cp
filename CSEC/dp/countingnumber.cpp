// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// ll dp[20][10][2][2];
// ll solve(string &number,int n,int x,bool leadind_zeros,bool tight){
//     if(n==0){
//         return 1;
//     }
//     if(x!= -1 && dp[n][x][leadind_zeros][tight]!=-1)
//     return 1;
//     int lb=0;
//     int ub= tight?(number[number.length()-n] -'0') :9;
//     ll answer=0;
//     for(int dig =lb;dig<=ub;dig++){
//         if(dig ==x && leadind_zeros==0)
//         continue;
//         answer += solve(number,n-1,dig,(leadind_zeros && dig==0),tight && dig==ub);
//     }
//     return dp[n][x][leadind_zeros][tight] = answer; // Memoize the result

// }



// int main(){
//     ios_base::sync_with_stdio(false);
//     cout.tie(0);
//     int t=1;
//     while(t--){
//         ll a,b;
//     cin>>a>>b;

//     memset(dp,-1,sizeof(dp));
//     string A =to_string(a-1);
//     string B= to_string(b);
//     ll ans1=solve(B,B.length(),-1,1,1);
//     memset(dp,-1,sizeof (dp));
//     ll ans2 =solve(A,A.length(),-1,1,1);
//     cout<< ans1-ans2;
// }
    
// }
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20][10][2][2];

ll solve(string &number, int n, int x, bool leadind_zeros, bool tight) {
    if (n == 0) {
        return 1; // Base case: one valid number
    }
    
    // Check if the result is already computed
    if (x != -1 && dp[n][x][leadind_zeros][tight] != -1)
        return dp[n][x][leadind_zeros][tight];

    int lb = 0;
    int ub = tight ? (number[number.length() - n] - '0') : 9; // Upper bound depends on `tight`
    ll answer = 0;

    for (int dig = lb; dig <= ub; dig++) {
        if (dig == x && leadind_zeros == 0) // Avoid consecutive same digits (excluding leading zeros)
            continue;
        
        answer += solve(number, n - 1, dig, (leadind_zeros && dig == 0), tight && (dig == ub));
    }

    return dp[n][x][leadind_zeros][tight] = answer; // Memoize the result
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp)); // Clear DP table
    string A = to_string(a - 1);
    string B = to_string(b);

    ll ans1 = solve(B, B.length(), -1, 1, 1);
    
    memset(dp, -1, sizeof(dp)); // Clear DP table again for second calculation
    ll ans2 = solve(A, A.length(), -1, 1, 1);

    cout << ans1 - ans2 << "\n"; // Compute final result
}
