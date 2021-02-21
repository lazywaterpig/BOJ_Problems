#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;

int arr[201], dp[201][201];

int solve(int left, int right){
    if(left==right) return 0;
    
    int &ret = dp[left][right];
    if(ret!=-1) return ret;
    ret=INF;

    for(int i=left; i<right; i++){
    	int tmp;
        if(arr[left]==arr[i+1]) tmp=0;
        else tmp=1;

        ret=min(ret, solve(left, i)+solve(i+1, right)+tmp);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    int n=0, k, num;

    cin >> num >> k;
    for(int i=0; i<num; i++){
    	char ctmp;
        int tmp;
        cin >> ctmp;
        if(ctmp=='G') tmp=1;
        if(ctmp=='B') tmp=2;
        if(ctmp=='R') tmp=3;
        if(i==0) arr[n++]=tmp;
        else if(tmp!=arr[n-1]) arr[n++]=tmp;
    }

    cout << solve(0, n-1)+1;

    return 0;
}