#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;

    vector<pair<pair<int,int>,int>> customers(n);
    //first.first=incoming
    //second.second = outgoing
    //second= index;

    }
    sort(customers.begin(),customers.end());
    vector<int> roomassigned(n);
    int roomId=1;

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> rooms;

        for(int i=0;i<n;i++){
            if(rooms.size()==0){
                roomassigned[customers[i].second]= roomId;
                rooms.push(make_pair(customers[i].first.second,roomId));
                roomId++;
            }
            else{
                if(rooms.top().first <customers[i].first.first){
                roomassigned[customers[i].second] = rooms.top().second;
                pair<int, int> x = rooms.top();
                rooms.pop();
                rooms.push(make_pair(customers[i].first.second, x.second));
                }
                else {
                roomassigned[customers[i].second] = roomId;
                rooms.push(make_pair(customers[i].first.second, roomId));
                roomId++;
            }
            }
        }
        cout << roomId - 1 << endl;
            for(int i = 0; i < n; i++) {
                cout << roomassigned[i] << " ";
            }
        return 0;
}