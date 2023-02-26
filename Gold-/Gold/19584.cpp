#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, tmp; cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> tmp >> arr[i];
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        if(arr[a]>arr[b]) swap(a,b);
        pq.push({arr[a],-c});
        pq.push({arr[b],c});
    }

    ll sum=0, ans=0;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        sum+=cur.second;
        if(ans>sum) ans=sum;
    }

    cout << -ans;
    return 0;
}