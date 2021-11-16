#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const ll sz=1<<19;
ll num[sz*2][2], arr[sz];
ll seg[sz*2];

void update(ll idx){
	idx+=sz;
    seg[idx]++;
    idx>>=1;
    while(idx){
        seg[idx]=seg[idx<<1]+seg[(idx<<1)+1];
        idx>>=1;
    }
}

ll sum(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return 0;
    if(start<=l && r<=end) return seg[n];
    ll mid=(l+r)/2;
    return sum(n*2, l, mid, start, end)+sum(n*2+1, mid+1, r, start, end);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            ll tmp; cin >> tmp;
            num[tmp][i]=j;
            if(!i) arr[j]=tmp;
        }
    }

    for(int i=0; i<n; i++) arr[i]=num[arr[i]][1];
    memset(seg, 0, sizeof(seg));

    ll ans=0;
    for(int i=0; i<n; i++){
        ans+=i-sum(1, 0, sz-1, 0, arr[i]);
        update(arr[i]);
    }

    cout << ans;
    return 0;
}