#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, v;
    stack <int> s;
    cin >> n;

    while(n--){
        string ss; cin >> ss;
        if(ss == "push"){
            int num; cin >> num;
            s.push(num);
        }
        else if(ss == "pop"){
            if(!s.empty()){
                cout << s.top() << "\n";
                s.pop();
            }
            else cout << "-1\n";
        }
        else if(ss == "size"){
            cout << s.size() << "\n";
        }
        else if(ss == "empty"){
            cout << (s.empty()?"1\n":"0\n");
        }
        else if(ss == "top"){
            if(s.empty()) cout << "-1\n";
            else cout << s.top() << "\n";
        }
    }

    return 0;
}