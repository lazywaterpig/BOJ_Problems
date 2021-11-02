#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int arr[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, val; cin >> n >> val;
    arr[0]=0;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) arr[i]+=arr[i-1];

    int l=1, r=1, ans=1e9;

    while(r<=n){
        if(arr[r]-arr[l-1]>=val){
            ans=min(ans, r-l+1);
            l++;
        }
        else r++;

        if(l>r) r++;
    }

    if(ans==1e9) cout << "0";
    else cout << ans;
    return 0;
}