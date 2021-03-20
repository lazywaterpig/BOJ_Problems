#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime[50000];
ll plist[5150], pcnt=0;
ll tmp;

bool isnono(int d){
    for(int i=2; i*i<=d; i++){
        if(d%(i*i)==0) return false;
    }
    return true;
}

void backtrack(ll cur, ll d, int flag, int lower_bound){
    if(cur>d) return;

    tmp+=flag*(d/cur);
    for(int i=lower_bound+1; ; i++){
        ll val=cur*plist[i]*plist[i];
        if(val>d) break;

        backtrack(val, d, -flag, i);
    }
}

ll nonocnt(ll d){
    tmp=0;
    backtrack(1, d, 1, -1);
    return tmp;
}

ll binarySearch(ll size, ll d){
	ll s=d;
	ll e=size;
	ll m;
	while(s<=e){
		m=(s+e)/2;
        ll val=nonocnt(m);

		if(val==d) return m;
		else if(val>d) e=m-1;
		else s=m+1;
	}
	return 0;
}

void primelistmaker(){
	ll i, j;
	prime[1]=false;
	for(i=2; i<50000; i++){
		if(prime[i]){
            plist[pcnt]=i;
            pcnt++;
			j=i*2;
			while(j<50000){
				prime[j]=false;
				j+=i;
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(prime, true, sizeof(prime));
    primelistmaker();

    ll k; cin >> k;
    ll res=binarySearch(5*k/2, k);

    while(!isnono(res)) res--;

    cout << res << endl;
    return 0;
}