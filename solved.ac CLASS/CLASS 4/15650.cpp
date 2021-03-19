#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];

bool possible(int idx){
    if(arr[idx-1]>=arr[idx])return false;
    return true;
}

void backtrack(int idx){
    if(idx==m-1){
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << endl;
        return;
    }
    for(int i=1; i<=n; i++){
        arr[idx+1]=i;
        if(possible(idx+1)) backtrack(idx+1);
    }
}

int main(){
    cin >> n >> m;
    backtrack(-1);
    return 0;
}