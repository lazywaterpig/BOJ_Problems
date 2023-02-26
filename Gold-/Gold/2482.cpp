#include <bits/stdc++.h>
#define INF 1000000003
using namespace std;

int arr[1010][1010][2]={0,};

int main(){
    int n, k, ans=0; cin >> n >> k;
    arr[0][0][0]=1;
    for(int i=1; i<n; i++){
        arr[i][0][0]=arr[i-1][0][0];
        for(int j=1; j<=k; j++){
            arr[i][j][0]=arr[i-1][j][0]+arr[i-1][j][1];
            arr[i][j][1]=arr[i-1][j-1][0];
            arr[i][j][0]%=INF; arr[i][j][1]%=INF;
        }
    }

    ans+=arr[n-1][k][0]+arr[n-1][k][1];
    ans%=INF;
    memset(arr, 0, sizeof(arr));
    
    arr[0][1][1]=1;
    for(int i=1; i<n; i++){
        arr[i][0][0]=arr[i-1][0][0];
        for(int j=1; j<=k; j++){
            arr[i][j][0]=arr[i-1][j][0]+arr[i-1][j][1];
            arr[i][j][1]=arr[i-1][j-1][0];
            arr[i][j][0]%=INF; arr[i][j][1]%=INF;
        }
    }

    ans+=arr[n-1][k][0];
    ans%=INF;
    cout << ans;
    return 0;
}