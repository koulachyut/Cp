#include <bits/stdc++.h>
 using namespace std;

 const int N = 1e5 + 5; 
 int fen[N];
 void update(int i,int add){
    while(i<N)
    {
        fen[i]+=add;
        i +=(i &(-i));
    }
 }
 int sum(int i){
    int s=0;
    while(i>0){
        s+=fen[i];
        i=i -(i & (-i));
    }
    return s;
 }
 int rangeSum(int l,int r){
    return sum(r)- sum(l-1);
 }

 int find(int k) {
    int curr = 0;
    int prevSum = 0;
    for (int i =log2(n); i >= 0; i--) { // assuming N <= 2^20
        if (fen[curr + (1 << i)] + prevSum < k) {
            curr += (1 << i);
            prevSum += fen[curr];
        }
    }
    return (curr + 1); // 1-based index of the answer
}

 int main() {
    vector<int> arr = {0, 3, 2, -1, 6, 5, 4}; 
    int n = arr.size() - 1;

    for (int i = 1; i <= n; i++) {
        update(i, arr[i]);
    }

    // Sample range sum queries
    cout << "Sum of elements from 1 to 3: " << rangeSum(1, 3) << endl; // 3 + 2 + (-1) = 4
    cout << "Sum of elements from 2 to 5: " << rangeSum(2, 5) << endl; // 2 + (-1) + 6 + 5 = 12
 
    int k = 6;
    int idx = find(k);

    cout << "The smallest index with prefix sum >= " << k << " is: " << idx << endl;
  
    return 0;
}
