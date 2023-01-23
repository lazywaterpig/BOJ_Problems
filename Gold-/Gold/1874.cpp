#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, piv=1, flag=0; cin >> n;
    stack <int> s;
    queue <char> ans;

    for(int i=0; i<n; i++){
        int ord; cin >> ord;
        if(piv<=ord){
            for(; piv<ord; piv++){
            	s.push(piv);
            	ans.push('+');
            }
            piv++;
            ans.push('+');
            ans.push('-');
        }
        else if(!s.empty() && s.top()==ord){
            s.pop();
            ans.push('-');
        }
        else flag=1;
    }

    if(flag) cout << "NO\n";
    else{
        int sz=ans.size();
        while(sz--){
            cout << ans.front() << "\n";
            ans.pop();
        }
    }
    return 0;
}