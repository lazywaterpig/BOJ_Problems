#include <bits/stdc++.h>
#define MAX 1000000009
using namespace std;
// + - x /
// 0 1 2 3
int n, maxv=-MAX, minv=MAX;
int arr[12], opr[5], oprperm[12];

void calc(){
    int val=arr[0];
    for(int i=0; i<n-1; i++){
        if(oprperm[i]==0) val+=arr[i+1];
        if(oprperm[i]==1) val-=arr[i+1];
        if(oprperm[i]==2) val*=arr[i+1];
        if(oprperm[i]==3) val/=arr[i+1];
    }
    if(val>maxv) maxv=val;
    if(val<minv) minv=val;
}

void backtrack(int cnt){
    if(cnt==n-1){
        calc();
        return;
    }
    for(int i=0; i<4; i++){
        if(opr[i]){
            opr[i]--;
            oprperm[cnt]=i;
            backtrack(cnt+1);
            opr[i]++;
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<4; i++) cin >> opr[i];

    backtrack(0);

    cout << maxv << '\n' << minv;
    return 0;
}