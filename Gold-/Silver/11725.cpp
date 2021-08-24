#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int n;
bool vis[MAX];
int parent[MAX];
vector<int> tree[MAX];

void dfs(int node){
    vis[node]=true;
    for(int i=0; i<tree[node].size(); i++){
        int next=tree[node][i];
        if(!vis[next]){
            parent[next]=node;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    dfs(1);

    for(int i=2; i<=n; i++) cout << parent[i] << "\n";
    return 0;
}