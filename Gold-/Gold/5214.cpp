#include <bits/stdc++.h>
using namespace std;

int n, k, m, tmp;
int hypertube[1001][1001];
int depth[100001];
bool vis[100001], tubevis[1001];
queue <int> nextstation;
vector <int> station[100001];

void bfs(int start){
    vis[start]=true;
    nextstation.push(start);
    while(!nextstation.empty()){
        int node=nextstation.front();
        nextstation.pop();
        for(int i=0; i<station[node].size(); i++){
            tmp=station[node][i];
            if(!tubevis[tmp]){
                tubevis[tmp]=true;
                for(int j=0; j<k; j++){
                    if(!vis[hypertube[tmp][j]]){
                        nextstation.push(hypertube[tmp][j]);
                        vis[hypertube[tmp][j]]=true;
                        depth[hypertube[tmp][j]]=depth[node]+1;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> m;

    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            cin >> hypertube[i][j];
            station[hypertube[i][j]].push_back(i);
        }
    }

    memset(depth, 0, sizeof(depth));
    memset(vis, false, sizeof(vis));
    memset(tubevis, false, sizeof(tubevis));

    bfs(1);

    if(n==1) cout << "1";
    else if(depth[n]==0) cout << "-1";
    else cout << depth[n]+1;

    return 0;
}