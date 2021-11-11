#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll sz=1<<20;
ll seg[2*sz], ans=0;
pair<ll,ll> arr[sz];

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first>b.first;
}

void update(ll idx, ll val){
    seg[idx]=val;
    idx/=2;
    while(idx){
        seg[idx]=seg[idx*2]+seg[idx*2+1];
        idx/=2;
    }
}

void inv(ll n){
    if(n==1) return;
    if(n%2==0) ans+=seg[n+1];
    return inv(n/2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(seg, 0, sizeof(seg));
    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second=i;
    }
    sort(arr, arr+n, cmp);
    
    for(ll i=sz; i<sz+n; i++) seg[i]=1;
    for(ll i=sz-1; i>0; i--) seg[i]=seg[i*2]+seg[i*2+1];
    
    for(ll i=0; i<n; i++){
        ll idx=arr[i].second;
        inv(idx+sz);
        update(idx+sz, 0);
    }

    cout << ans;
    return 0;
}