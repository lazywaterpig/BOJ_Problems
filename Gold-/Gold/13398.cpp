#include <bits/stdc++.h>
using namespace std;

int arr[100001], dp[100001][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n, ans=-1234567890;
    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];
    dp[0][0]=arr[0];
    dp[0][1]=arr[0];
    for(i=1; i<n; i++) dp[i][0]=max(dp[i-1][0]+arr[i], arr[i]);
    for(i=1; i<n; i++) dp[i][1]=max(dp[i-1][0], dp[i-1][1]+arr[i]);

    for(i=0; i<n; i++){
        if(ans<dp[i][0]) ans=dp[i][0];
        if(ans<dp[i][1]) ans=dp[i][1];
    }
    cout << ans;
    return 0;
}