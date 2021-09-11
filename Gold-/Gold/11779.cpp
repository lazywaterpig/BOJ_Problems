#include <bits/stdc++.h>
#define MAX 1002
#define INF 1e9
#define endl "\n";
#define pii pair<int,int>
using namespace std;

int n, m;
vector <pii> edge[MAX];
int dist[MAX];
int parent[MAX];

void dijkstra(int start){
    dist[start]=0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<cost) continue;
        for(int i=0; i<edge[cur].size(); i++){
            int next=edge[cur][i].first;
            int nextcost=cost+edge[cur][i].second;
            if(dist[next]>nextcost){
                dist[next]=nextcost;
                pq.push({nextcost,next});
                parent[next]=cur;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int from, to, cost;
    while(m--){
        cin >> from >> to >> cost;
        edge[from].push_back({to, cost});
    }
    
    cin >> from >> to;
    
    for(int i=0; i<=n; i++) dist[i]=INF;

    dijkstra(from);

    cout << dist[to] << endl;

    stack<int> s;
    int idx=to;
    while(idx!=from){ s.push(idx); idx=parent[idx]; }
    s.push(idx);
    cout << s.size() << endl;
    while(!s.empty()){ cout << s.top() << ' '; s.pop(); } cout << endl;
    return 0;
}