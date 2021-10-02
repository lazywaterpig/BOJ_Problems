#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k;
    ll dp[51][26];
    cin >> n >> k; k++;

    memset(dp, 0, sizeof(dp));
    dp[n][0]=1;
    for(int i=n-1; i>-1; i--){
        for(int j=0; j<=n/2; j++){
            if(j-1>=0) dp[i][j]+=dp[i+1][j-1];
            if(j+1<=n/2) dp[i][j]+=dp[i+1][j+1];
        }
    }

    if(dp[0][0]<k) cout << "-1";
    else{
        int level=0;
        string ans="";
        for(int i=0; i<n; i++){
            if(level==n-i){
                while(level--) ans+=')';
                break;
            }
            else{
                if(k<=dp[i+1][level+1]){
                    ans+='(';
                    level++;
                }
                else{
                    ans+=')';
                    k-=dp[i+1][level+1];
                    level--;
                }
            }
        }
        cout << ans;
    }
    return 0;
}