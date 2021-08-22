#include <bits/stdc++.h>
using namespace std;

int arr[100001], cnt[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n, m, ans=0;
    cin >> n >> m;

    cin >> arr[0];
    arr[0]%=m;
    for(i=1; i<n; i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
        arr[i]%=m;
    }
    for(i=0; i<n; i++) cnt[arr[i]]++;
    ans+=cnt[0];
    for(i=1; i<n; i++) ans+=cnt[arr[i]];

    cout << ans;
    return 0;
}