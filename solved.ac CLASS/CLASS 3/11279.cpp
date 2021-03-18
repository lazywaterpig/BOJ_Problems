#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main(){
    fastio;
    int n, tmp;
    cin >> n;

    priority_queue <int> pq;
    while(n--){
        cin >> tmp;
        if(!tmp){
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(tmp);
    }

    return 0;
}