#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[5002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    ll s=0, e=n-1;
    ll res1=1000000001, res2=1000000001, res3=1000000001;

    for(ll i=0; i<n-2; i++){
        for(ll j=i+2; j<n; j++){
            ll left=i+1, right=j-1;
            while(left<=right){
                ll mid=(left+right)/2;
                if(abs(arr[i]+arr[mid]+arr[j])<abs(res1+res2+res3)){
                    res1=arr[i];
                    res2=arr[mid];
                    res3=arr[j];
                }

                if(arr[i]+arr[mid]+arr[j]>0) right=mid-1;
                else left=mid+1;
            }
        }
    }

    cout << res1 << ' ' << res2 << ' ' << res3;
    return 0;
}