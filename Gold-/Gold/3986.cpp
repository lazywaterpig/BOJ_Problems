#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt, cnt=0; cin >> tt;
    while(tt--){
        string s; cin >> s;
        stack <char> st;
        int sz=s.size();
        for(int i=0; i<sz; i++){
            if(!st.empty() && st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }
        if(st.empty()) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}