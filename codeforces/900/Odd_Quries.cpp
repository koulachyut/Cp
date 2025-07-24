#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
{
    long long n,q;
    cin>>n>>q;
    vector<long long>a(n);
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    long long old_sum= accumulate(a.begin(),a.end(),0LL);

    vector<long long> prefix_sum(n+1,0);
    for(int i=1;i<=n;i++){
        prefix_sum[i]= prefix_sum[i-1]+a[i-1];
    }
    while(q--){
        long long l,r,k;
        cin >> l >> r >> k;
        long long sum_to_remove= prefix_sum[r]-prefix_sum[l-1];
        long long sum_to_add= (r-l+1)*k;
        long long tot_sum= old_sum +sum_to_add-sum_to_remove;
        if(tot_sum % 2 == 1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    
}
   return 0;
}