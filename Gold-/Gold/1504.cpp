#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define MAX 802
#define INF 2e9
using namespace std;

typedef long long ll;

ll n, e;
vector <pii> g[MAX];
ll cost[MAX];
priority_queue <pii, vector<pii>, greater<pii>> pq;

ll d(ll start, ll end){
    for(ll i=1; i<=n; i++) cost[i]=INF;

    cost[start]=0;
    pq.push({0, start});
    while(!pq.empty()){
        ll cur=pq.top().second;
        ll cur_cost=pq.top().first;
        pq.pop();

        if(cur_cost > cost[cur]) continue;
        for(ll i=0; i<g[cur].size(); i++){
            ll next=g[cur][i].first;
            ll next_cost=g[cur][i].second+cur_cost;
            if(next_cost<cost[next]){
                cost[next]=next_cost;
                pq.push({next_cost, next});
            }
        }
    }

    return cost[end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> e;
    while(e--){
        ll from, to, c;
        cin >> from >> to >> c;
        g[from].push_back({to, c});
        g[to].push_back({from, c});
    }
    ll v1, v2;
    cin >> v1 >> v2;
    ll sv1=d(1, v1), v1v2=d(v1, v2), v2e=d(v2, n);
    ll sv2=d(1, v2), v2v1=d(v2, v1), v1e=d(v1, n);
    ll sum1=sv1+v1v2+v2e;
    ll sum2=sv2+v2v1+v1e;

    if(sum1>=INF && sum2>=INF) cout << "-1";
    else cout << (sum1<sum2? sum1 : sum2);
    return 0;
}