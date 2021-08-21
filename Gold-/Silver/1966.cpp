#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int tt;
    cin >> tt;
    while(tt--){
	    int i, j, n, m, tmp, flag=0, cnt=1;
        int arr[101], priority[101];
	    
	    cin >> n >> m;
        for(i=0; i<n; i++){
            cin >> arr[i];
            priority[i]=arr[i];
        }

        sort(priority, priority+n);
        int piv=0, pri_piv=n-1;

        while(1){
            if(piv==n) piv=0;
            if(priority[pri_piv]==arr[piv]){
                if(piv==m){
                    flag=1;
                    break;
                }
                else{
                    cnt++;
                    pri_piv--;
                }
            }
            if(flag==1) break;

            piv++;
        }
        cout << cnt << "\n";
    }
	return 0;
}