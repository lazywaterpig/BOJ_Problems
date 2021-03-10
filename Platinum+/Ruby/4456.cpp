#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int arr[21], position_cnt[11]={0};
        int loop[21][21], loop_cnt=0;
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