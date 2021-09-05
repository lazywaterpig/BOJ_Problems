#include <bits/stdc++.h>
using namespace std;

int arr[100002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int s=0, e=n-1;
    int res1=1000000001, res2=1000000001;

    while(s<e){
        if(abs(res1+res2)>abs(arr[s]+arr[e])){
            res1=arr[s];
            res2=arr[e];
        }

        if(abs(arr[s])>abs(arr[e])) s++;
        else e--;
    }

    cout << res1 << ' ' << res2;
    return 0;
}