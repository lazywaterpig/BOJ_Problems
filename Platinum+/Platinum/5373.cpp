#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef pair<int,int> pii;

char cube[6][9], board[9], buf[3];

char dat_cases[2][4][3]={{{0,1,2},{0,3,6},{2,5,8},{6,7,8}},{{2,1,0},{6,3,0},{8,5,2},{8,7,6}}}; //up-low case / each element group type / elements
char dat_turn[2][6][4][2]={{{{'f',1},{'l',1},{'b',1},{'r',1}},{{'F',4},{'R',4},{'B',4},{'L',4}},{{'U',4},{'R',2},{'d',1},{'l',3}},{{'u',1},{'L',2},{'D',4},{'r',3}},{{'U',2},{'F',2},{'D',2},{'b',3}},{{'u',3},{'B',2},{'d',3},{'f',3}}},{{{'F',1},{'R',1},{'B',1},{'L',1}},{{'f',4},{'l',4},{'b',4},{'r',4}},{{'u',4},{'L',3},{'D',1},{'r',2}},{{'U',1},{'R',3},{'d',4},{'l',2}},{{'u',2},{'B',3},{'d',2},{'f',2}},{{'U',3},{'F',3},{'D',3},{'b',2}}}};
//clock-counter / mode(plane) / each 4 plane group / each plane

pii typefinder(int c, int idx, int mode){
    int sub_mode, sub_mode_type;

    if(dat_turn[c][mode][idx][0]=='U'||dat_turn[c][mode][idx][0]=='u') sub_mode=0;
    else if(dat_turn[c][mode][idx][0]=='D'||dat_turn[c][mode][idx][0]=='d') sub_mode=1;
    else if(dat_turn[c][mode][idx][0]=='F'||dat_turn[c][mode][idx][0]=='f') sub_mode=2;
    else if(dat_turn[c][mode][idx][0]=='B'||dat_turn[c][mode][idx][0]=='b') sub_mode=3;
    else if(dat_turn[c][mode][idx][0]=='L'||dat_turn[c][mode][idx][0]=='l') sub_mode=4;
    else sub_mode=5;

    if('A' <= dat_turn[c][mode][idx][0] && dat_turn[c][mode][idx][0] <= 'Z') sub_mode_type=0;
    else sub_mode_type=1;

    return {sub_mode, sub_mode_type};
}

void clockwise_turn(int mode){
    for(int i=0; i<9; i++) board[((i%3)*3)+(2-i/3)]=cube[mode][i];
    for(int i=0; i<9; i++) cube[mode][i]=board[i];

    pii tmp=typefinder(0, 3, mode);

    for(int j=0; j<3; j++){
        buf[j]=cube[tmp.first][dat_cases[tmp.second][dat_turn[0][mode][3][1]-1][j]];
    }

    for(int i=3; i>0; i--){
        pii cur=typefinder(0, i-1, mode);
        pii next=typefinder(0, i, mode);

        for(int j=0; j<3; j++){
            cube[next.first][dat_cases[next.second][dat_turn[0][mode][i][1]-1][j]] = cube[cur.first][dat_cases[cur.second][dat_turn[0][mode][i-1][1]-1][j]];
        }
    }

    pii next=typefinder(0, 0, mode);

    for(int j=0; j<3; j++){
        cube[next.first][dat_cases[next.second][dat_turn[0][mode][0][1]-1][j]] = buf[j];
    }
}

void counterclockwise_turn(int mode){
    for(int i=0; i<9; i++) board[((2-(i%3))*3)+(i/3)]=cube[mode][i];
    for(int i=0; i<9; i++) cube[mode][i]=board[i];

    pii tmp=typefinder(1, 3, mode);

    for(int j=0; j<3; j++){
        buf[j]=cube[tmp.first][dat_cases[tmp.second][dat_turn[1][mode][3][1]-1][j]];
    }

    for(int i=3; i>0; i--){
        pii cur=typefinder(1, i-1, mode);
        pii next=typefinder(1, i, mode);

        for(int j=0; j<3; j++){
            cube[next.first][dat_cases[next.second][dat_turn[1][mode][i][1]-1][j]] = cube[cur.first][dat_cases[cur.second][dat_turn[1][mode][i-1][1]-1][j]];
        }
    }

    pii next=typefinder(1, 0, mode);

    for(int j=0; j<3; j++){
        cube[next.first][dat_cases[next.second][dat_turn[1][mode][0][1]-1][j]] = buf[j];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        int n, plane; cin >> n;

        for(int i=0; i<9; i++){ //큐브 초기화
            cube[0][i]='w';
            cube[1][i]='y';
            cube[2][i]='r';
            cube[3][i]='o';
            cube[4][i]='g';
            cube[5][i]='b';
        }

        while(n--){ //U D F B L R 순으로 plane 0~5
            string ord; cin >> ord;
            if(ord[0] == 'U') plane=0;
            else if(ord[0] == 'D') plane=1;
            else if(ord[0] == 'F') plane=2;
            else if(ord[0] == 'B') plane=3;
            else if(ord[0] == 'L') plane=4;
            else plane=5;

            if(ord[1] == '+') clockwise_turn(plane);
            else counterclockwise_turn(plane);
        }

        for(int i=0; i<9; i++){
            cout << cube[0][i];
            if((i+1)%3==0) cout << endl;
        }
    }

    return 0;
}