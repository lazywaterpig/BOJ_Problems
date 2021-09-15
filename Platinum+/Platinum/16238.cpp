#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,n,arr[1001],ans=0;
    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n, greater<>());
    for(i=0; i<n; i++){
        if(arr[i]<i) break;
        ans+=arr[i];
    }
    cout << ans-i*(i-1)/2;
    return 0;
}