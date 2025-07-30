#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll c;
        cin >> n >> c;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end()); // Sort increasing

        int coins = 0;
        for (int i = 0; i < n; ++i) {
            ll weight = a[i];
            int doublings = n - 1 - i; // bags destroyed before this one

            // Multiply weight by 2^doublings safely
            for (int d = 0; d < doublings && weight <= c; ++d) {
                if (weight > c / 2) { // prevent overflow
                    weight = c + 1; // will cost 1 coin
                    break;
                }
                weight *= 2;
            }

            if (weight > c) coins++;
        }

        cout << coins << "\n";
    }

    return 0;
}
