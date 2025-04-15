#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,n,point,left,right;
    cin>>x>>n;
    set<int>points={0,x};
    multiset<int>lengths={x};
    while(n--){
        cin>>point;
        auto it= points.upper_bound(point);

        left = *prev(it);
        right = *it;
        lengths.erase(lengths.find(right-left));
        
        lengths.insert(point-left);
        lengths.insert(right-point);

        points.insert(it,point);

        cout<<*lengths.rbegin()<<" ";
    }
    return 0;
}