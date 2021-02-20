#include <bits/stdc++.h>
using namespace std;

int N;
bool vis[100001];
vector <pair<int,int>> node[100001];

int res=0;
int ep=0;
void dfs(int point, int length){
    if(vis[point]) return;

    vis[point]=true;
    if(res<length){
        res=length;
        ep=point;
    }

    for(int i=0; i<node[point].size(); i++){
        dfs(node[point][i].first, length+node[point][i].second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int parent, child, length;
    for(int i=0; i<N-1; i++){
        cin >> parent;
        while(1){
            cin >> child;
            if(child==-1) break;

            cin >> length;
            node[parent].push_back(make_pair(child, length));
            node[child].push_back(make_pair(parent, length));
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(1, 0);

    res=0;
    memset(vis, false, sizeof(vis));
    dfs(ep, 0);

    cout << res << endl;
    return 0;
}