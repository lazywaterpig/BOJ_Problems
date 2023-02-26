#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define INF 1e9+7
#define piii pair<int,pair<int,int>>
#define fi first
#define se second
using namespace std;

int cnt[1001000]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int cut = 1.0*9*m/10+0.99;

    int flag=0;
    for(int i=0; i<m; i++){
        cnt[arr[i]]++;
        if(cnt[arr[i]]>=cut) flag=1;
    }

    for(int i=m; i<n; i++){
        cnt[arr[i-m]]--;
        cnt[arr[i]]++;
        if(cnt[arr[i]]>=cut) flag=1;
    }

    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}