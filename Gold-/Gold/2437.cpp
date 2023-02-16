#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    int ans=0;
    for(int i=0; i<n; i++){
    	if(arr[i]>ans+1) break;
    	ans+=arr[i];
    }
    cout << ans+1;

    return 0;
}