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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int cnt=0;
    while(t--){
        int tmp; cin >> tmp;
        if(isPrime(2*tmp+1)) cnt++;
    }
    cout << cnt;
    return 0;
}

/* 참고 - kipa00님 풀이

bool isprime[101];

bool mr(uint n) {
    int s = 0;
    uint m = n - 1;
    while (!(m & 1)) {
        ++s;
        m >>= 1;
    }
    if (n <= 100) {
        return isprime[n];
    }
    for (int a : {2, 7, 61}) {
        uint r = 1, p = a, mm = m;
        while (mm) {
            if (mm & 1) {
                r = ((ulli)r * p) % n;
            }
            mm >>= 1;
            p = ((ulli)p * p) % n;
        }
        mm = n - 1;
        if (r == 1 || r == mm) {
            continue;
        }
        int ss = s;
        while (--ss) {
            r = ((ulli)r * r) % n;
            if (r == 1) {
                return false;
            } else if (r == mm) {
                break;
            }
        }
        if (ss <= 0) {
            return false;
        }
    }
    return true;
}

*/