#include<bits/stdc++.h>
using namespace std;
#define ll long long 

struct range{
    int left,right,index;
    bool operator < (const range &other)const{
        if(left==other.left)
        return right > other.right;
        return left <other.left;
    }
};

int main(){
    int n;
    cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> containes(n);
    for(int i=0;i<n;i++){
        cin>>ranges[i].left;
        cin>>ranges[i].right;
        ranges[i].index=i;
    }
    sort(ranges.begin(),ranges.end());
    int maxend=0;
        for(int i = 0; i<n; i++){
        if(ranges[i].right <= maxend)
            contained[ranges[i].index] = true;
        maxend = max(maxend , ranges[i].right);
    }
 
 
    int minend = INT_MAX;
    for(int i = n - 1; i>= 0 ; i--){
        if(ranges[i].right >= minend)
            containes[ranges[i].index] = true;
        minend = min(minend , ranges[i].right);
    }
 
    for(int i = 0; i<n; i++){
        cout<<containes[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<contained[i]<<" ";
    }
    cout<<endl;
 
    return 0;

}