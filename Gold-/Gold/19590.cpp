#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, sum=0; cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    if(n==1) cout << arr[0];
    else if(n==2) cout << abs(arr[0]-arr[1]);
    else{
        sort(arr.begin(), arr.end());
        if(arr[n-1]*2>sum) cout << arr[n-1]*2-sum;
        else cout << sum%2;
    }
    return 0;
}