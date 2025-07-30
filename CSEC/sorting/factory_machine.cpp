#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  
    ll n ,k;
    cin>> n>>k;

    vector<ll>nums(n);
    for(int i=0;i<n;i++){
        cin>> nums[i];
    }
    

    ll l=0,h=1e18;
    int ans=0;
    while(l<=h){
    ll mid= l+(h-l)/2;
    ll sum=0;
    for(ll i=0;i<n;i++){
       sum+=(mid/nums[i]);
       if(sum>= k)
       break;
    }
    if(sum>=k){
        ans=mid;
        h=mid-1;
    }
    else{
        l= mid+1;
    }
   }
                 cout<<ans<<" ";
}
  
   
