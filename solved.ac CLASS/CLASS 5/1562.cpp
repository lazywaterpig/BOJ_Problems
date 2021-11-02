#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD=1e9;
ll dp[101][10][1024];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    ll ans=0;

    for(int i=1; i<10; i++) dp[0][i][1<<i]=1;

    for(int idx=0; idx<n-1; idx++){
        for(int i=0; i<10; i++){
            for(int bit=1; bit<(1<<10); bit++){
                if(i<9){
                    dp[idx+1][i+1][bit|(1<<(i+1))]+=dp[idx][i][bit];
                    dp[idx+1][i+1][bit|(1<<(i+1))]%=MOD;
                }
                if(i>0){
                    dp[idx+1][i-1][bit|(1<<(i-1))]+=dp[idx][i][bit];
                    dp[idx+1][i-1][bit|(1<<(i-1))]%=MOD;
                }
            }
        }
    }

    for(int i=0; i<10; i++) ans+=dp[n-1][i][1023];
    cout << ans%MOD;
    return 0;
}