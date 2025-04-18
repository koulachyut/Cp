#include <bits/stdc++.h>
 using namespace std;
#define ll long long
 int main(){
   int t;
   cin>>t;
   while(t--){
   ll n,k;
   cin>>n>>k;
   vector<ll>ans;
   for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    ans.push_back(temp);
   }
   sort(ans.begin(),ans.end());
   int cnt=0;
   int ansss=1;
   for(int i=1;i<n;i++){
    if(ans[i]-ans[i-1] <= k){
        ansss++;
    }
    
    else{
        cnt= max(cnt,ansss);
        ansss=1;
        
    }
   }
   cnt= max(cnt,ansss);
   cout<< n-cnt<<"\n";
    
   }

   } 

 