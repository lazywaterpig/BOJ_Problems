#include <bits/stdc++.h>
#define MAX 1000010
#define endl "\n";
typedef long long ll;
using namespace std;

int n, m, k;
int arr[MAX];
vector<ll> lazy;
vector<ll> tree;
vector<pair<pair<int,int>, pair<int,ll>>> ord;

ll make_segtree(int node, int start, int end){
    if(start==end) return tree[node]=arr[start];

    int mid=(start+end)/2;
    ll left_res=make_segtree(node*2, start, mid);
    ll right_res=make_segtree(node*2+1, mid+1, end);
    tree[node]=left_res+right_res;

    return tree[node];
}

void Setup(){
    int height=(int)ceil(log2(n));
    int tree_size=(1 << (height+1));
    tree.resize(tree_size);
    lazy.resize(tree_size);
    make_segtree(1, 0, n-1);
}

void lazy_update(int node, int start, int end){
    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node, int start, int end, int left, int right, ll value){
    lazy_update(node, start, end);
    if(right<start || left>end) return;
    if(left<=start && end<=right){
        tree[node]+=(end-start+1)*value;
        if(start!=end){
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return;
    }

    int mid=(start+end)/2;
    update(node*2, start, mid, left, right, value);
    update(node*2+1, mid+1, end, left, right, value);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right){
    lazy_update(node, start, end);
    if(right<start || left>end) return 0;
    if(left<=start && end<=right) return tree[node];

    int mid=(start+end)/2;
    ll left_res=query(node*2, start, mid, left, right);
    ll right_res=query(node*2+1, mid+1, end, left, right);
    return left_res+right_res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<m+k; i++){
        int a; cin >> a;
        if(a==1){
            int b, c, d; cin >> b >> c >> d;
            ord.push_back({{a,b},{c,d}});
        }
        else{
            int b, c; cin >> b >> c;
            ord.push_back({{a,b},{c,-1}});
        }
    }

    Setup();

    for(int i=0; i<m+k; i++){
        int buf=ord[i].first.first;
        if(buf==1){
            int idx=ord[i].first.second-1;
            int idx2=ord[i].second.first-1;
            ll value=ord[i].second.second;

            update(1, 0, n-1, idx, idx2, value);
        }
        else{
            int idx=ord[i].first.second-1;
            int idx2=ord[i].second.first-1;

            cout << query(1, 0, n-1, idx, idx2) << endl;
        }
    }

    return 0;
}