#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,x;cin>> n>>x;
    int peopleWeight[n];
    for(auto &x :peopleWeight)cin >> x;

    vector<pair <int,int>> dp(1<<n);

    dp[0] ={1,0};
    for(int subset = 1;subset <(1<<n);subset++){
        dp[subset]={21,0};

        for(int person=0; person <n;person++){
            //We check if the person is a part of the chosen subset of people

            if((subset >> person) & 1){
                auto[rides,weight] =dp[subset ^ (1 << person)];
                //gets the state of the elevator rides upto the last chosen person

                if(weight +peopleWeight[person] > x){
                  rides++;
                  weight=min(peopleWeight[person],weight);

                }
                else weight +=peopleWeight[person];
                dp[subset]=min(dp[subset],{rides,weight});
            }
        }
    }
     cout << dp[(1 << n) - 1].first;
    //Minimum Number of rides with all the people chosen   
}