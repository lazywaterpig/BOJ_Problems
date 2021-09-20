#include <bits/stdc++.h>
using namespace std;

double arr[1002][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    double T;
    int n; cin >> T >> n;
    T+=0.000005;
    for(int i=0; i<n; i++){
        cin >> arr[i][0];
        arr[i][1]=1;
    }

	double maxv=0, minv=1e9+1;
	int cnt;
    for(int i=0; i<n; i++){
        if(arr[i][0]>maxv) maxv=arr[i][0];
        if(arr[i][0]<minv) minv=arr[i][0];
    }
    if(minv/maxv>T) cnt=0;
    else cnt=1;

    while(cnt){
        double tmp;
        double ans_tmp=1e9+1;
        double maxv=0, maxv2=0, minv=1e9+1;
        int maxi, maxi2, mini;
        for(int i=0; i<n; i++){
            tmp=arr[i][0]/arr[i][1];
            if(maxv<tmp){
            	maxv2=maxv;
                maxv=tmp;
                maxi=i;
            }
            else if(maxv2<tmp) maxv2=tmp;
            
            if(minv>tmp) minv=tmp;
        }
        arr[maxi][1]+=1;
		tmp=arr[maxi][0]/arr[maxi][1];
        ans_tmp=min(tmp,minv)/max(tmp, maxv2);
        
        if(ans_tmp>T) break;
        cnt++;
    }

    cout << cnt;
    return 0;
}