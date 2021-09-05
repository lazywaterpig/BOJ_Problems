#include <bits/stdc++.h>
using namespace std;

int t, n, m, w, s, e, c;
vector<pair<int, int>> edge[502];

bool Bellman_Ford(int start){
    vector<int> dist(n+1, 1234567890);
    bool update;
    dist[start]=0;
    for (int i=1; i<=n; i++){
        update=0;
        for(int node=1; node<=n; node++){
            for(auto next : edge[node]){
                if(dist[next.first]>dist[node]+next.second){
                    if(next.first==start) return 1;
                    dist[next.first]=dist[node]+next.second;
                    update = 1;
                }
            }
        }
        if (!update) return 0;
    }
    return update;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m >> w;
        for(int i=1; i<=n; i++) edge[i].clear();
        while(m--){
            cin >> s >> e >> c;
            edge[s].push_back({e, c});
            edge[e].push_back({s, c});
        }
        while(w--){
            cin >> s >> e >> c;
            edge[s].push_back({e, -c});
        }
        if(Bellman_Ford(1)) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
#include <bits/stdc++.h>
#define MAX 502
#define INF 1234567890
using namespace std;

int n, m, w;
int dist[MAX];
string ans;
vector<pair<pair<int,int>, int>> edge;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        for(int i=1; i<MAX; i++) dist[i]=INF;
        memset(dist, -1, sizeof(dist));
        edge.clear();

        cin >> n >> m >> w;
        for(int i=0; i<m; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            edge.push_back({{from, to}, cost});
            edge.push_back({{to, from}, cost});
        }
        for(int i=0; i<w; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            edge.push_back({{from, to}, -cost});
        }

        dist[1]=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<edge.size(); j++){
                int from=edge[j].first.first;
                int to=edge[j].first.second;
                int cost=edge[j].second;

                if(dist[from]==INF) continue;
                if(dist[to]>dist[from]+cost) dist[to]=dist[from]+cost;
            }
        }

        int flag=0;
        for(int i=0; i<edge.size(); i++){
            int from=edge[i].first.first;
            int to=edge[i].first.second;
            int cost=edge[i].second;

            if(dist[from]==INF) continue;
            if(dist[to]>dist[from]+cost){
                ans="YES";
                flag=1;
            }
        }
        if(flag==0) ans="NO";

        cout << ans << "\n";
    }

    return 0;
}

*/