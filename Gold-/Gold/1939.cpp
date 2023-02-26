#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define INF 1e9+7
#define piii pair<int,pair<int,int>>
#define fi first
#define se second
#define endl '\n';
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pii> arr(n);
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        arr[i]={a,a+b};
    }

    sort(arr.begin(), arr.end());

    int s=0, e=2e9, m, maxv=-1, flag, piv;
    while(s<=e){
        m=s/2 + e/2 + (s%2 + e%2)/2;
        flag=0;
        piv=arr[0].fi;
        for(int i=1; i<n; i++){
            if(arr[i].se<piv+m){
                flag=1;
                break;
            }
            piv=max(piv+m, arr[i].fi);
        }
        if(!flag){
            maxv=m;
            s=m+1;
        }
        else e=m-1;
    }

    cout << maxv;
    return 0;
}