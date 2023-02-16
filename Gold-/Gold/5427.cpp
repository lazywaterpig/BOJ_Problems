#include <bits/stdc++.h>
#define picii pair<pair<int, char>, pair<int, int>>
#define fi first
#define se second
using namespace std;

char board[1010][1010];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt;; cin >> tt;
    while(tt--){
        int n, m; cin >> m >> n;
        for(int i=0; i<n+2; i++){
            board[i][0]='!';
            board[i][m+1]='!';
        }
        for(int i=0; i<m+2; i++){
            board[0][i]='!';
            board[n+1][i]='!';
        }

        int xs, ys;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                cin >> board[i][j];
                if(board[i][j]=='@'){
                    xs=i; ys=j;
                }
            }
        }
        
        queue<picii> q;
        q.push({{0, '@'}, {xs, ys}});
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(board[i][j]=='*') q.push({{0, '*'}, {i, j}});
            }
        }

        int flag=0;
        while(!q.empty()){
            auto cur = q.front();
            int cx=cur.se.fi, cy=cur.se.se;
            q.pop();
            
            if(cur.fi.se=='@'){
            	if(board[cx][cy]!='@') continue;
                for(int i=0; i<4; i++){
                    if(board[cx+dx[i]][cy+dy[i]]=='!'){
                        flag=1;
                        cout << cur.fi.fi+1 << endl;
                        break;
                    }

                    if(board[cx+dx[i]][cy+dy[i]]=='.'){
                        q.push({{cur.fi.fi+1, '@'}, {cx+dx[i], cy+dy[i]}});
                        board[cx+dx[i]][cy+dy[i]]='@';
                    }
                }
            }
            else{
                for(int i=0; i<4; i++){
                    if(board[cx+dx[i]][cy+dy[i]]=='.' || board[cx+dx[i]][cy+dy[i]]=='@'){
                        q.push({{cur.fi.fi+1, '*'}, {cx+dx[i], cy+dy[i]}});
                        board[cx+dx[i]][cy+dy[i]]='*';
                    }
                }
            }

            if(flag) break;
        }

        if(!flag) cout << "IMPOSSIBLE\n";
    }

    return 0;
}