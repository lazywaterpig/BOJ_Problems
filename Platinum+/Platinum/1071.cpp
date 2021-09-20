#include <bits/stdc++.h>
using namespace std;

int arr[1002];
int cnt[1002]={0};
int sum[1002]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for(int i=1000; i>=0; i--) sum[i]=cnt[i]+sum[i+1];

	int lastout=-2;
    for(int i=0; i<n; i++){
        int piv=0;
        while(sum[piv+1]>0){
        	if(cnt[piv]>0 && (sum[piv+2]>0 || sum[0]-sum[piv]>0) && lastout+1!=piv) break;
            piv++;
        }
        cout << piv << ' ';
        lastout=piv;
        cnt[piv]--;
        for(int j=0; j<=piv; j++) sum[j]--;
    }

    return 0;
}