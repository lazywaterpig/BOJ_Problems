#include <bits/stdc++.h>
using namespace std;

long long cnt[1002]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long i, j, n, m, v=0, tmp, ans=0;
    cin >> n >> m;

    cnt[0]++;
    for(i=0; i<n; i++){
        cin >> tmp;
        v=(v+tmp)%m;
        cnt[v]++;
    }

    while(m--) ans+=cnt[m]*(cnt[m]-1)/2;

    cout << ans;
    return 0;
}