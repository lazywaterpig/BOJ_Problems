#include <bits/stdc++.h>
using namespace std;

int n, cnt=0, depth;
int arr[11];

void backtrack(int d, int maxv){
    if(n==cnt) return;
    if(d==depth){
        cnt++;
        if(n==cnt){
            for(int i=0; i<depth; i++) cout << arr[i];
        }
        return;
    }
    
    for(int i=depth-d-1; i<=maxv; i++){
        arr[d] = i;
        backtrack(d+1, i-1);
    }
}

int main(){
    
    cin >> n;
    n++;

    for(int i=1; i<11; i++){
        depth = i;
        backtrack(0, 9);
    }

    if(n>cnt) cout << "-1";

    return 0;
}