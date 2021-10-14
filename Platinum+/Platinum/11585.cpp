#include <bits/stdc++.h>
using namespace std;

vector<char> arr, meat, p;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    arr.resize(2*n); meat.resize(n);
    p.resize(n, 0);
    for(int i=0; i<n; i++) cin >> meat[i];
    for(int i=0; i<n; i++) cin >> meat[i];

    for(int i=0; i<2*n; i++) arr[i]=meat[i%n];
    int piv=0;
    for(int i=1; i<n; i++){
        while(piv>0 && arr[i]!=arr[piv]) piv=p[piv-1];
        if(arr[i]==arr[piv]){
            piv++;
            p[i]=piv;
        }
    }

    piv=0;
    int cnt=0;
    for(int i=0; i<2*n-1; i++){
        while(piv>0 && arr[i]!=arr[piv]) piv=p[piv-1];
        if(arr[i]==arr[piv]){
            if(piv==n-1){ cnt++; piv=p[piv]; }
            else piv++;
        }
    }

	int g=__gcd(n, cnt);
    cout << cnt/g << '/' << n/g;
    return 0;
}