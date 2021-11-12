#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

struct s{
    ll x, y, z;
};

const ll sz=1<<19;
ll seg[2*sz];
s arr[sz];

bool cmp(s a, s b){
    return a.x<b.x;
}

void update(ll idx, ll val){
    idx+=sz;
    seg[idx]=min(seg[idx], val);
    idx>>=1;
    while(idx){
        seg[idx]=min(seg[idx*2], seg[idx*2+1]);
        idx>>=1;
    }
}

ll minv(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return 1e9;
    if(start<=l && r<=end) return seg[n];
    ll mid=(l+r)>>1;
    return min(minv(n*2, l, mid, start, end), minv(n*2+1, mid+1, r, start, end));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll tmp;
    for(ll i=0; i<n; i++){
        cin >> tmp; arr[tmp].x=i;
    }
    for(ll i=0; i<n; i++){
        cin >> tmp; arr[tmp].y=i;
    }
    for(ll i=0; i<n; i++){
        cin >> tmp; arr[tmp].z=i;
    }
    sort(arr+1, arr+n+1, cmp);
    for(ll i=0; i<2*sz; i++) seg[i]=1e9;

    ll ans=0;
    for(int i=1; i<=n; i++){
        if(minv(1, 0, sz-1, 0, arr[i].y)>arr[i].z) ans++;
        update(arr[i].y, arr[i].z);
    }

    cout << ans;
    return 0;
}