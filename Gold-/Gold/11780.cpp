//Floyd-Warshall
//with paths
#include <bits/stdc++.h>
#define MAX 102
#define INF 1e9
#define endl "\n"
using namespace std;

int n, m;
int from, to, c;
int cost[MAX][MAX];
int route[MAX][MAX];
vector <int> v;

void floyd(){
    for(int mid = 1; mid <= n; mid++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(cost[i][j] > cost[i][mid] + cost[mid][j]){
                    cost[i][j] = cost[i][mid] + cost[mid][j];
                    route[i][j] = mid;
                }
            }
        }
    }
}

void routefinder(int s, int e){
    if(route[s][e] == 0){
        v.push_back(s);
        v.push_back(e);
        return;
    }
    routefinder(s, route[s][e]);
    v.pop_back();
    routefinder(route[s][e], e);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cost[i][j] = INF;
    }

    for(int i = 0; i < m; i++){
        cin >> from >> to >> c;
        cost[from][to] = min(cost[from][to], c);
    }

    floyd();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] == INF) cout << "0 ";
            else cout << cost[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] == INF) cout << 0;
            else{
                v.clear();
                routefinder(i, j);
                cout << v.size() << ' ';
                for(int k = 0; k < v.size(); k++) cout << v[k] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}