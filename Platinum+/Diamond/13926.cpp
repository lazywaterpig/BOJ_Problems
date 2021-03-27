#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;

vector<ll> res;

ull mul(ull x, ull y, ull m){
    return (ull)((i128)x*y%m);
}

ull fastpow(ull x, ull y, ull m){
    ull r=1;
    x%=m;
    while(y){
        if(y&1) r=mul(r, x, m);
        x=mul(x, x, m);
        y>>=1;
    }
    return r;
}

bool Miller_Rabin(ull n, ull a){
	if(n%a==0) return false;
	int cnt=0;
    ull d=n-1;
    while(d%2==0){
        d>>=1;
        cnt++;
    }
    cnt--;
    
    ull tmp=fastpow(a, d, n);
    if(tmp==1 || tmp==n-1) return true;
    while(cnt--){
        tmp=mul(tmp, tmp, n);
        if(tmp==n-1) return true;
    }
    return false;
}

bool isPrime(ll n){
	if(n<=1) return false;
	for(auto a : {2,3,5,7,11,13,17,19,23,29,31,37}){
	    if(n == a) return true;
		if(n>40 && !Miller_Rabin(n, a)) return false;
	}
	if(n<=40) return false;
	return true;
}

ll Pollard_Rho(ll n){
    ll x, y, c, r;
    x=rand()%(n-2)+2; y=x;
    c=rand()%(n-1)+1;
    
    auto f=[=](ll x){
		return (mul(x, x, n)+c)%n;
	};
	
    while(1){
        x=f(x);
        y=f(f(y));
        r=__gcd(abs(x-y), n);
        if(r==1) continue;

        if(!isPrime(r)) return Pollard_Rho(r);
        else return r;
    }
}

void factorize(ll n){
    while(n%2==0){
        n>>=1;
        res.push_back(2);
    }
    if(n==1) return;
    while(!isPrime(n)){
        ll r=Pollard_Rho(n);
        while(n%r==0){
            res.push_back(r);
            n/=r;
        }
        if(n==1) return;
    }
    if(n>1) res.push_back(n);
}

int main(){
    ll n; cin >> n;
    factorize(n);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    ll ans=n;
    for(auto a:res){
        ans/=a;
        ans*=(a-1);
    }
    cout << ans << endl;
    return 0;
}