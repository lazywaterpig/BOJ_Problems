#include <bits/stdc++.h>
using namespace std;

int arr[21][300001], cnt[21]={0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int i, j, n, k;
    long long sum=0;
    cin >> n >> k;

    string name;
    int nsize;

    for(i=0; i<n; i++){
        cin >> name;
        nsize=name.size();
        arr[nsize][cnt[nsize]]=i;
        cnt[nsize]++;
    }

    for(i=2; i<21; i++){
        int start=0, end=1;
        while(start<cnt[i] && end<cnt[i]){
            while(end<cnt[i]-1 && arr[i][end]-arr[i][start]<=k) end++;
            if(arr[i][end]-arr[i][start]>k) end--;
            if(start<end) sum+=(end-start);
            start++;
        }
    }

    cout << sum;
	return 0;
}