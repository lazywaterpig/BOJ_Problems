#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[20001];
int dist[20001];
queue <int> q;
vector <int> barn[20001];

void bfs(int start){
    vis[start]=true;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0; i<barn[node].size(); i++){
            if(!vis[barn[node][i]]){
                vis[barn[node][i]]=true;
                q.push(barn[node][i]);
                dist[barn[node][i]]=dist[node]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int buf1, buf2;
    for(int i=0; i<m; i++){
        cin >> buf1 >> buf2;
        barn[buf1].push_back(buf2);
        barn[buf2].push_back(buf1);
    }

    dist[1]=0;
    bfs(1);

    int maxp, maxd=-1, cnt=1;
    for(int i=1; i<=n; i++){
        if(maxd<dist[i]){
            maxp=i;
            maxd=dist[i];
            cnt=1;
        }
        else if(maxd==dist[i]) cnt++;
        else continue;
    }

    cout << maxp << ' ' << maxd << ' ' << cnt;
    return 0;
}