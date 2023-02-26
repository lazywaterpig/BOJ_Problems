#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        queue<int> ans;

        priority_queue<int> pq_l;
        priority_queue<int, vector<int>, greater<int>> pq_h;
        if(n<3){
            int tmp; cin >> tmp;
            cout << "1\n" << tmp << '\n';
            if(n==2) cin >> tmp;
            continue;
        }

        int a, b; cin >> a >> b;
        ans.push(a);
        if(a>b) swap(a,b);
        pq_l.push(a);
        pq_h.push(b);
        
        for(int i=2; i<n; i++){
            int cur; cin >> cur;

            if(i%2){ // 짝
                if(pq_h.top()<cur){
                    pq_h.push(cur);
                    cur=pq_h.top();
                    pq_h.pop();
                }
                pq_l.push(cur);
            }
            else{
                if(pq_l.top()>cur){
                    pq_l.push(cur);
                    cur=pq_l.top();
                    pq_l.pop();
                }
                pq_h.push(cur);
                ans.push(pq_h.top());
            }
        }

        cout << (n+1)/2 << '\n';
        for(int i=0; i<(n+1)/2; i++){
            cout << ans.front() << ' ';
            ans.pop();
        }
        cout << '\n';
    }
    return 0;
}