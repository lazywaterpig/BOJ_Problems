#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct p{
    int dist=1e9;
    int p1x, p1y, p2x, p2y;
    int lx, ly;
};

int taxicab(int x, int y, int px, int py){
    return abs(x-px)+abs(y-py);
}

p dp[1001][1001];
bool vis[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w; cin >> n >> w;
    int arr[1002][2];
    for(int i=1; i<=w; i++) cin >> arr[i][0] >> arr[i][1];
    dp[0][0].dist=0;
    dp[0][0].p1x=dp[0][0].p1y=1;
    dp[0][0].p2x=dp[0][0].p2y=n;
	//cout << dp[0][0].dist << endl;
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=true;
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        int maxv=max(cur.first, cur.second);
        if(dp[maxv+1][cur.second].dist>dp[cur.first][cur.second].dist+taxicab(arr[maxv+1][0], arr[maxv+1][1], dp[cur.first][cur.second].p1x, dp[cur.first][cur.second].p1y)){
            dp[maxv+1][cur.second].dist=dp[cur.first][cur.second].dist+taxicab(arr[maxv+1][0], arr[maxv+1][1], dp[cur.first][cur.second].p1x, dp[cur.first][cur.second].p1y);
            dp[maxv+1][cur.second].p1x=arr[maxv+1][0];
            dp[maxv+1][cur.second].p1y=arr[maxv+1][1];
            dp[maxv+1][cur.second].p2x=dp[cur.first][cur.second].p2x;
            dp[maxv+1][cur.second].p2y=dp[cur.first][cur.second].p2y;
            dp[maxv+1][cur.second].lx=cur.first;
            dp[maxv+1][cur.second].ly=cur.second;
        }
        if(dp[cur.first][maxv+1].dist>dp[cur.first][cur.second].dist+taxicab(arr[maxv+1][0], arr[maxv+1][1], dp[cur.first][cur.second].p2x, dp[cur.first][cur.second].p2y)){
            dp[maxv+1][cur.second].dist=dp[cur.first][cur.second].dist+taxicab(arr[maxv+1][0], arr[maxv+1][1], dp[cur.first][cur.second].p2x, dp[cur.first][cur.second].p2y);
            dp[cur.first][maxv+1].p2x=arr[maxv+1][0];
            dp[cur.first][maxv+1].p2y=arr[maxv+1][1];
            dp[cur.first][maxv+1].p1x=dp[cur.first][cur.second].p1x;
            dp[cur.first][maxv+1].p1y=dp[cur.first][cur.second].p1y;
            dp[cur.first][maxv+1].lx=cur.first;
            dp[cur.first][maxv+1].ly=cur.second;
        }

        if(maxv<n-1){
            if(!vis[maxv+1][cur.second]){
                q.push({maxv+1, cur.second});
                vis[maxv+1][cur.second]=true;
            }
            if(!vis[cur.first][maxv+1]){
                q.push({cur.first, maxv+1});
                vis[cur.first][maxv+1]=true;
            }
        }
    }

    int ans=1e9;
    int tx, ty;
    for(int i=0; i<w; i++){
        if(dp[w][i].dist<ans){
        	ans=dp[w][i].dist;
        	tx=w;
        	ty=i;
        }
        if(dp[i][w].dist<ans){
        	ans=dp[i][w].dist;
        	tx=i;
        	ty=w;
        }
    }
    
    for(int i=w; i>0; i--){
    	cout << tx << ' ' << ty << endl;
    	int tmpx=tx, tmpy=ty;
    	tx=dp[tmpx][tmpy].lx;
    	ty=dp[tmpx][tmpy].ly;
    }
    
    for(int i=1; i<=w; i++){
    	for(int j=1; j<=w; j++){
    		cout << dp[i][j].dist << ' ';
    	}
    	cout << endl;
    }

    cout << ans;
    return 0;
}