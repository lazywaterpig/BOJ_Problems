#include <bits/stdc++.h>
#define MAX 1002
#define INF 1e9
#define endl "\n"
#define pii pair<int,int>
using namespace std;

int n, m, k;
vector<pii> edge[MAX];
priority_queue<int> dist[MAX];

void dijkstra(){
    dist[1].push(0);
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        for(auto i : edge[cur]){
            int next=i.first;
            int nextcost=cost+i.second;
            if(dist[next].size()<k){
                dist[next].push(nextcost);
                pq.push({nextcost,next});
            }
            else if(dist[next].top()>nextcost){
                dist[next].pop();
                dist[next].push(nextcost);
                pq.push({nextcost,next});
            }
            else continue;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    int buf[3];
    while(m--){
        cin >> buf[0] >> buf[1] >> buf[2];
        edge[buf[0]].push_back({buf[1],buf[2]});
    }
    
    dijkstra();

    int maxv=-1;
    for(int i=1; i<=n; i++){
        if(dist[i].size()!=k) cout << "-1" << endl;
        else cout << dist[i].top() << endl;
    }

    return 0;
}