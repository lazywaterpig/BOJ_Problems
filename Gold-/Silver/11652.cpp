#include <bits/stdc++.h>
#define INF 1e9+7
#define ll long long
using namespace std;

ll arr[100100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr[0], arr[n]);
    cout << arr[0];

    return 0;
}