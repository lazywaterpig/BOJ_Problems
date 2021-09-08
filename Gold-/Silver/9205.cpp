#include <bits/stdc++.h>
using namespace std;

int graph[103][103]={0};
int node[103][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n; cin >> n;
        for(int i=0; i<n+2; i++) cin >> node[i][0] >> node[i][1];
        for(int i=0; i<103; i++) memset(graph[i], 0, sizeof(graph[i]));
        for(int i=0; i<n+2; i++){
            for(int j=0; j<n+2; j++){
                if(i==j) continue;
                if(abs(node[i][0]-node[j][0])+abs(node[i][1]-node[j][1]) <= 1000) graph[i][j]=1;
            }
        }

        queue<int> q;
        bool vis[103]={0};
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=0; i<n+2; i++){
                if(i==now) continue;
                if(!vis[i] && graph[i][now]==1){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        cout << (vis[n+1]? "happy" : "sad") << endl;
    }

    return 0;
}