#include <bits/stdc++.h>
#define x first
#define y second
#define MAX 502
#define INF 1e9+7
#define endl "\n"
using namespace std;

typedef pair<int,int> pii;

int n, m;
int s, e;
int from, to, cost;
vector<pii> g[MAX];
int dist[MAX] = {0};
vector<int> par[MAX];

void dijkstra(){ // 평범한 다익스트라이지만,
    priority_queue<pii, vector<pii>, greater<pii>> pq; //stl 최소 힙
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        int now = pq.top().y;
        int cost = pq.top().x;
        pq.pop();

        if(cost > dist[now]) continue;

        for(auto i : g[now]){
            int nxt = i.x;
            int nxtcost = cost + i.y;
            if(nxtcost < dist[nxt]){ //만약 이전보다 짧은 경로 발견 시
                dist[nxt] = nxtcost;
                pq.push({nxtcost, nxt});
                par[nxt].clear(); //부모 저장용 벡터 par를 비우고
                par[nxt].push_back(now); //새 부모를 저장
            }
            else if(nxtcost == dist[nxt]){ //이전과 같은 거리의 경로 발견 시
                par[nxt].push_back(now); //부모를 par에 추가
            }
            else continue;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(1){
        cin >> n >> m;
        if(n == 0) break;

        cin >> s >> e;

        for(int i = 0; i < n; i++) g[i] = vector<pii>(); //g = 인접 리스트

        for(int i = 0; i < m; i++){
            cin >> from >> to >> cost;
            g[from].push_back({to, cost});
        }

        for(int i = 0; i < n; i++) dist[i] = INF; //각 노드 최단거리 초기화
        for(int i = 0; i < n; i++) par[i] = vector<int>(); //각 노드의 부모 초기화

        dijkstra();

        /*for(int i = 0; i < n; i++){
            cout << i << ": ";
            for(auto j : g[i]) cout << j.first << ' ';
            cout << endl;
        }*/
		
        queue<int> q; //삭제해야 할 경로에 포함된 노드를 큐에 등록
        q.push(e);
        bool vis_del[MAX] = {0}; //최단거리에 포함된 간선 삭제를 위해 방문한 노드 기록
        vis_del[e] = 1;
        while(!q.empty()){ //최단거리에 포함된 간선 삭제
            int i = q.front();
            q.pop();
            for(int j = 0; j < par[i].size(); j++){ //부모 노드의 수만큼
                for(int k = 0; k < g[par[i][j]].size(); k++){ //각 부모 노드의 인접 리스트에서 현재 노드를 찾음
                    if(g[par[i][j]][k].first == i){ //현재 노드를 찾았다면 해당 간선 삭제 후 break
                        g[par[i][j]].erase(g[par[i][j]].begin() + k); //*erase 용법 암기하기
                        if(!vis_del[par[i][j]]) q.push(par[i][j]);
                        break;
                    }
                }
            }
        }

        /*for(int i = 0; i < n; i++){
            cout << i << ": ";
            for(auto j : g[i]) cout << j.first << ' ';
            cout << endl;
        } 제대로 간선들이 삭제되었는지 여부 판단용 코드 */
		
        for(int i = 0; i < n; i++) dist[i] = INF; //각 노드 최단거리 초기화
        for(int i = 0; i < n; i++) par[i] = vector<int>(); //각 노드의 부모 초기화

        dijkstra(); //최단 경로 간선 삭제 후 다시 한 번 최단거리 구하기
        
        if(dist[e] == INF) cout << "-1" << endl;
        else cout << dist[e] << endl;
    }

    return 0;
}