#include <bits/stdc++.h>
using namespace std;

int arr[2048];
int prefix_sum[2048];

void Swap(int a, int b, int sz){
    for(int i=0; i<sz/2; i++){
        swap(arr[a+i], arr[b+i]);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; n=n*2-1;
    for(int i=0; i<n; i++) cin >> arr[i];

    int sz=2;
    while(sz<n){
        prefix_sum[0]=arr[0];
        for(int i=0; i<n; i++){
            prefix_sum[i]=prefix_sum[i-1]+arr[i];
        }

        int cnt=0, tmp_idx, idx_type;
        for(int i=0; i<n+1-sz; i+=sz){
            if((prefix_sum[i+sz-1]-(i==0?0:prefix_sum[i-1]))%sz){
                if(cnt==0){
                    cnt=1;
                    tmp_idx=i;
                    if((prefix_sum[i+sz/2-1]-(i==0?0:prefix_sum[i-1]))%sz) idx_type=0;
                    else idx_type=1;
                }
                else{
                    cnt=0;
                    if((prefix_sum[i+sz/2-1]-prefix_sum[i-1])%sz) Swap(tmp_idx+sz*idx_type/2, i+sz/2, sz);
                    else Swap(tmp_idx+sz*idx_type/2, i, sz);
                }
            }
        }

        if(cnt){
            if((prefix_sum[n-sz/2]-prefix_sum[n-sz])%sz) Swap(tmp_idx+sz*(idx_type^1)/2, n-sz+1, sz);
            else Swap(tmp_idx+sz*idx_type/2, n-sz+1, sz);
        }
        sz*=2;
    }

    for(int i=0; i<n/2+1; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}