#include <bits/stdc++.h>
using namespace std;

int arr[502][502];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans=-1;
    cin >> n;

    memset(arr, 0, sizeof(arr));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> arr[i][j];
            arr[i][j]+=max(arr[i-1][j-1], arr[i-1][j]);
        }
    }
    for(int i=1; i<=n; i++){
        if(ans<arr[n][i]) ans=arr[n][i];
    }
    cout << ans << endl;
    return 0;
}