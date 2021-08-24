#include <bits/stdc++.h>
using namespace std;

#define MAX 2147483647
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n, k;
    ll tmp;
    ll primelist[101];
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    queue <ll> q_tmp;

    cin >> k >> n;
    for(i=0; i<k; i++) cin >> primelist[i];
    sort(primelist, primelist+k);

    for(i=0; i<k; i++) cin >> primelist[i];
    sort(primelist, primelist+k);

    for(i=0; i<k; i++){
        int sss=pq.size();
        int sz=min(100000, sss);
        for(j=0; j<sz; j++){
            q_tmp.push(pq.top());
            pq.pop();
        }
        pq=priority_queue <ll, vector<ll>, greater<ll>>();

        for(j=0; j<sz; j++){
            tmp=q_tmp.front();
            while(tmp<=MAX){
                pq.push(tmp);
                tmp*=primelist[i];
            }
            q_tmp.pop();
        }

        tmp=primelist[i];
        while(tmp<=MAX){
            pq.push(tmp);
            tmp*=primelist[i];
        }
    }

    for(i=0; i<n-1; i++) pq.pop();
    cout << pq.top();
    return 0;
}