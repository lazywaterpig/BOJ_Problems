#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

bool jcmp(pii a, pii b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<pii> jewel;
    vector<ll> bag;
    priority_queue<pii> pq;

    ll n, k; cin >> n >> k;
    for(ll i=0; i<n; i++){
        ll mi, vi; cin >> mi >> vi;
        jewel.push_back({vi,mi});
    }
    for(ll i=0; i<k; i++){
        ll ci; cin >> ci;
        bag.push_back(ci);
    }

    sort(jewel.begin(), jewel.end(), jcmp);
    sort(bag.begin(), bag.end());

    ll piv=0, ans=0;
    for(ll i=0; i<k; i++){
        if(piv<n){
            while(piv<n && jewel[piv].second<=bag[i]){
                pq.push(jewel[piv]);
                piv++;
            }
        }
        if(pq.size()){
            ans+=pq.top().first;
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}