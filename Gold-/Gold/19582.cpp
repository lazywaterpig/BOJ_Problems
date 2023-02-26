#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int dp[100100][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pii> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;

    dp[0][0]=arr[0].second; dp[0][1]=0;
    for(int i=1; i<n; i++){
        if(dp[i-1][0]!=-1 && dp[i-1][0]<=arr[i].first) dp[i][0]=dp[i-1][0]+arr[i].second;
        else dp[i][0]=-1;

        dp[i][1]=dp[i-1][0];

        if(dp[i-1][1]!=-1 && dp[i-1][1]<=arr[i].first) dp[i][1]=dp[i-1][1]+arr[i].second;
        else dp[i][1]=max(dp[i][1], -1);
    }

    if(dp[n-1][0]==-1 && dp[n-1][1]==-1) cout << "Zzz";
    else cout << "Kkeo-eok";
    return 0;
}