#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[21], dist[21]={0}, dp[21][2], pos1[21][2], pos2[21][2];
    int a, n, pos[2], tmp, i, j;

    cin >> a;
    cin >> pos[0] >> pos[1] >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
        if(i>0) dist[i]=dist[i-1]+abs(arr[i]-arr[i-1]);
    }

    dp[0][0]=abs(arr[0]-pos[0]);
    pos1[0][0]=arr[0];
    pos1[0][1]=pos[1];

    dp[0][1]=abs(arr[0]-pos[1]);
    pos2[0][0]=pos[0];
    pos2[0][1]=arr[0];

    for(i=1; i<n; i++){
        dp[i][0]=dist[i]+dp[0][0];
        pos1[i][0]=arr[i];
        pos1[i][1]=pos[1];
        for(j=0; j<i; j++){
            tmp=dp[j][1]+abs(arr[j+1]-pos2[j][0])+dist[i]-dist[j+1];
            if(dp[i][0]>tmp){
                dp[i][0]=tmp;
                pos1[i][1]=arr[j];
            }
        }

        dp[i][1]=dist[i]+dp[0][1];
        pos2[i][0]=pos[0];
        pos2[i][1]=arr[i];
        for(j=0; j<i; j++){
            tmp=dp[j][0]+abs(arr[j+1]-pos1[j][1])+dist[i]-dist[j+1];
            if(dp[i][1]>tmp){
                dp[i][1]=tmp;
                pos2[i][0]=arr[j];
            }
        }
        
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}