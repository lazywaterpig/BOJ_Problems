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
        for(int j=0; j<n-i; j++){
            minv=2147483647;
            for(int k=0; k<i; k++){
                tmp=arr[j][0]*arr[j+k][1]*arr[j+i][1]+dp[k][j]+dp[i-k-1][j+k+1];
                if(tmp<minv) minv=tmp; 
            }
            dp[i][j]=minv;
        }
    }
    cout << dp[n-1][0] << endl;

    return 0;
}