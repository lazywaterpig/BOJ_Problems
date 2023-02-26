#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define SIZE 200200
#define MOD 1e9+7
#define piii pair<int,pair<int,int>>
#define fi first
#define se second
using namespace std;

int f[SIZE+1];
int inv[SIZE+1];
void make_com(){
    inv[0] = inv[1] = f[0] = f[1] = 1;
    for (int i = 2; i <=SIZE ; i++)f[i] = 1LL*f[i - 1] * i % MOD;
    for (int i = 2; i <= SIZE ; i++)inv[i] = -1LL * (MOD / i) * inv[MOD % i] % MOD;
    for (int i = 2; i <= SIZE ; i++)inv[i] = 1LL * inv[i - 1] * ((inv[i] + MOD) % MOD) % MOD;
}
int C(int n, int r){return (long long)f[n] * inv[r] % MOD * inv[n - r] % MOD;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    
    ll ans=1;

    if(n==2 || m==2) cout << "2";
    else{
        n--; m--;
        ans=C(n+m, n);
        ans--;
        n--; m--;
        ans-=n+m;
        cout << ans;
    }
    
    return 0;
}