#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

char board[11][11];
int d[5]={-1,0,1,0,-1};

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    pii fR, fB, O;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            board[i][j]=s[j];
            if(s[j]=='R') fR={i,j};
            if(s[j]=='B') fB={i,j};
            if(s[j]=='O') O={i,j};
            if(board[i][j]!='.' && board[i][j]!='#') board[i][j]='.';
        }
    }
	
    queue<pair<pii,pii>> q;
    q.push({fR,fB});
    int ans=0;
    for(int _=1; _<=10; _++){
        int sz=q.size();
        while(sz--){
            pii R=q.front().x, B=q.front().y, tR, tB;
            q.pop();
            for(int i=0; i<4; i++){
                tR=R;
                tB=B;
                board[tR.x][tR.y]='R';
                board[tB.x][tB.y]='B';
                board[O.x][O.y]='O';
                int flag=0, rflag=0;
                while(1){
                    if(board[tR.x+d[i]][tR.y+d[i+1]]=='O'){
                        rflag=1;
                        board[tR.x][tR.y]='.';
                    }
                    if(rflag) break;
                    if(board[tR.x+d[i]][tR.y+d[i+1]]=='.'){
                        board[tR.x][tR.y]='.';
                        tR.x+=d[i];
                        tR.y+=d[i+1];
                        board[tR.x][tR.y]='R';
                    }
                    else break;
                }
                
                while(1){
                    if(board[tB.x+d[i]][tB.y+d[i+1]]=='O') flag=1;
                    if(flag) break;
                    if(board[tB.x+d[i]][tB.y+d[i+1]]=='.'){
                        board[tB.x][tB.y]='.';
                        tB.x+=d[i];
                        tB.y+=d[i+1];
                        board[tB.x][tB.y]='B';
                    }
                    else break;
                }

                if(flag){
                    board[tR.x][tR.y]='.';
                    board[tB.x][tB.y]='.';
                    board[O.x][O.y]='.';
                    continue;
                }

                if(rflag){
                    ans=_;
                    break;
                }

                while(1){
                    if(board[tR.x+d[i]][tR.y+d[i+1]]=='.'){
                        board[tR.x][tR.y]='.';
                        tR.x+=d[i];
                        tR.y+=d[i+1];
                        board[tR.x][tR.y]='R';
                    }
                    else break;
                }

                q.push({tR,tB});
                board[tR.x][tR.y]='.';
                board[tB.x][tB.y]='.';
                board[O.x][O.y]='.';
            }
            if(ans) break;
        }
        if(ans) break;
    }

    cout << (ans?ans:-1);
    return 0;
} 