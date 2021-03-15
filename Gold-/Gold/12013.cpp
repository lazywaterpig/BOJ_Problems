#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[250], dp[250][250];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++){
        cin >> arr[i];
        dp[i][i]=arr[i];
    }

    for(int length=1; length<n; length++){
        for(int i=0; i<n; i++){
            int j=i+length;
            if(j>=n) break;
            for(int k=i; k<j; k++){
                if(dp[i][k] && dp[k+1][j] && dp[i][k]==dp[k+1][j] && dp[i][j]<=dp[i][k]){
                    dp[i][j]=dp[i][k]+1;
                }
            }
        }
    }
    
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(res<dp[i][j]) res=dp[i][j];
        }
    }

    cout << res << endl;
    return 0;
}