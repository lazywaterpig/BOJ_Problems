#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        multiset<int> s;
        while(k--){
            char c;
            int n;
            cin >> c >> n;

            if(c=='I') s.insert(n);
            else if(c=='D' && !s.empty()){
                if(n==1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }
        if(!s.empty()) cout << *(--s.end()) << ' ' << *s.begin() << "\n";
        else cout << "EMPTY\n";
    }
    return 0;
}