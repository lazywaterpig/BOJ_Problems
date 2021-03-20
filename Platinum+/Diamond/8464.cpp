#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;

bool prime[500001];
i128 plist[45000], pcnt=0;
i128 tmp;

bool isnono(i128 d){
    for(i128 i=2; i*i<=d; i++){
        if(d%(i*i)==0) return true;
    }
    return false;
}

void backtrack(i128 cur, i128 d, i128 flag, i128 lower_bound){
    if(cur>d) return;

    tmp+=flag*(d/cur);
    for(i128 i=lower_bound+1; ; i++){
        i128 val=cur*plist[i]*plist[i];
        if(val>d) break;

        backtrack(val, d, -flag, i);
    }
}

i128 nonocnt(i128 d){
    tmp=0;
    backtrack(1, d, 1, -1);
    return d-tmp;
}

i128 binarySearch(i128 size, i128 d){
	i128 s=d;
	i128 e=size;
	i128 m;
	while(s<=e){
		m=(s+e)/2;
        i128 val=nonocnt(m);

		if(val==d) return m;
		else if(val>d) e=m-1;
		else s=m+1;
	}
	return 0;
}

void primelistmaker(){
	i128 i, j;
	prime[1]=false;
	for(i=2; i<500001; i++){
		if(prime[i]){
            plist[pcnt]=i;
            pcnt++;
			j=i*2;
			while(j<500001){
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
    ll res=binarySearch(5*k, k);

    while(!isnono(res)) res--;

    cout << res << endl;
    return 0;
}