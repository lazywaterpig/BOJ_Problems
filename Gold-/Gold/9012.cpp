#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--){
        string s; cin >> s;
        int sz = s.size(), cnt=0, flag=0;
        while(sz--){
            if(cnt>0){
                flag=1; break;
            }
            else{
                if(s[sz] == ')') cnt--;
                else cnt++;
            }
        }

        if(!flag && cnt==0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}