#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int arr[15];

bool possible(int idx){
    for(int i=idx-1; i>=0; i--){
        if(arr[i]==arr[idx] || abs(arr[idx]-arr[i])==idx-i) return false;
    }
    return true;
}

void backtrack(int idx){
    if(idx==n-1){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){
        arr[idx+1]=i;
        if(possible(idx+1)) backtrack(idx+1);
    }
}

int main(){
    cin >> n;
    cnt=0;
    backtrack(-1);
    cout << cnt << endl;
    return 0;
}


/*#include <stdio.h>

int main(){
    int n, arr[16]={0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};
    scanf("%d", &n);
    printf("%d", arr[n]);
}*/
