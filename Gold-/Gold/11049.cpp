#include <bits/stdc++.h>
using namespace std;

int dp[502][502];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[502][2];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
        dp[i][0]=0;
    }

    int minv, tmp;
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            minv=2147483647;
            for(int k=0; k<i; k++){
                tmp=arr[j-i][0]*arr[j-i+k][1]*arr[j][1]+dp[k][j-i+k]+dp[i-k+1][j];
                if(tmp<minv) minv=tmp;
                cout << i << ' ' << j << ' ' << k << ' ' << arr[j-i][0]*arr[j-i+k][1]*arr[j][1] << endl; 
            }
            dp[i][j]=tmp;
            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    cout << dp[n-1][n-1] << endl;

    return 0;
}