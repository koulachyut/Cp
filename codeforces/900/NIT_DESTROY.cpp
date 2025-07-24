#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int tot_zero=0;
        for(int i=0;i<n;i++){
          if(a[i]==0){
            tot_zero++;
          }
        }
        int left=0,right=n-1;
        while(left <n && a[left]==0)
        left ++;

        while(right >= 0 && a[right]==0 )
        right--;
        
        bool zero= false;
        for(int i=left;i<=right;i++){
         if(a[i]==0){
         zero=true;
         break;
        }
        }
         
         if(tot_zero==n)
         cout<<0<<endl;
         else if(!zero)
         cout<<1<<endl;
         else
         cout<<2<<endl;
    }
}