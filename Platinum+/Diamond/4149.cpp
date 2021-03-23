#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;

vector<ll> alist={2,3,5,7,11,13,17,19,23,29,31,37,41,43};

ll mul(ll x, ll y, ll m){
    return (i128)x*y%m;
}

ll fastpow(ll x, ll y, ll m){
    x%=m;
    ll r=1ULL;
    while(y){
        if(y&1) r=mul(r, x, m);
        x=mul(x, x, m);
        y>>=1;
    }
    return r;
}

bool Miller_Rabin(ll n, ll a){
    ll d=n-1;
    while(!(d&1)){
        if(fastpow(a, d, n)==n-1) return true;
        d>>1;
    }
    ll tmp=fastpow(a, d, n);
    return (tmp==n-1 || tmp==1);
}

bool isPrime(ll n){
    if(n<=1) return false;
    if(n<=1e6){
        for(ll i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    for(ll a : alist){
        if(!Miller_Rabin(n, a)) return false;
    }
    return true;
}

ll c;

ll floyd(ll x, ll n){
    return (mul(x, x, n)+c)%n;
}

void Pollard_Rho(ll n, vector<ll> v){
    if(n==1) return;
    if(!(n&1)){
        v.push_back(2);
        Pollard_Rho(n/2, v);
        return;
    }
    if(isPrime(n)){
        v.push_back(n);
        return;
    }
    ll a, b, r=1;
    a=b=rand()%(n-2)+2;
    c=alist[rand()%13+1];
    while(r==1){
        a=floyd(a, n);
        b=floyd(floyd(b, n), n);
        r=__gcd(abs(a-b), n);
    }
    Pollard_Rho(r, v);
    Pollard_Rho(n/r, v);
}

vector<ll> factorize(ll n){
    vector<ll> res;
    Pollard_Rho(n, res);
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for(auto a:factorize(n)) cout << a << endl;

    return 0;
}