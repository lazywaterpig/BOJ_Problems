#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll sz=1<<18;
const ll mod=1e9+7;
ll seg[2*sz], dist[2*sz];

void update(ll idx, ll val){
    idx+=sz;
    seg[idx]+=val;
    idx/=2;
    while(idx){
        seg[idx]=seg[idx*2]+seg[idx*2+1];
        idx/=2;
    }
}

void update_dist(ll idx, ll val){
    idx+=sz;
    dist[idx]+=val;
    idx/=2;
    while(idx){
        dist[idx]=dist[idx*2]+dist[idx*2+1];
        idx/=2;
    }
}

ll sum(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return 0;
    if(start<=l && r<=end) return seg[n];
    ll mid=(l+r)/2;
    return sum(n*2, l, mid, start, end) + sum(n*2+1, mid+1, r, start, end);
}

ll sum_dist(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return 0;
    if(start<=l && r<=end) return dist[n];
    ll mid=(l+r)/2;
    return sum_dist(n*2, l, mid, start, end) + sum_dist(n*2+1, mid+1, r, start, end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(seg, 0, sizeof(seg));
    memset(dist, 0, sizeof(dist));
    ll n; cin >> n;
    ll ans=1, tmp, val; cin >> tmp;
    update(tmp, 1);
    update_dist(tmp, tmp);
    for(ll i=0; i<n-1; i++){
        cin >> tmp;
        val=0;
        val+=tmp*sum(1, 0, sz-1, 0, tmp-1);
        val-=tmp*sum(1, 0, sz-1, tmp+1, 200000);
        val+=sum_dist(1, 0, sz-1, tmp+1, 200000);
        val-=sum_dist(1, 0, sz-1, 0, tmp-1);
        update(tmp, 1);
        update_dist(tmp, tmp);
        val%=mod;
        ans*=val;
        ans%=mod;
    }
    
    cout << ans % mod;
    return 0;
}