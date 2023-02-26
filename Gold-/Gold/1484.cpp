#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define INF 1e9+7
#define piii pair<int,pair<int,int>>
#define fi first
#define se second
#define endl '\n';
using namespace std;

int arr[100100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    int piv=1, flag=0;
    for(int i=1; i<=n; i++){
        while(i*i-piv*piv>n) piv++;
        if(i*i-piv*piv==n){
            flag=1;
            cout << i << endl;
        }
    }

    if(!flag) cout << "-1";
    return 0;
}