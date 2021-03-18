#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n, arr[10001][2], ans=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i][0] >> arr[i][1];
    arr[n][0]=arr[0][0];
    arr[n][1]=arr[0][1];

    for(int i=0; i<n; i++){
        ans+=arr[i][0]*arr[i+1][1]-arr[i][1]*arr[i+1][0];
    }
    cout << abs(ans/2) << ((ans%2==1)?".5":".0") << endl;
    return 0;
}