#include <bits/stdc++.h>
using namespace std;

int n, k, arr[102][2], dp[102][100003];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> arr[i][0] >> arr[i][1];

    for(int i=1; i<=n; i++){
        int weight=arr[i][0], value=arr[i][1];
        for(int j=0; j<=k; j++){
            if(j<arr[i][0]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight]+value);
        }
    }

    cout << dp[n][k];
    return 0;
}