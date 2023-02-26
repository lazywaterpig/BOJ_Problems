#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m; cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> pq, cost;
    priority_queue<pii, vector<pii>, greater<pii>> pq2, cost2;
    while(n--){
        ll a, b; cin >> a >> b;
        pq.push({a,b});
    }
    while(m--){
        ll a, b; cin >> a >> b;
        cost.push({a,b});
    }

    ll cnt=0, maskcnt=0;
    pii cur, mask=cost.top();
    while(!pq.empty() && !cost.empty()){
        cur=pq.top();
        if(mask.first!= cost.top().first || mask.second!= cost.top().second) mask=cost.top();
        
        if(cur.first>mask.first){
            cost2.push({cost.top().first, cost.top().second - maskcnt});
            maskcnt=0;
            cost.pop();
        }
        else if(mask.first>cur.second){
            pq2.push({pq.top().second, pq.top().first});
            pq.pop();
        }
        else{
            maskcnt++;
            cnt++;
            pq.pop();

            if(maskcnt==mask.second){
                maskcnt=0;
                cost.pop();
            }
        }
    }

    maskcnt=0;
    if(!cost2.empty()) mask=cost.top();
    
    while(!pq2.empty() && !cost2.empty()){
        cur=pq2.top();
        if(mask.first!= cost2.top().first || mask.second!= cost2.top().second) mask=cost2.top();
        
        if(cur.second>mask.first){
            maskcnt=0;
            cost2.pop();
        }
        else if(mask.first>cur.first) pq2.pop();
        else{
            maskcnt++;
            cnt++;
            pq2.pop();

            if(maskcnt==mask.second){
                maskcnt=0;
                cost2.pop();
            }
        }
    }
    
    cout << cnt;
    return 0;
}