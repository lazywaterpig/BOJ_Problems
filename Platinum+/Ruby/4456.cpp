#include <bits/stdc++.h>
using namespace std;

/* 미해결 테스트 데이터
10
1 2 3 1 4 5 6 4 7 8 9 7 10 6 5 9 8 10 2 3
9
1 2 3 4 5 6 7 8 9 1 6 3 4 5 2 7 8 9
9
1 2 3 4 5 1 9 6 7 3 2 8 6 7 8 9 4 5
9
1 2 3 4 5 1 9 6 7 3 4 5 2 8 6 7 8 9
9
1 2 3 4 5 1 9 6 7 3 2 8 6 7 8 9 5 4
9
1 2 3 4 5 1 9 6 7 3 2 4 5 8 6 7 8 9
2
2 1 2 1
0

=-Ans-=
caught
caught
caught
caught
escaped
escaped
escaped

*/

/* algorithms, functions, pseudocode

AddBoundaries(){

}

AddLoop(){

}

IntoIn(공간 내부에 있을 때 && 이전 node와 현재 node가 모두 loop list에 두 번 이상 속해 있을 때){

}

IntoOut(공간 내부에 있을 때 && 현재 node가 loop list에 한 개만 속해 있을 때){

}

OuttoIn(){

}

OuttoOut(공간 외부에 있을 때 && 현재 node가 loop list에 속해 있지 않을 때)





*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int piv=-1; 
        int arr[21], position_cnt[11]={0};
        int loop[21][21], loop_cnt=0;
        int boundary[25][2], boundary_cnt=0;
        for(int i=0; i<2*n; i++){
            cin >> arr[i];
            position_cnt[arr[i]]++;
            if(position_cnt[arr[i]]==1) arr[i]+=100;
            else arr[i]+=200; // 1<=arr[i]<11 => 100의 자릿수에 n번째 node 방문횟수 저장
        }

        //공간 분리 알고리즘
        //공간에서 나올때마다 해당 공간의 남은 정점 수 짝수 아니면 no
        //기존 두개의 공간에 속한 정점을 지날 땐 주어진 공간의 분리
        //

    }

    return 0;
}