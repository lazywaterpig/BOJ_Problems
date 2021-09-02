#include <bits/stdc++.h>
using namespace std;

void solve(string p, string i){
    if(p.size()==0) return;

    int sz=p.size();
    char root=p[0];
    int l=find(i.begin(), i.end(), root)-i.begin();
    int r=sz-l-1;
    solve(p.substr(1,l), i.substr(0,l-1));
    solve(p.substr(l+1,sz), i.substr(l+1,sz));

    cout << root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        string pre_ord, in_ord;
        cin >> pre_ord >> in_ord;
        if(pre_ord.size()==0) break;

        solve(pre_ord, in_ord);
        cout << "\n";
    }
    return 0;
}