#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ff first
#define ss second
#define ar array
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    fastio
    int n;
    cin >> n;

    vector<ar<int, 3>> a(n); // [l, r, idx]
    rep(i, n) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    // Sort by l asc, r desc for contains logic
    sort(a.begin(), a.end(), [&](ar<int,3>& i, ar<int,3>& j) {
        return i[0] < j[0] || (i[0] == j[0] && i[1] > j[1]);
    });

    vector<int> contains(n), contained(n);
    oset<pair<int, int>> rightSet;

    // Calculate how many intervals each interval contains
    for (int i = n - 1; i >= 0; i--) {
        int r = a[i][1];
        int id = a[i][2];
        contains[id] = rightSet.order_of_key({r + 1, -1});
        rightSet.insert({r, i}); // `i` used for uniqueness
    }

    // Calculate how many intervals contain each interval
    rightSet.clear();
    for (int i = 0; i < n; i++) {
        int r = a[i][1];
        int id = a[i][2];
        contained[id] = i - rightSet.order_of_key({r, -1});
        rightSet.insert({r, i});
    }

    // Output results
    rep(i, n) cout << contains[i] << " ";
    cout << "\n";
    rep(i, n) cout << contained[i] << " ";
    cout << "\n";

    return 0;
}
