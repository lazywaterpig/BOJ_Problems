#include <bits/stdc++.h>
#define MAX 10010
#define endl "\n"
using namespace std;

vector<int> tree[MAX];
bool vis[MAX];
int dp[2][MAX];
int num[MAX];

void dfs(int node){
    vis[node]=true;
    for(auto i : tree[node]){
        if(!vis[i]) dfs(i);
    }
    dp[0][node]=0;
    dp[1][node]=num[node];
    for(auto i : tree[node]){
        dp[0][node]+=max(dp[0][i], dp[1][i]);
        dp[1][node]+=dp[0][i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for(int i=1; i<=n; i++) cin >> num[i];

    for(int i=0; i<n-1; i++){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    
    dfs(1);

    cout << max(dp[0][1],dp[1][1]) << endl;
    return 0;
}