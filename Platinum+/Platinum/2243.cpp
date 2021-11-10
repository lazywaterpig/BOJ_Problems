#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll sz=1<<20;
ll seg[2*sz];

void update(ll idx, ll diff){
    idx+=sz;
    seg[idx]+=diff;
    idx/=2;
    while(idx){
        seg[idx]=seg[idx*2]+seg[idx*2+1];
        idx/=2;
    }
}

ll taste(ll n, ll val){
    if(n>sz) return n-sz;
    else if(seg[n*2]<val) return taste(n*2+1, val-seg[n*2]);
    else return taste(n*2, val);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    memset(seg, 0, sizeof(seg));
    
    //for(ll i=sz-1; i>0; i--) seg[i]=seg[i*2]+seg[i*2+1];
    
    for(ll i=0; i<n; i++){
        ll a, b, c; cin >> a;
        if(a==1){
            cin >> b;
            ll ans=taste(1,b);
            cout << ans << endl;
            update(ans, -1);
        }
        else if(a==2){
            cin >> b >> c;
            update(b, c);
        }
    }
}