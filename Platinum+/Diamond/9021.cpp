#include <bits/stdc++.h>
using namespace std;

int N, M, r1, r2, c1, c2;
int d[5]={-1,0,1,0,-1};
int rpri[4]={-1, 0, 0, 1};
int cpri[4]={0, 1, -1, 0};
int diag[9]={1, 1, -1, -1, 1, 0, -1, 0, 1};

int tmp_board[102][102], ans[102][102];
int clockwise=0;

bool IsStartPoint(int x1, int y1){
    return (x1==r1 && y1==c1);
}

bool IsEndPoint(int x1, int y1){
    return (x1==r2 && y1==c2);
}

bool IsInBoard(int x1, int y1){
    return (1<=x1 && x1<=M && 1<=y1 && y1<=N);
}

void ClockwisePointTurn(){
    int tN=N, tM=M, tr1=r1, tr2=r2, tc1=c1, tc2=c2;
    N=tM;
    M=tN;
    r1=tc1;
    c1=tM+1-tr1;
    r2=tc2;
    c2=tM+1-tr2;
    clockwise++;
}

void ClockwiseBoardTurn(){
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            tmp_board[i][j]=ans[i][j];
        }
    }

    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            ans[j][M+1-i]=tmp_board[i][j];
        }
    }

    ClockwisePointTurn();
}

void Solve(){
    ans[r1][c1]=1;
    ans[r2][c2]=N*M;

    int cnt=2, p1_piv=2, p2_piv=N*M-1;
    int bcnt=2;
    while(cnt<N*M){
        while(cnt<N*M){
            int dr, dc, dcnt=0;
            for(int i=0; i<4; i++){
                if(IsInBoard(r2+rpri[i], c2+cpri[i]) && ans[r2+rpri[i]][c2+cpri[i]]==0){
                    dcnt++;
                    dr=rpri[i];
                    dc=cpri[i];
                    //cout << "!!" << dr << ' ' << dc << endl;
                } 
            }
            if(dcnt!=1) break;
            //cout << "??" << dcnt << endl;

            r2+=dr;
            c2+=dc;
            ans[r2][c2]=p2_piv;
            cnt++;
            p2_piv--;
        }
        
        for(int i=0; i<4; i++){
            bool flag=0;
            cout <<r1+rpri[i]<< ' '<<c1+cpri[i] <<' ' << i << endl;
            if(IsInBoard(r1+rpri[i], c1+cpri[i]) && ans[r1+rpri[i]][c1+cpri[i]]==0){
            	cout <<r1+rpri[i]<< ' '<<c1+cpri[i] <<' ' << '?' << endl;
                cnt++;
                ans[r1+rpri[i]][c1+cpri[i]]=p1_piv;
                p1_piv++;
                bool diagflag=0;
                for(int j=0; j<8; j++){
                    if(IsInBoard(r1+rpri[i]+diag[j], c1+cpri[i]+diag[j+1]) && ans[r1+rpri[i]+diag[j]][c1+cpri[i]+diag[j+1]]==0){
                        int tcnt=0;
                        for(int k=0; k<4; k++){
                            if(IsInBoard(r1+rpri[i]+diag[j]+d[k], c1+cpri[i]+diag[j+1]+d[k+1]) && ans[r1+rpri[i]+diag[j]+d[k]][c1+cpri[i]+diag[j+1]+d[k+1]]==0) {tcnt++; cout << "A";}
                            if(IsInBoard(r1+rpri[i]+diag[j]+d[k], c1+cpri[i]+diag[j+1]+d[k+1]) && IsStartPoint(r1+rpri[i]+diag[j]+d[k], c1+cpri[i]+diag[j+1]+d[k+1])) {tcnt++; cout << "B";}
                            if(IsInBoard(r1+rpri[i]+diag[j]+d[k], c1+cpri[i]+diag[j+1]+d[k+1]) && IsEndPoint(r1+rpri[i]+diag[j]+d[k], c1+cpri[i]+diag[j+1]+d[k+1])) {tcnt++; cout << "C";}
                            cout << tcnt;
                        }
                        if(tcnt<2) {diagflag=1; cout << "=+=" << diag[i] << ' ' << diag[i] << endl;}
                    }
                }

                if(diagflag==1){
                    flag=1;
                    cnt--;
                    ans[r1+rpri[i]][c1+cpri[i]]=0;
                    p1_piv--;

                }
                else{
                	cout << rpri[i] << cpri[i] << "FDSA" << endl;
                    r1+=rpri[i];
                    c1+=cpri[i];
                    break;
                }
            }
            else flag=1;

            if(flag==0) break;
        }

        if(bcnt==cnt){ cout << "-1\n"; return;}
        bcnt=cnt;
        
    	cout << r1 << ' ' << c1 << ' ' << cnt << endl;//
    	
	    for(int i=1; i<=M; i++){
	        for(int j=1; j<=N; j++){
	            cout << ans[i][j] <<' ';
	        }
	        cout << endl;
	    }
    }

    while(clockwise%4!=0) ClockwiseBoardTurn();

    cout << "1\n";
    int rcflag=0;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(IsInBoard(i,j) && ans[i][j]==1){
                r1=i;
                c1=j;
                rcflag=1;
                break;
            }
        }
        if(rcflag==1) break;
    }
    //cout << r1 << c1 << endl;
    int rcur=r1, ccur=c1;
    for(int i=1; i<N*M+1; i++){
        cout << rcur << ' ' << ccur << "\n";
        for(int j=0; j<4; j++){
            if(IsInBoard(rcur+d[j],ccur+d[j+1]) && ans[rcur+d[j]][ccur+d[j+1]]==i+1){
                rcur+=d[j];
                ccur+=d[j+1];
                break;
            }
        }
    }
    /*
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cout << ans[i][j] <<' ';
        }
        cout << endl;
    }*/
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        cin >> M >> N;
        cin >> r1 >> c1;
        cin >> r2 >> c2;
        if((abs(r2-r1)+abs(c2-c1))%2==0) cout << "-1\n";
        else{
            for(int i=0; i<102; i++) memset(ans[i], 0, sizeof(ans[i]));
            while(r2<r1 || c2<c1) ClockwisePointTurn();
            Solve();
        }
    }

    return 0;
}