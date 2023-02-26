#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    int dp[10101]={0};
    
    for(int i=0; i<n; i++){
        int cur; cin >> cur;
        if(cur>k) continue;
        dp[cur]++;
        for(int j=cur+1; j<=k; j++) dp[j]+=dp[j-cur];
    }

    cout << dp[k];
    return 0;
}