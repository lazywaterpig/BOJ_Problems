#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll sz=1<<17;
ll seg[2*sz];

void update(ll idx, ll val){
    seg[idx]=val;
    idx/=2;
    while(idx){
        seg[idx]=seg[idx*2]+seg[idx*2+1];
        idx/=2;
    }
}

ll sum(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return 0;
    if(start<=l && r<=end) return seg[n];
    ll mid=(l+r)/2;
    return sum(n*2, l, mid, start, end)+sum(n*2+1, mid+1, r, start, end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(seg, 0, sizeof(seg));
    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        cin >> seg[i+sz];
        seg[i+sz]%=2;
    }
    
    for(ll i=sz-1; i>0; i--) seg[i]=seg[i*2]+seg[i*2+1];
    
    ll m; cin >> m;
    while(m--){
        ll a, b, c; cin >> a >> b >> c; b--; c--;
        if(a==1) update(b+sz, (++c)%2);
        else if(a==2) cout << (c-b+1)-sum(1, 0, sz-1, b, c) << endl;
        else if(a==3) cout << sum(1, 0, sz-1, b, c) << endl;
    }

    return 0;
}