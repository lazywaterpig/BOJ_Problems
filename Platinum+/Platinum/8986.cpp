#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<ll> v;

ll dist(ll a){
    ll sum=0;
    for(int i=1; i<n; i++){
        sum+=abs(v[i]-a*i);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i];

    ll m1=0, m2=1e9;
    ll l=0, r=(v[n-1]*2+1)/n;

    while(m1+1<m2){
        m1=(2*l+r)/3;
        m2=(l+2*r)/3;

        if(dist(l)>dist(r)) l=m1;
        else r=m2;
    }

    cout << min(dist(m1),dist(m2));
    return 0;
}