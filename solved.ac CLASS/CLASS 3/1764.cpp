#include <bits/stdc++.h>
using namespace std;

vector <string> h;
vector <string> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    h.resize(n);
    s.resize(m);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<m; i++) cin >> s[i];
    
    sort(h.begin(), h.end());
    sort(s.begin(), s.end());

    int cnt=0;
    int hpiv=0, spiv=0;
    queue <string> q;
    while(hpiv<n && spiv<m){
        if(h[hpiv]==s[spiv]){
            q.push(h[hpiv]);
            cnt++;
            hpiv++;
            spiv++;
        }
        else if(h[hpiv]>s[spiv]) spiv++;
        else hpiv++;
    }
    cout << cnt << endl;
    while(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
    }
    return 0;
}