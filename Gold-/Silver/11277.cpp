#include <bits/stdc++.h>
using namespace std;

int n, m, arr[21], sat[101][2];
int ans=0;

void backtrack(int d){
    if(ans) return;
    if(d==n+1){
        int flag=0;
        for(int i=0; i<m; i++){
            bool a, b;
            a = sat[i][0]>0?arr[abs(sat[i][0])]:abs(arr[abs(sat[i][0])]-1);
            b = sat[i][1]>0?arr[abs(sat[i][1])]:abs(arr[abs(sat[i][1])]-1);
            if(a+b==0){
                flag=1; break;
            }
        }
        if(!flag) ans=1;
        return;
    }
    arr[d]=0;
    backtrack(d+1);
    arr[d]=1;
    backtrack(d+1);
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++) cin >> sat[i][0] >> sat[i][1];

    backtrack(1);
    cout << ans;
    return 0;
}