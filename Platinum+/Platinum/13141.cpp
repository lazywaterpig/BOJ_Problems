#include <bits/stdc++.h>
#define MAX 201
#define INF 1e9
#define endl "\n";
#define pii pair<int,int>
using namespace std;

int n, m;
vector <pii> edge[MAX];
int dist[MAX];

void dijkstra(int start){
    for(int i=1; i<=n; i++) dist[i]=INF;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int buf[3];
    for(int i=0; i<m; i++){
        cin >> buf[0] >> buf[1] >> buf[2];
        buf[2]*=2;
        edge[buf[0]].push_back({buf[1], buf[2]});
        edge[buf[1]].push_back({buf[0], buf[2]});
    }

    int maxv=1e9;
    for(int i=1; i<=n; i++){
        dijkstra(i);
        int tmp=-1;
        for(int j=1; j<=n; j++){
            for(auto k : edge[j]){
                int val=min(dist[j]+k.second, min(dist[k.first]+k.second, (dist[j]+dist[k.first]+k.second)/2));
                if(tmp<val) tmp=val;
            }
        }
        if(maxv>tmp) maxv=tmp;
    }

    cout << maxv/2 << (maxv%2==1?".5":".0");
    return 0;
}