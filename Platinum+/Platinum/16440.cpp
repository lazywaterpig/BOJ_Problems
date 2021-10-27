#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int cnt[2]={0}, piv=n/2;
    for(int i=0; i<n/2; i++) cnt[(s[i]=='s'?0:1)]++;
    while(1){
        if(cnt[0]-cnt[1]){
            cnt[(s[piv]=='s'?0:1)]++;
            cnt[(s[piv-n/2]=='s'?0:1)]--;
            piv++;
        }
        else break;
    }
    if(!(piv-n/2)) cout << "1\n" << piv;
    else cout << "2\n" << piv-n/2 << ' ' << piv;
    return 0;
}