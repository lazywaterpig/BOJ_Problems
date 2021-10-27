#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int arr[1001][3];
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    int ans=1e9;
    int dp[1001][3];
    for(int color=0; color<3; color++){
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<3; i++) dp[0][i]=arr[0][i];
        dp[0][color]=1e9;
        for(int i=1; i<n; i++){
            for(int j=0; j<3; j++){
                dp[i][j]=arr[i][j]+min(dp[i][(j+1)%3], dp[i][(j+2)%3]);
            }
        }
        if(dp[n-1][color]<ans) ans=dp[n-1][color];
    }

    cout << ans;
    return 0;
}