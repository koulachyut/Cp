#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // ✅ Required for LLONG_MIN


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    long long n,k;
    cin >> n>>k;
    vector<long long> points_arr;
    points_arr.push_back(0);
    for(int i=0;i<n;i++){
        long long point;
        cin>>point;
        points_arr.push_back(point);
    }
    points_arr.push_back(k);
    long long x= points_arr.size();

    long long maxi = LLONG_MIN; 

    for(int i=1;i<x;i++){
        if(i==x-1){
            maxi=max(maxi,2*(points_arr[i]-points_arr[i-1]));
        }
        else{
            maxi= max(maxi,points_arr[i]-points_arr[i-1]);
        }
    }
    cout<< maxi<<endl;
}
return 0;

}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long n, x;
//         cin >> n >> x;
//         vector<long long> points_arr;
//         points_arr.push_back(0);
//         for (int i = 0; i < n; i++) // n
//         {
//             long long point;
//             cin >> point;
//             points_arr.push_back(point);
//         }
//         points_arr.push_back(x);
//         n = points_arr.size();
//         // inputs

//         long long max_distance_between_points = INT_MIN;
//         for (int i = 1; i < n; i++) // n
//         {
//             if (i == n - 1) // last point
//                 max_distance_between_points = 
//                 max(max_distance_between_points, 2 * (points_arr[i] - points_arr[i - 1]));
//             else
//                 max_distance_between_points = 
//                 max(max_distance_between_points, points_arr[i] - points_arr[i - 1]);
//         }
//         cout << max_distance_between_points << endl;
//     }
//     return 0;
// }