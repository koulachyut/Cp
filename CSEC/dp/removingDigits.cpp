#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define INF 1e9
typedef long long ll;

int main(){
    int n ;
    cin>> n;
    vector <int>minsteps(n+1,INF);
    minsteps[0]=0;
    for(int i=0;i<= n;i++){
        int temp=i;
        while(temp>0){
            minsteps[i]= min(minsteps[i],minsteps[i-temp%10]+1);
            temp /=10;
        }
    }
    cout<<minsteps[n];
}