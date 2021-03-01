#include <bits/stdc++.h>
using namespace std;

int N, M, r1, r2, c1, c2; // 다람쥐 1: r(ow)1, c(olumn)1

char board[10][102][102], tmp_board[102][102], ans[102][102];
int bcnt=0, clockwise=0; //필요한 경우를 대비해 예비 board[X][][], bcnt=X, 문제풀이의 편의를 위한 board turn, ans를 채워넣은 이후 다시 되돌리기 위한 clockwise


/* 해결 안된 케이스
solve simple
9 5
3 4
4 5

*/

void PrintBoard(){
    cout << "YES" << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

void ClockwisePointTurn(){
    int tN=N, tM=M, tr1=r1, tr2=r2, tc1=c1, tc2=c2;
    N=tM;
    M=tN;
    r1=tc1;
    c1=tN+1-tr1;
    r2=tc2;
    c2=tN+1-tr2;
    clockwise++;
}

void AntiClockwisePointTurn(){
    int tN=N, tM=M, tr1=r1, tr2=r2, tc1=c1, tc2=c2;
    N=tM;
    M=tN;
    r1=tM+1-tc1;
    c1=tr1;
    r2=tM+1-tc2;
    c2=tr2;
    clockwise--;
}

void ClockwiseBoardTurn(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            tmp_board[i][j]=ans[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            ans[j][N+1-i]=tmp_board[i][j];
        }
    }

    ClockwisePointTurn();
}

void AntiClockwiseBoardTurn(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            tmp_board[i][j]=ans[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            ans[M+1-j][i]=tmp_board[i][j];
        }
    }

    AntiClockwisePointTurn();
}

bool IsSimple(){
    if(r1==1 && r2!=1) return true; 
    if(r1==N && r2!=N) return true;
    if(r2==1 && r1!=1) return true;
    if(r2==N && r1!=N) return true;
    if(c1==1 && c2!=1) return true;
    if(c1==M && c2!=M) return true;
    if(c2==1 && c1!=1) return true; //주어진 땅의 서로 다른 모서리 경계값, 혹은 꼭짓점
    if(c2==M && c1!=M) return true; //혹은 하나만 경계값
    if(((r1!=1 && r2!=1) && (r1!=N && r2!=N)) && ((c1!=1 && c2!=1) && (c1!=M && c2!=M))) return true; //둘다 경계값 아닌경우
    return false; //서로 같은 변 경계값이며 꼭짓점 없는경우
}

void solve_2x(){
    //board: 2*X size
    if(N!=2) ClockwisePointTurn();
    if(r1!=r2){
        for(int i=1; i<=M; i++) ans[r1][i]='#';
        for(int i=1; i<=M; i++) ans[r2][i]='.';
    }else{
        if((c1!=1 && c1!=M) && (c2!=1 && c2!=M)){
            cout << "NO" << endl;
            return;
        }
        else{
            if(c1==1 || c1==M){
                for(int i=1; i<=M; i++) ans[r2][i]='.';
                ans[r1][c1]='#';
                if(r2==2) r1=1;
                if(r2==1) r1=2;
                for(int i=1; i<=M; i++) ans[r1][i]='#';
                r1=r2;
            }
            else{
                for(int i=1; i<=M; i++) ans[r1][i]='#';
                ans[r2][c2]='.';
                if(r1==2) r2=1;
                if(r1==1) r2=2;
                for(int i=1; i<=M; i++) ans[r2][i]='.';
                r2=r1;
            }
        }
    }
    if(clockwise==1) AntiClockwiseBoardTurn();
    if(clockwise==-1) ClockwiseBoardTurn();

    PrintBoard();
}
/*  solve simple else case
    if(r1==1 && r2!=1) return true; 
    if(r1==N && r2!=N) return true;
    if(r2==1 && r1!=1) return true;
    if(r2==N && r1!=N) return true;
    if(c1==1 && c2!=1) return true;
    if(c1==M && c2!=M) return true;
    if(c2==1 && c1!=1) return true;
    if(c2==M && c1!=M) return true;  */

void solve_no_boundaries(){
    
}

void solve_simple(){
    //경계값 없는경우
    if(((r1!=1 && r2!=1) && (r1!=N && r2!=N)) && ((c1!=1 && c2!=1) && (c1!=M && c2!=M))){
        solve_no_boundaries();
        return;
    }
    //경계값 다른 둘, 하나
    if(((r1==1 && r2!=1) || (r1==N && r2!=N)) || ((c1==1 && c2!=1) || (c1==M && c2!=M))){
        if(r1==N && r2!=N){
            ClockwisePointTurn();
            ClockwisePointTurn();
        }
        else if(c1==1 && c2!=1){
            ClockwisePointTurn();
        }
        else if(c1==M && c2!=M){
            AntiClockwisePointTurn();
        }

        for(int i=1; i<=M; i++){
            ans[1][i]='#';
            ans[N][i]='.';
        }

        for(int i=1; i<=M; i++){
            char cc;
            if((i+c2)%2!=0) cc='#';
            else cc='.';
            for(int j=2; j<=N-1; j++) ans[j][i]=cc;
        }

        while(clockwise!=0){
            if(clockwise<0) ClockwiseBoardTurn();
            else AntiClockwiseBoardTurn();
        }

        PrintBoard();
    }
    else{
        if(r2==1 && r1!=1){
            ClockwisePointTurn();
            ClockwisePointTurn();
        }
        else if(c2==M && c1!=M){
            ClockwisePointTurn();
        }
        else if(c2==1 && c1!=1){
            AntiClockwisePointTurn();
        }

        for(int i=1; i<=M; i++){
            ans[1][i]='#';
            ans[N][i]='.';
        }

        for(int i=1; i<=M; i++){
            char cc;
            if((i+c1)%2==0) cc='#';
            else cc='.';
            for(int j=2; j<=N-1; j++) ans[j][i]=cc;
        }

        while(clockwise!=0){
            if(clockwise<0) ClockwiseBoardTurn();
            else AntiClockwiseBoardTurn();
        }

        PrintBoard();
    }
}

void solve_even(){
    if(N==2 || M==2) solve_2x();
    else if(IsSimple()) solve_simple();
    else{
        return; //임시
    }
}

void solve_half(){
    if(N==2 || M==2) solve_2x();
    else if(IsSimple()) solve_simple();
    else{
        return; //임시
    }
}

void solve_odd(){
    if(IsSimple()) solve_simple();
    else{
        return; //임시
    }
}

void solve(){
    if(N%2==0 && M%2==0) solve_even();
    else if(N%2==0 || M%2==0) solve_half();
    else solve_odd();
}

int main(){

    cin >> N >> M;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    solve();

    return 0;
}