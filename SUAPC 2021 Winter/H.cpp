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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    priority_queue<pii> pq;

    for(int i=0; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        int g = gcd(abs(a),abs(b));
        pq.push({a/g, b/g});
    }

    ll ans=n*(n-1)/2, cnt=1;
    auto cur = pq.top();
    pq.pop();

    while(!pq.empty()){
        auto next = pq.top();
        if(cur.fi == next.fi && cur.se == next.se){
            cnt++;
            pq.pop();
        }
        else{
            ans-=cnt*(cnt-1)/2;
            cnt=1;
            cur=next;
        }
    }
    ans-=cnt*(cnt-1)/2;
    cout << ans;
    return 0;
}