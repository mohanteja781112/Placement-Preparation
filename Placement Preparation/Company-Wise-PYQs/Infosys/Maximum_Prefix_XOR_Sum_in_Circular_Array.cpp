#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>a(n);;
    for(int i=0;i<n;i++) cin>>a[i];
    long long ans=0;
    for(int start=0;start<n;start++){
        long long sum=0;
        int xr=0;
        // clock-wise   
        for(int k=0;k<n;k++){
            int idx=(start+k)%n;
            xr^=a[idx];
            sum+=xr;
        }
        ans=max(ans,sum);

        //anti clock-wise
        sum=0;
        xr=0;
        for(int k=0;k<n;k++){
            int idx=(start-k+n)%n;
            xr^=a[idx];
            sum+=xr;
        }
        ans=max(ans,sum);
    }
    cout<<ans;  
}