#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<pii> v(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
        pq.push({v[i].first, 1});
        pq.push({v[i].second, 0});
    }

    int cnt=0, maxv=-1;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(cur.second==1){
            cnt++;
            if(cnt>maxv) maxv=cnt;
        }
        else cnt--;
    }

    cout << maxv;
    return 0;
}