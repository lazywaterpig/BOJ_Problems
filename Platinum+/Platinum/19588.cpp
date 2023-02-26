#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m; cin >> n >> m;
    vector<pii> arr(n);
    for(ll i=0; i<n; i++){
    	cin >> arr[i].first >> arr[i].second;
    	arr[i].first*=-1;
    }

    sort(arr.begin(), arr.end());
    
    vector<ll> x(n);
    ll val=0;
    for(ll i=0; i<m; i++) val^=arr[i].second;
    x[0]=val;
    for(ll i=0; i<n-m; i++){
        val^=arr[i].second;
        val^=arr[i+m].second;
        x[i+1]=val;
    }

    for(ll i=m; i<n-m+1; i++) x[i]+=x[i-m];

    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;

        cout << x[b+(a-1)*m]-(b-m>=0?x[b-m]:0) << '\n';
    }
    
    return 0;
}