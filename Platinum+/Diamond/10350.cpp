#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int arr[20002]={0};
    int tmp;
    long long sum=0;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=2; i<=n; i++) arr[i]+=arr[i-1];
    for(int i=1; i<=n; i++) arr[i+n]+=arr[i]+arr[n];
    
	for(int i=0; i<n; i++){
		for(int j=i+1; j<=i+n; j++){
			tmp=arr[j]-arr[i];
			if(tmp<0){
				sum+=((tmp*(-1))-1)/arr[n]+1;
			}
		}
	}

	cout << sum;
    return 0;
}