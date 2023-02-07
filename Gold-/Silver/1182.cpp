#include <bits/stdc++.h>
using namespace std;

int n, S, ans=0;
int arr[21], pick[21];

void backtrack(int cnt){
    if(cnt==n){
        int sum=0;
        for(int i=0; i<n; i++) sum+=pick[i]*arr[i];

        if(sum == S) ans++;
        return;
    }
    for(int i=0; i<2; i++){
        pick[cnt]=i;
        backtrack(cnt+1);
    }
}

int main(){
    cin >> n >> S;
    for(int i=0; i<n; i++) cin >> arr[i];

    backtrack(0);

	if(!S) ans--;
    cout << ans;
    return 0;
}