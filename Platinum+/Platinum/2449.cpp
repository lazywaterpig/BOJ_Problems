#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;

int arr[201], dp[201][201], i, tmp;

int solve(int left, int right){
    if(left==right) return 0;
    
    int &ret = dp[left][right];
    if(ret!=-1) return ret;
    ret=INF;

    for(i=left; i<right; i++){
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
    for(i=0; i<num; i++){
        cin >> tmp;
        if(i==0) arr[n++]=tmp;
        else if(tmp!=arr[n-1]) arr[n++]=tmp;
    }

    cout << solve(0, n-1);

    return 0;
}