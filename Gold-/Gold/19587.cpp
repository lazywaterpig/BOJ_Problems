#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll dp[70][4]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n; n--;

    dp[0][0]=1; dp[0][1]=2;
    dp[0][2]=1; dp[0][3]=1;

    for(int i=1; i<64; i++){
        dp[i][0]=dp[i-1][0]*dp[i-1][0]+dp[i-1][1]*dp[i-1][2]; dp[i][0]%=MOD;
        dp[i][1]=dp[i-1][0]*dp[i-1][1]+dp[i-1][1]*dp[i-1][3]; dp[i][1]%=MOD;
        dp[i][2]=dp[i-1][2]*dp[i-1][0]+dp[i-1][3]*dp[i-1][2]; dp[i][2]%=MOD;
        dp[i][3]=dp[i-1][2]*dp[i-1][1]+dp[i-1][3]*dp[i-1][3]; dp[i][3]%=MOD;
    }

    ll cur[4]={1,0,0,1}, pst[4], piv=0;
    bool vis=0;
    while(n){
        if(n%2){
            if(!vis){
            	vis=1;
                for(int i=0; i<4; i++) cur[i]=dp[piv][i];
            }
            else{
                for(int i=0; i<4; i++) pst[i]=cur[i];
                cur[0]=pst[0]*dp[piv][0]+pst[1]*dp[piv][2]; cur[0]%=MOD;
                cur[1]=pst[0]*dp[piv][1]+pst[1]*dp[piv][3]; cur[1]%=MOD;
                cur[2]=pst[2]*dp[piv][0]+pst[3]*dp[piv][2]; cur[2]%=MOD;
                cur[3]=pst[2]*dp[piv][1]+pst[3]*dp[piv][3]; cur[3]%=MOD;
            }
        }
        piv++;
        n/=2;
    }

    cout << (cur[0]*2+cur[1]+cur[2]*2+cur[3])%MOD;
    return 0;
}