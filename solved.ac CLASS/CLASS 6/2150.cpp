#include <bits/stdc++.h>
using namespace std;

vector <int> v[10001], e[10001];
vector <int> res[10001];
bool visited[10001];

stack <int> s;

void dfs(int node){
    visited[node]=1;
    for(auto a:v[node]){
        if(!visited[a]) dfs(a);
    }
    s.push(node);
}

void redfs(int node, int idx){
    visited[node]=1;
    res[idx].push_back(node);
    for(auto a:e[node]){
        if(!visited[a]) redfs(a, idx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    memset(visited, false, sizeof(visited));
    int cnt=0;
    while(!s.empty()){
        int tmp=s.top();
        s.pop();
        if(!visited[tmp]){
            redfs(tmp, cnt);
            cnt++;
        }
    }
    cout << cnt << '\n';
    vector <pair<int,int>> ans;
    for(int i=0; i<cnt; i++){
        sort(res[i].begin(), res[i].end());
        ans.push_back({res[i][0], i});
    }
    sort(ans.begin(), ans.end());
    for(auto a:ans){
        for(auto b:res[a.second]) cout << b << ' ';
        cout << -1 << '\n';
    }
    return 0;
}