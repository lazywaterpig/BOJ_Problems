#include <bits/stdc++.h>
#define MAX 20001
#define INF 1e9
#define endl "\n"
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
using namespace std;

int n, m;
vector<pii> edge[MAX];
int dist_fox[MAX];
int dist_wolf[MAX][2];

void d_fox(int start){
	for(int i=0; i<=n; i++) dist_fox[i]=INF;
    dist_fox[start]=0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist_fox[cur]<cost) continue;
        for(int i=0; i<edge[cur].size(); i++){
            int next=edge[cur][i].first;
            int nextcost=cost+edge[cur][i].second;
            if(dist_fox[next]>nextcost){
                dist_fox[next]=nextcost;
                pq.push({nextcost,next});
            }
        }
    }
}

void d_wolf(int start){
	for(int i=0; i<=n; i++){ dist_wolf[i][0]=INF; dist_wolf[i][1]=INF; }
    dist_wolf[start][0]=0;
    priority_queue <piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {start,0}});

    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second.first;
        int runtype=pq.top().second.second;
        pq.pop();

        if(dist_wolf[cur][runtype]<cost) continue;
        for(int i=0; i<edge[cur].size(); i++){
            int next=edge[cur][i].first;
            int nextcost=cost;
            int nextruntype=runtype^1;
            if(runtype==0) nextcost+=edge[cur][i].second/2;
            else nextcost+=edge[cur][i].second*2;

            if(dist_wolf[next][nextruntype]>nextcost){
                dist_wolf[next][nextruntype]=nextcost;
                pq.push({nextcost,{next,nextruntype}});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int buf[3];
    while(m--){
        cin >> buf[0] >> buf[1] >> buf[2];
        edge[buf[0]].push_back({buf[1],buf[2]*2});
        edge[buf[1]].push_back({buf[0],buf[2]*2});
    }
    
    d_fox(1);
    d_wolf(1);

    int cnt=0;
    for(int i=2; i<=n; i++){
        if(dist_fox[i]<min(dist_wolf[i][0], dist_wolf[i][1])) cnt++;
    }

    cout << cnt;
    return 0;
}