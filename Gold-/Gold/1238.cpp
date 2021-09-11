#include <bits/stdc++.h>
#define MAX 20001
#define INF 1e9
#define endl "\n"
#define pii pair<int,int>
using namespace std;

int n, m, k;
vector<pii> edge[MAX];
vector<pii> reve[MAX];
int dist[MAX];
int revd[MAX];

void dijkstra(int start){
	for(int i=0; i<=n; i++) dist[i]=INF;
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
            }
        }
    }
}

void rev_dijkstra(int start){
	for(int i=0; i<=n; i++) revd[i]=INF;
    revd[start]=0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(revd[cur]<cost) continue;
        for(int i=0; i<reve[cur].size(); i++){
            int next=reve[cur][i].first;
            int nextcost=cost+reve[cur][i].second;
            if(revd[next]>nextcost){
                revd[next]=nextcost;
                pq.push({nextcost,next});
            }
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
        reve[buf[1]].push_back({buf[0],buf[2]});
    }
    
    rev_dijkstra(k);
    dijkstra(k);

    int maxv=-1;
    for(int i=1; i<=n; i++){
        if(maxv<dist[i]+revd[i]) maxv=dist[i]+revd[i];
    }

    cout << maxv;
    return 0;
}