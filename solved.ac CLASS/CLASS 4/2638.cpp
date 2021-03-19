#include <bits/stdc++.h>
using namespace std;

int n, m, cnt=0, ans=0;
int arr[102][102];
bool vis[102][102];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

bool OOB(int a, int lb, int ub){return !(lb<=a && a<=ub);}

void bfs(int x, int y){
    queue <pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=true;
    arr[x][y]=2;
    int tx, ty, nx, ny;
    while(!q.empty()){
        tx=q.front().first;
        ty=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            nx=tx+dx[i];
            ny=ty+dy[i];
            if(!OOB(nx,1,n) && !OOB(ny,1,m)){
                if(!vis[nx][ny] && arr[nx][ny]==0){
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                    arr[nx][ny]=2;
                }
            }
        }
    }
}

bool dissolve(int x, int y){
    int sum=0;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(arr[nx][ny]==2) sum++;
    }
    if(sum>=2) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1) cnt++;
        }
    }
    while(cnt>0){
        memset(vis, false, sizeof(vis));
        for(int i=1; i<=m; i++){
            if(!vis[1][i] && arr[1][i]==0) bfs(1, i);
            if(!vis[n][i] && arr[n][i]==0) bfs(n, i);
        }
        for(int i=1; i<=n; i++){
            if(!vis[i][1] && arr[i][1]==0) bfs(i, 1);
            if(!vis[i][m] && arr[i][m]==0) bfs(i, m);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j]==1 && dissolve(i,j)){
                    arr[i][j]=3;
                    cnt--;
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j]>=2) arr[i][j]=0;
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}