#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll sz=1<<17;
ll seg[2*sz], arr[sz], ans[sz];

void update(ll idx, ll val){
    seg[idx]=val;
    idx/=2;
    while(idx){
        seg[idx]=seg[idx*2]+seg[idx*2+1];
        idx/=2;
    }
}

ll inversion(ll n, ll val){
    if(n>=sz) return n;
    else if(seg[n*2]<val) return inversion(n*2+1, val-seg[n*2]);
    else return inversion(n*2, val);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    for(ll i=1; i<=n; i++) cin >> arr[i];
    memset(seg, 0, sizeof(seg));
    
    for(ll i=sz; i<sz+n; i++) seg[i]=1;
    for(ll i=sz-1; i>0; i--) seg[i]=seg[i*2]+seg[i*2+1];
    
    for(ll i=1; i<=n; i++){
        ll idx=inversion(1, arr[i]+1);
        ans[idx-sz+1]=i;
        update(idx, 0);
    }

    for(int i=1; i<=n; i++) cout << ans[i] << endl;
    
    return 0;
}