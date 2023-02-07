#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9], vis[9]={0};

void backtrack(int idx){
    if(idx==m){
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            arr[idx]=i;
            vis[i]=1;
            backtrack(idx+1);
            vis[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    backtrack(0);

    return 0;
}