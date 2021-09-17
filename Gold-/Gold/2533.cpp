#include <bits/stdc++.h>
#define MAX 1000010
#define endl "\n"
using namespace std;

vector<int> tree[MAX];
vector<int> friends[MAX];
bool vis[MAX];
int dp[MAX][2];

void dfs(int node){
    vis[node]=true;
    for(auto i : tree[node]){
        if(!vis[i]){
            friends[node].push_back(i);
            dfs(i);
        }
    }
}

int tree_dp(int node, bool flag){
    int &res=dp[node][flag];

    if(res!=-1) return res;

    if(flag){
        res=1;
        for(auto i : friends[node]) res+=min(tree_dp(i,true),tree_dp(i,false));
    }
    else{
        res=0;
        for(auto i : friends[node]) res+=tree_dp(i,true);
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for(int i=0; i<n-1; i++){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    memset(dp, -1, sizeof(dp));
    
    dfs(1);

    cout << min(tree_dp(1,false),tree_dp(1,true)) << endl;
    return 0;
}