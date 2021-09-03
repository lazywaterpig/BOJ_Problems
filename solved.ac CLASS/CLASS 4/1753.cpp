#include <bits/stdc++.h>
using namespace std;

#define MAX 20001
#define INF 2147483647

int v, e, k;
vector <pair<int,int>> edge[MAX];

vector<int> dijkstra(int s, int v){
    vector<int> dist(v, INF);
    dist[s]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});

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
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e >> k;
    v++;
    int buf[3];
    for(int i=0; i<e; i++){
        cin >> buf[0] >> buf[1] >> buf[2];
        edge[buf[0]].push_back({buf[1], buf[2]});
    }

    vector<int> res=dijkstra(k, v);

    for(int i=1; i<v; i++){
        if(res[i]==INF) cout << "INF\n";
        else cout << res[i] << "\n";
    }

    return 0;
}