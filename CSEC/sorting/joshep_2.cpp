#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void run_case() {
    int n, k;
    cin >> n >> k;

    ordered_set<int> set;
    for (int i = 1; i <= n; i++) set.insert(i);

    int pos = k % n;
    while (!set.empty()) {
        pos %= set.size();                        
        int val = *set.find_by_order(pos);        
        cout << val << " ";
        set.erase(val);                           
        if (!set.empty())
            pos = (pos + k) % set.size();        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    while (tc--) run_case();
    return 0;
}
