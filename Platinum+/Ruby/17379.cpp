#include <bits/stdc++.h>
using namespace std;

int N, M, r1, r2, c1, c2;

char tmp_board[102][102], ans[102][102];
int bcnt=0, clockwise=0;

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
    if(c2==1 && c1!=1) return true;
    if(c2==M && c1!=M) return true;
    if(((r1!=1 && r2!=1) && (r1!=N && r2!=N)) && ((c1!=1 && c2!=1) && (c1!=M && c2!=M))) return true;
    return false;
}

void solve_2x(){
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

void solve_no_boundaries(){
    if(abs(c1-c2)%2!=0) ClockwisePointTurn();

    if(abs(r1-r2)%2!=0){
        for(int i=1; i<=N; i++){
            char cc;
            if((r1+i)%2==0) cc='#';
            else cc='.';
            for(int j=2; j<=M-1; j++) ans[i][j]=cc;
        }
        for(int i=1; i<=N; i++){
            ans[i][1]='#';
            ans[i][M]='.';
        }

        if(clockwise==1) AntiClockwiseBoardTurn();
        PrintBoard();
    }
    else{
        if(r1!=r2 && c1!=c2){
            while(r1<r2 || c1<c2) ClockwisePointTurn();

            for(int i=1; i<=M; i++){
                ans[1][i]='#';
                ans[N][i]='.';
            }
            for(int i=1; i<=M; i++){
                char cc;
                if((c1+i)%2==0) cc='#';
                else cc='.';
                for(int j=2; j<=N-1; j++) ans[j][i]=cc;
            }

            for(int i=c2; i<c1; i++) ans[r2][i]='.';
            for(int i=c1; i>c2; i--) ans[r1][i]='#';
            
            while(clockwise!=0) AntiClockwiseBoardTurn();
            PrintBoard();
        }
        else{
            while(r1<=r2) ClockwisePointTurn();

            for(int i=1; i<=M; i++){
                ans[1][i]='#';
                ans[N][i]='.';
            }
            for(int i=1; i<=M; i++){
                char cc;
                if(i%2!=0) cc='#';
                else cc='.';
                for(int j=2; j<=N-1; j++) ans[j][i]=cc;
            }

            if(M==3){
                for(int i=r1; i<N; i++) ans[i][2]='#';
                for(int i=r1-1; i<=N; i++) ans[i][1]='.';
                for(int i=r1+1; i<=N; i++) ans[i][3]='.';
            }
            else{
                if(c1!=2){
                    ans[r1][c1]='#';
                    ans[r1][c1-1]='#';
                    ans[r2][c2]='.';
                    ans[r2][c2-1]='.';
                }
                else{
                    ans[r1][c1]='#';
                    ans[r1][c1+1]='#';
                    ans[r2][c2]='.';
                    ans[r2][c2+1]='.';
                }
            }

            while(clockwise!=0) AntiClockwiseBoardTurn();
            PrintBoard();
        }
    }
}

void solve_simple(){
    if(((r1!=1 && r2!=1) && (r1!=N && r2!=N)) && ((c1!=1 && c2!=1) && (c1!=M && c2!=M))){
        solve_no_boundaries();
        return;
    }
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
        while(r1!=1) ClockwisePointTurn();

        if(abs(c1-c2)==1 && min(c1, c2)%2==0){
            cout << "NO" << endl;
            return;
        }
        else{
            if(min(c1, c2)%2==0){
                if(c1<c2) c1++;
                else c2++;
            }
            char sc=c1<c2? '#' : '.';
            char bc=c1>c2? '#' : '.';

            for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++) ans[i][j]=bc;
            }

            for(int i=1; i<=M; i++) ans[N][i]=sc;
            for(int i=1; i<M; i+=2){
                for(int j=2; j<N; j++) ans[j][i]=sc;
            }
            for(int i=1; i<=min(c1,c2); i++) ans[1][i]=sc;
            for(int i=2; i<=min(c1,c2)+1; i++) ans[N-1][i]=bc;
            
            while(clockwise!=0) AntiClockwiseBoardTurn();
            PrintBoard();
        }
    }
}

void solve_half(){
    if(N==2 || M==2) solve_2x();
    else if(IsSimple()) solve_simple();
    else{
        while(r1!=1) ClockwisePointTurn();
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++) ans[i][j]='#';
        }

        if(M%2==0){
            for(int i=2; i<N; i+=2){
                for(int j=2; j<M; j++) ans[i][j]='.';
            }

            for(int i=1; i<N; i++) ans[i][c2]='.';
        }
        else{
            for(int i=2; i<M; i+=2){
                for(int j=2; j<N; j++) ans[j][i]='.';
            }

            for(int i=2; i<M; i++) ans[2][i]='.';
            ans[r2][c2]='.';
        }

        while(clockwise!=0) AntiClockwiseBoardTurn();
        PrintBoard();
    }
}

void solve_odd(){
    if(IsSimple()) solve_simple();
    else{
        while(r1!=1) ClockwisePointTurn();

        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++) ans[i][j]='#';
        }

        for(int i=2; i<N; i+=2){
            for(int j=2; j<M; j++) ans[i][j]='.';
        }

        for(int i=1; i<N; i++) ans[i][c2]='.';

        while(clockwise!=0) AntiClockwiseBoardTurn();
        PrintBoard();
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