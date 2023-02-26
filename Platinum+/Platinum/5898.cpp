#include <bits/stdc++.h>
using namespace std;

int dp[100100][21];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<int> v[n+1  ];
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++) cin >> dp[i][0];

    for(int i=1; i<=n; i++){
        dp[i][1]=dp[i][0];
        for(int l=0; l<v[i].size(); l++){
            dp[i][1]+=dp[v[i][l]][0];
        }
    }

    for(int j=2; j<=k; j++){
        for(int i=1; i<=n; i++){
        	dp[i][j]=(1-v[i].size())*dp[i][j-2];
            for(auto l:v[i]) dp[i][j]+=dp[l][j-1];
        }
    }
    
    for(int i=1; i<=n; i++) cout << dp[i][k] << '\n';
    return 0;
}