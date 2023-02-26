#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define INF 1e9+7
#define piii pair<int,pair<int,int>>
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    ll cnt=0;
    ll arr[70];
    ll tmp = n;
    int bound = (int)(sqrt(n)+0.999999);
    for(int i=2; i<=bound; i++){
        while(1){
            if(tmp%i) break;
            else{
                arr[cnt]=i;
                cnt++;
                tmp/=i;
            }
        }
    }
    if(tmp!=1){
        arr[cnt]=tmp;
        cnt++;
    }

    if(cnt<4) cout << "-1";
    else{
        if(cnt%2){
            for(int i=0; i<cnt-2; i+=2){
                cout << arr[i]*arr[i+1] << ' ';
            }
            cout << arr[cnt-1]*arr[cnt-2]*arr[cnt-3];
        }
        else{
            for(int i=0; i<cnt; i+=2){
                cout << arr[i]*arr[i+1] << ' ';
            }
        }
    }
    
    return 0;
}