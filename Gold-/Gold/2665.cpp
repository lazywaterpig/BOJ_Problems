#include <bits/stdc++.h>
#define MAX 51
#define INF 2501
#define piii pair<int,pair<int,int>>
using namespace std;

int d[5]={-1,0,1,0,-1};

int n;
int arr[MAX][MAX], depth[MAX][MAX];
priority_queue <piii, vector<piii>, greater<piii>> pq;

bool OOB(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
    	string ord; cin >> ord;
        for(int j=0; j<n; j++){
            arr[i][j]=ord[j]-48;
            arr[i][j]^=1;
            depth[i][j]=INF;
        }
    }

    pq.push({0,{0,0}});
    depth[0][0]=0;
    while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int cost=pq.top().first;
        pq.pop();
        if(cost>depth[x][y]) continue;
        for(int i=0; i<4; i++){
            if(!OOB(x+d[i], y+d[i+1]) && cost+arr[x+d[i]][y+d[i+1]]<depth[x+d[i]][y+d[i+1]]){
                pq.push({cost+arr[x+d[i]][y+d[i+1]], {x+d[i], y+d[i+1]}});
                depth[x+d[i]][y+d[i+1]]=cost+arr[x+d[i]][y+d[i+1]];
            }
        }
    }

    cout << depth[n-1][n-1];
    return 0;
}