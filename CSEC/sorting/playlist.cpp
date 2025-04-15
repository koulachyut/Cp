#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
 cin>>arr[i];
    }
    int i=0,j=0,max_len=0,cur_len=0;
    map<int,int> mpp;
    while(j<n){
        if(mpp.find(arr[j])==mpp.end()|| mpp[arr[j]]==0){
            mpp[arr[j]]++;
           cur_len++;
            max_len=max(max_len,cur_len);
             j++;
        }
        else{
            cur_len--;
            mpp[arr[i]]--;
            i++;
            
        }
    }
    cout<<max_len<<endl;
}