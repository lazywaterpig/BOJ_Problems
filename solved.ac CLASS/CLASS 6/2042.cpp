#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int l, r, idx;
ll diff;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start==end) return tree[node]=arr[start];

    int mid=(start+end)/2;
    return tree[node]=init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

void update(vector<ll> &tree, int node, int start, int end){
    if(start>idx || idx>end) return;

    tree[node]+=diff;

    if(start!=end){
        int mid=(start+end)/2;
        update(tree, node*2, start, mid);
        update(tree, node*2+1, mid+1, end);
    }
}

ll sum(vector<ll> &tree, int node, int start, int end){
    if(l>end || r<start) return 0;

    if(l<=start && end<=r) return tree[node];

    int mid=(start+end)/2;
    return sum(tree, node*2, start, mid)+sum(tree, node*2+1, mid+1, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int h=(int)ceil(log2(n));
    int tree_size=(1 << (h+1));

    vector<ll> arr(n);
    vector<ll> tree(tree_size);


    for(int i=0; i<n; i++) cin >> arr[i];

    init(arr, tree, 1, 0, n-1);

    m+=k;
    while(m--){
        int get;
        cin >> get;

        if(get==1){
            ll val;
            cin >> idx >> val;
            idx--;
            diff=val-arr[idx];
            arr[idx]=val;
            update(tree, 1, 0, n-1);
        }
        else{
            cin >> l >> r;
            l--;
            r--;
            cout << sum(tree, 1, 0, n-1) << '\n';
        }
    }

    return 0;
}