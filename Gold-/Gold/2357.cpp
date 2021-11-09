#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll sz=1<<17;
ll seg_min[2*sz], seg_max[2*sz];
ll minv, maxv;

void min_val(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return;
    if(start<=l && r<=end){
        minv=min(minv, seg_min[n]);
        return;
    }
    ll mid=(l+r)/2;
    min_val(n*2, l, mid, start, end);
    min_val(n*2+1, mid+1, r, start, end);
    return;
}

void max_val(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return;
    if(start<=l && r<=end){
        maxv=max(maxv, seg_max[n]);
        return;
    }
    ll mid=(l+r)/2;
    max_val(n*2, l, mid, start, end);
    max_val(n*2+1, mid+1, r, start, end);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m;
    for(ll i=0; i<n; i++){
        cin >> seg_min[sz+i+1];
        seg_max[sz+i+1]=seg_min[sz+i+1];
    }
    
    for(ll i=sz-1; i>0; i--){
        seg_min[i]=min(seg_min[i*2], seg_min[i*2+1]);
        seg_max[i]=max(seg_max[i*2], seg_max[i*2+1]);
    }
    
    for(ll i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        minv=1e9+1, maxv=0;
        min_val(1, 0, sz-1, a, b);
        max_val(1, 0, sz-1, a, b);
        cout << minv << ' ' << maxv << endl;
    }
}