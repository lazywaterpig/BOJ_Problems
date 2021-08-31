#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k, t1, t2;
        cin >> n >> k;
        dp[1][1][0]=1;
        dp[1][1][1]=1;
    	k++;
    	
    	for(int i=2; i<=n; i++){
    		t1=max(1, i+k-n);
    		t2=min(i, k);
            for(int j=t1; j<=t2; j++){
                dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j-1][1];
            }
        }
        
        cout << dp[n][k][0]+dp[n][k][1] << "\n";
    }
    
    return 0;
}