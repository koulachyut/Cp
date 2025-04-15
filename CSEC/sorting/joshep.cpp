#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(ll N)
{


    queue<ll>q;
    for(ll i=1;i<=N;i++){
        q.push(i);
    }

    bool flag= false;
    while(!q.empty()){
        ll ele=q.front();
        q.pop();

        if(flag){
            cout<<ele<<" ";
        }
        else{
            q.push(ele);
        }
        flag =!flag;
    }
    cout<<endl;

}

int main()
{
    ll N;
    
    cin >> N;
    solve(N);
    return 0;
}
