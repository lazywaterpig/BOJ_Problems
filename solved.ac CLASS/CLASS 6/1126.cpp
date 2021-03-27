#include <bits/stdc++.h>
using namespace std;

bool dp[500001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(dp, 0, sizeof(dp));

    int i, n;
    cin >> n;

    int piv=0, tmp, block[51];
    for(i=0; i<n; i++) cin >> block[i];

    for(i=0; i<n; i++){
        for(int j=500000; j>=0; j--){
            if(j+block[i]<500001 && dp[j]==true) dp[j+block[i]]=true;
        }
        dp[block[i]]=true;
    }

    i=500000;
    while(i>0){
        if(dp[i]==true && dp[i/2]==true){
            cout << i/2 << endl;
            break;
        }
        if(i<2) cout << "-1" << endl;
        i-=2;
    }

    return 0;
}