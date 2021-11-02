#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

vector<int> v[32001];
int cnt[32001]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        cnt[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!cnt[i]) q.push(i);
    }
    
    int cur;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        cout << cur << ' ';
        for(int i=0; i<v[cur].size(); i++){
            cnt[v[cur][i]]--;
            if(!cnt[v[cur][i]]) q.push(v[cur][i]);
        }
    }

    return 0;
}