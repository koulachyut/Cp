#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        long long a,b,n;
        cin>> a>>b>>n;
        vector<long long>x(n);
        for(int i=0;i<n;i++){
            cin>> x[i];
        } 
        long long max_time=b;
        for(int i=0;i<n;i++){
            max_time+= min(x[i],a-1);
        }
        cout<< max_time<<endl;

    }
    return 0;
}