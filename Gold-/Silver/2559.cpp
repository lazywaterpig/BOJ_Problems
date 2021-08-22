#include <bits/stdc++.h>
using namespace std;

int arr[105000], dp[105000]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n, k, ans=-123456789;
    cin >> n >> k;
    for(i=1; i<=n; i++) cin >> arr[i];
    for(i=1; i<=n; i++) dp[i]=dp[i-1]+arr[i];

    for(i=1; i<=n-k+1; i++){
        if(ans<dp[i+k-1]-dp[i-1]) ans=dp[i+k-1]-dp[i-1];
    }

    cout << ans;
    return 0;
}