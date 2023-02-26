#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int sz=s.size(), ans=2;

    if(sz<9){
        int x=stoi(s);
        while(x!=1){
            x/=ans;
            ans++;
        }
    }
    else{
        ans=2;
        double logsum=0;
        while(floor(logsum)<sz-1){ // ref - coconut99
            logsum+=log10(ans);
            ans++;
        }
    }
    
    cout << ans-1;
    return 0;
}