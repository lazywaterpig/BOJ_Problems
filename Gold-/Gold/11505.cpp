#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
int n, m, k;
ll tree[4000001];
const ll mod=1e9+7;

void update(int node, int s, int e, int idx, int val) {
    if(s==e){
        tree[node]=val;
        return;
    }
    int mid=(s+e)/2;
    if(idx<=mid) update(2*node, s, mid, idx, val);
    else update(2*node+1, mid+1, e, idx, val);
    tree[node]=tree[2*node]*tree[2*node+1]%mod;
}

ll query(int node, int s, int e, int l, int r) {
    if(l>e || r<s) return 1;
    if(l<=s && e<=r) return tree[node];
    int mid=(s+e)/2;
    ll q1=query(2*node, s, mid, l, r);
    ll q2=query(2*node+1, mid+1, e, l, r);
    return q1*q2%mod;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        int num; cin >> num;
        update(1, 1, n, i, num);
    }
    int r=m+k;
    while(r--){
        int a, b, c; cin >> a >> b >> c;
        if(a==1) update(1, 1, n, b, c);
        if(a==2){
            if(b>=c) swap(b, c);
            cout << query(1, 1, n, b, c) << endl;
        }
    }
}