#include <bits/stdc++.h>
using namespace std;

int arr[20000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(arr, 0, sizeof(arr));

    int i, n, m, tmp;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> tmp;
        arr[tmp+10000000]++;
    }
    cin >> m;
    for(i=0; i<m; i++){
        cin >> tmp;
        cout << arr[tmp+10000000] << ' ';
    }
    return 0;
}