#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, r, c, ans=0;
    cin >> n >> r >> c;
    n=(1<<n);
    while(n>0){
        if(r>n/2-1){
            ans+=n*n/2;
            r-=n/2;
        }
        if(c>n/2-1){
            ans+=n*n/4;
            c-=n/2;
        }
        n/=2;
    }
    cout << ans << endl;
    return 0;
}