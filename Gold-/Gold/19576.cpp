#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int dp[5050];
    for(int i=0; i<n; i++) dp[i]=1;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]%arr[i]==0){
            	dp[j]=max(dp[j], dp[i]+1);
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(dp[i]>ans) ans=dp[i];
    }

    cout << n-ans;
    return 0;
}