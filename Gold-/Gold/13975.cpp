#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--){
        int n, tmp; cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n--){
            cin >> tmp;
            pq.push(tmp);
        }

        long long ans=0;
        int a, b;
        while(pq.size()>1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        cout << ans << '\n';
    }
    return 0;
}