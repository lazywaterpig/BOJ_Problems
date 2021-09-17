#include <bits/stdc++.h>
#define MAX 100002
#define endl "\n"
using namespace std;

vector<int> tree[MAX];
int parent[MAX];
int query[MAX];
int dp[MAX];

void find_parent(int start){
    queue<int> q;
    q.push(start);
    parent[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i : tree[node]){
            if(parent[i]==-1){
                q.push(i);
                parent[i]=node;
            }
        }
    }
}

int make_dp(int node){
    if(parent[node]!=0 && tree[node].size()==1){
        dp[node]=1;
        return 1;
    }

    int cnt=0;
    for(auto i : tree[node]){
        if(i!=parent[node]){
            cnt+=make_dp(i);
        }
    }

    dp[node]=cnt+1;
    return cnt+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    for(int i=0; i<n-1; i++){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    for(int i=0; i<q; i++) cin >> query[i];

    memset(parent, -1, sizeof(parent));
    memset(dp, -1, sizeof(dp));
    
    find_parent(r);
    make_dp(r);

    for(int i=0; i<q; i++) cout << dp[query[i]] << endl;
    return 0;
}