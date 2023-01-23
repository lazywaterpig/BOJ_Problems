#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, cnt=0; cin >> n >> p;

    vector<stack<int>> v;
    stack<int> s;

    for(int i=0; i<6; i++) v.push_back(s);
    
    while(n--){
        int a, b;
        cin >> a >> b;
        a--;
        if(v[a].empty()){
            cnt++;
            v[a].push(b);
        }
        else{
            while(!v[a].empty() && v[a].top()>b){
                cnt++;
                v[a].pop();
            }
            if(v[a].empty() || v[a].top()<b){
                cnt++;
                v[a].push(b);
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}