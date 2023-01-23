#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, l, ans=0; cin >> n >> k;
    int board[101][101]={0};
    int t[101]; char d[101];
    int x[4]={0, -1, 0, 1}, y[4]={1, 0, -1, 0};
    
    queue<pair<int,int>> q;
    int dir_piv=0;
    pair<int,int> dir;

    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        board[a][b]=2;
    }
    
    q.push({0,0});
    board[0][0]=1;
    dir={0,1};

    cin >> l;
    for(int i=0; i<l; i++) cin >> t[i] >> d[i];
    int piv=0;
    
    while(1){
		ans++;
        int tx=q.back().first+dir.first, ty=q.back().second+dir.second;
        
        if(tx>=n || ty>=n || tx<0 || ty<0) break;
        if(board[tx][ty]==1) break;
        q.push({tx, ty});

        if(board[tx][ty]==0){
            board[q.front().first][q.front().second]=0;
            q.pop();
        }
        board[tx][ty]=1;

        if(piv<l && t[piv]==ans){
            if(d[piv]=='L') dir_piv = (dir_piv+1)%4;
            else dir_piv = (dir_piv+3)%4;

            dir = {x[dir_piv], y[dir_piv]};
            piv++;
        }
    }

    cout << ans;
    return 0;
}