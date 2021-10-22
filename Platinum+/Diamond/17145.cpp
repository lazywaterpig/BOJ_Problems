#include <iostream>
#include <cstring>
#define endl "\n"
using namespace std;

string dir="ULDRULDR";
int clockwise=4;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int r, c, x, y;
int board[102][102];

bool oob(int a, int b){
    return (0<=a && a<r && 0<=b && b<c);
}

bool boundary(int a, int b){
    return (a<1 || a>=r-1 || b<1 || b>=c-1);
}

void boardturn(){
    clockwise--;
    int tr=r, tc=c, tx=x, ty=y;
    r=tc;
    c=tr;
    x=tc-1-ty;
    y=tx;
}

void solvespecial(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(i%2==0) board[i][j]=3;
			else board[i][j]=1;
		}
	}
	for(int i=0; i<r; i+=2){
		board[i][c-1]=2;
	}
	for(int i=1; i<r; i+=2){
		board[i][0]=2;
	}
	
    string ans="";
    int tx=x, ty=y, ttx, tty;
    for(int i=0; i<r*c-1; i++){
        ans+=dir[board[tx][ty]+clockwise];
        ttx=dx[board[tx][ty]%4];
        tty=dy[board[tx][ty]%4];
        tx+=ttx;
        ty+=tty;
    }

    cout << ans << endl;
}

void solveboundary(){
    memset(board, -1, sizeof(board));
    if(boundary(x, y)){
    	while(x!=0 || y==c-1) boardturn();
    }
    if(x==0 && y==0){
    	solvespecial();
    	return;
    }
    int tx=x, ty=y, ttx, tty;
    while(ty!=0){
        board[tx][ty]=1;
        ty--;
    }
    
    int flag=0;
    while(ty<y+1){
        if(flag==0){
            while(tx<r-1){
                board[tx][ty]=2;
                tx++;
            }
            board[tx][ty]=3;
            ty++;
            flag=1;
        }
        else{
            while(tx>1){
                board[tx][ty]=0;
                tx--;
            }
            board[tx][ty]=3;
            ty++;
            flag=0;
        }
    }
    
    for(int i=0; i<r; i++){
    	for(int j=y+1; j<c; j++){
    		if(i%2) board[i][j]=1;
    		else board[i][j]=3;
    	}
    }
    for(int i=r-1; i>0; i-=2) board[i][c-1]=0;
    for(int i=r-2; i>0; i-=2) board[i][y+1]=0;
    /*
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) cout << board[i][j] << ' ';
		cout <<endl;
	}*/
    string ans="";
    tx=x, ty=y;
    for(int i=0; i<r*c-1; i++){
        ans+=dir[board[tx][ty]+clockwise];
        ttx=dx[board[tx][ty]%4];
        tty=dy[board[tx][ty]%4];
        tx+=ttx;
        ty+=tty;
    }
    cout << ans << endl;
}

void solveodd(){
    memset(board, -1, sizeof(board));
    if(boundary(x, y)){
        solveboundary();
        return;
    }

    int tx=x, ty=y, ttx, tty;
    if(x%2){
        for(int i=0; i<=y; i++){
            for(int j=0; j<=x; j++){
                if(i%2) board[j][i]=0;
                else board[j][i]=2;
            }
        }
        for(int i=y; i>0; i-=2){
            board[0][i]=1;
        }
        for(int i=y-1; i>0; i-=2){
            board[x][i]=1;
        }
        tx=x, ty=0;
        while(tx<r-1){
            board[tx][ty]=2;
            tx++;
        }
        int flag=0;
        while(tx>-1){
            if(flag==0){
                while(ty<c-1){
                    board[tx][ty]=3;
                    ty++;
                }
                board[tx][ty]=0;
                tx--;
                flag=1;
            }
            else{
                while(board[tx][ty-1]==-1){
                    board[tx][ty]=1;
                    ty--;
                }
                board[tx][ty]=0;
                tx--;
                flag=0;
            }
        }
    }
    else{
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                if(i%2) board[i][j]=3;
                else board[i][j]=1;
            }
        }
        for(int i=1; i<=x; i++) board[i][y]=0;
        for(int i=0; i<=x; i+=2) board[i][0]=2;
        for(int i=1; i<=x; i+=2) board[i][y-1]=2;

        for(int i=0; i<=y; i++){
            for(int j=x+1; j<r; j++){
                if(i%2) board[j][i]=0;
                else board[j][i]=2;
            }
        }
        for(int i=0; i<y; i+=2) board[r-1][i]=3;
        for(int i=1; i<y; i+=2) board[x+1][i]=3;

        tx=r-1, ty=y;
        int flag=0;
        while(tx>-1){
            if(flag==0){
                while(ty<c-1){
                    board[tx][ty]=3;
                    ty++;
                }
                board[tx][ty]=0;
                tx--;
                flag=1;
            }
            else{
                while(board[tx][ty-1]==-1){
                    board[tx][ty]=1;
                    ty--;
                }
                board[tx][ty]=0;
                tx--;
                flag=0;
            }
        }
    }

    string ans="";
    tx=x, ty=y;
    for(int i=0; i<r*c-1; i++){
        ans+=dir[board[tx][ty]+clockwise];
        ttx=dx[board[tx][ty]%4];
        tty=dy[board[tx][ty]%4];
        tx+=ttx;
        ty+=tty;
    }
    cout << ans << endl;
}

void solveeven(){
    if(c%2){
        for(int i=0; i<r-1; i++) board[i][0]=2;
        board[r-1][0]=3;
        int idx=1, flag=0;
        for(int i=r-1; i>0; i--){
            if(flag==0){
                while(idx<c-1){
                    board[i][idx]=3;
                    idx++;
                }
                board[i][idx]=0;
                flag=1;
            }
            else{
                while(idx>1){
                    board[i][idx]=1;
                    idx--;
                }
                board[i][idx]=0;
                flag=0;
            }
        }
        for(int i=1; i<c; i++) board[0][i]=1;
    }
    else{
        for(int i=1; i<c; i++) board[0][i]=1;
        board[0][0]=2;
        int idx=1, flag=0;
        for(int i=0; i<c-1; i++){
            if(flag==0){
                while(idx<r-1){
                    board[idx][i]=2;
                    idx++;
                }
                board[idx][i]=3;
                flag=1;
            }
            else{
                while(idx>1){
                    board[idx][i]=0;
                    idx--;
                }
                board[idx][i]=3;
                flag=0;
            }
        }
        for(int i=1; i<r; i++) board[i][c-1]=0;
    }

    string ans="";
    int tx=x, ty=y, ttx, tty;
    for(int i=0; i<r*c-1; i++){
        ans+=dir[board[tx][ty]];
        ttx=dx[board[tx][ty]];
        tty=dy[board[tx][ty]];
        tx+=ttx;
        ty+=tty;
    }

    cout << ans << endl;
}

void solve(){
	clockwise=4;
    if((r*c)%2) solveodd();
    else solveeven();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    char tmp;
    while(t--){
        cin >> r >> c >> x >> y;
        if((x+y)%2 && (r*c)%2){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        if((r==1 || c==1) && ((x!=1 && x!=r) || (y!=1 && y!=c))){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        if(r==1 || c==1){
            if(r==1){
                c--;
                tmp=(x==1?'R':'L');
                while(c--) cout << tmp;
                cout << endl;
            }
            else{
                r--;
                tmp=(y==1?'D':'U');
                while(r--) cout << tmp;
                cout << endl;
            }
            continue;
        }
        x--; y--;
        solve();
    }

    return 0;
}