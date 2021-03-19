#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

int n, arr[3][2]={0}, tmp[3][2]={0};
int main(){
    fastio;
    cin >> n;
    while(n--){
        for(int i=0; i<3; i++){
            tmp[i][0]=arr[i][0];
            tmp[i][1]=arr[i][1];
        }
        cin >> arr[0][0] >> arr[1][0] >> arr[2][0];
        for(int i=0; i<3; i++) arr[i][1]=arr[i][0];

        arr[0][0]+=max(tmp[0][0], tmp[1][0]);
        arr[1][0]+=max(max(tmp[0][0], tmp[1][0]), tmp[2][0]);
        arr[2][0]+=max(tmp[1][0], tmp[2][0]);

        arr[0][1]+=min(tmp[0][1], tmp[1][1]);
        arr[1][1]+=min(min(tmp[0][1], tmp[1][1]), tmp[2][1]);
        arr[2][1]+=min(tmp[1][1], tmp[2][1]);
    }
    cout << max(max(arr[0][0], arr[1][0]), arr[2][0]) << ' ' << min(min(arr[0][1], arr[1][1]), arr[2][1]) << endl;
    return 0;
}