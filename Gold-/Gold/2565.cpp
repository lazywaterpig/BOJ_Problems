#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pii> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());

    int dp[101]; dp[0]=1;
    for(int i=1; i<n; i++){
        int v=1;
        for(int j=0; j<i; j++){
            if(dp[j]>=v && arr[j].second<arr[i].second) v=dp[j]+1;
        }
        dp[i]=v;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(ans<dp[i]) ans=dp[i];
    }
    cout << n-ans;
    return 0;
}