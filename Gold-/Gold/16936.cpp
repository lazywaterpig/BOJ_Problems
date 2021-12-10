#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;

bool cmp(pair<ll, pair<ll,ll>> a, pair<ll, pair<ll,ll>> b){
    if(a.y.x==b.y.x) return a.y.y>b.y.y;
    return a.y.x<b.y.x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<ll, pair<ll,ll>> arr[101];
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i].x;
        arr[i].y.x=arr[i].y.y=0;
        ll tmp=arr[i].x;
        while(tmp%2==0){
            arr[i].y.x++;
            tmp/=2;
        }
        while(tmp%3==0){
            arr[i].y.y++;
            tmp/=3;
        }
    }

    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++) cout << arr[i].x << ' ';

    return 0;
}