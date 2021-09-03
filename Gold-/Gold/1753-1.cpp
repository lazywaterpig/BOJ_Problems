#include <bits/stdc++.h>
using namespace std;

#define MAX 20001
#define INF 2147483647
#define pii pair<int,int>

int v, e, k;
vector <pii> arr[MAX];

vector<int> dij(int s, int sz){
    vector<int> dist(sz, INF);
    dist[s]=0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<cost) continue;
        for(int i=0; i<arr[cur].size(); i++){
            int next=arr[cur][i].first;
            int ncost=arr[cur][i].second+cost;
            if(dist[next]>ncost){
                dist[next]=ncost;
                pq.push({ncost,next});
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
    int n1, n2, c;
    for(int i=0; i<e; i++){
        cin >> n1 >> n2 >> c;
        arr[n1].push_back({n2,c});
    }

    vector <int> ans=dij(k, v);

    for(int i=1; i<v; i++){
        if(ans[i]==INF) cout << "INF\n";
        else cout << ans[i] << "\n";
    }

    return 0;
}