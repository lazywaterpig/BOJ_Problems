#include <bits/stdc++.h>
#define MAX 126
#define INF 1e9
#define endl "\n";
#define piii pair<int,pair<int,int>>
using namespace std;

int n, d[5]={-1,0,1,0,-1};
int arr[MAX][MAX], dist[MAX][MAX];

bool OOB(int x, int y){
    return (x<0 || y<0 || x>n-1 || y>n-1);
}

void dijkstra(){
    dist[0][0]=arr[0][0];
    priority_queue <piii, vector<piii>, greater<piii>> pq;
    pq.push({dist[0][0], {0,0}});

    while(!pq.empty()){
        int cost=pq.top().first;
        int curx=pq.top().second.first;
        int cury=pq.top().second.second;
        pq.pop();

        if(dist[curx][cury]<cost) continue;
        for(int i=0; i<4; i++){
            int nextx=curx+d[i];
            int nexty=cury+d[i+1];
            if(OOB(nextx, nexty)) continue;

            int nextcost=cost+arr[nextx][nexty];

            if(dist[nextx][nexty]>nextcost){
                dist[nextx][nexty]=nextcost;
                pq.push({nextcost,{nextx, nexty}});
            }
        }
    }
    cout << dist[n-1][n-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt=1;
    while(1){
        cin >> n;
        if(n==0) break;

        cout << "Problem " << cnt << ": ";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                dist[i][j]=INF;
            }
        }
        dijkstra();
        cnt++;
    }

    return 0;
}