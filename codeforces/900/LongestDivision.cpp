// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         long long n;
//         cin >> n;

//         int cnt = 0;
//         int maxi = 0;

//         for(long long i = 1; i <= n; i++) {
//             if((n % i == 0) && (i > 1 && n % (i - 1) == 0)) {
//                 cnt++;
//                 maxi = max(maxi, cnt);
//             }
//             else if(n % i == 0) {
//                 cnt++;
//                 maxi = max(maxi, cnt);
//             }
//             else {
//                 cnt = 0;
//             }
//         }

//         cout << maxi << endl;
//     }
// }
 #include <bits/stdc++.h>
 using namespace std;

 int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int i=1;
        while(n%i ==0){
            i++;
        }
   cout<<i-1 << endl;
    }
 }