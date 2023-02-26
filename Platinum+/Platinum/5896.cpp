#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, k, m, ans=0; cin >> n >> k >> m;
    vector<pll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].se >> arr[i].fi;

    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) swap(arr[i].fi, arr[i].se);
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for(int i=0; i<n; i++){
        if(k){
            if(m<arr[i].se) break;

            pq.push(arr[i]);
            m-=arr[i].se;
            k--;
            ans++;
        }
        else{
            ll a, b;
            pll cur = pq.top();
            a = m-arr[i].fi;
            b = m - (cur.fi-cur.se) - arr[i].se;

            if(a<0 && b<0) continue;
            else ans++;

            if(a>=b) m=a;
            else{
                m=b;
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }

	cout << ans;
    return 0;
}