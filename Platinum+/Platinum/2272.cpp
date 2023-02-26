#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool arr[1001001], narr[1001001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i=n-1; i>-1; i--) cin >> arr[i];

    int val=1;
    while(m){
        if(m%2){
            for(int i=0; i<n; i++) narr[i]=arr[i];
            for(int i=0; i<n; i++){
                if(arr[i]) narr[(i+val)%n]=!narr[(i+val)%n];
            }
            for(int i=0; i<n; i++) arr[i]=narr[i];
        }
        m/=2;
        val*=2;
        val%=n;
    }
    
    for(int i=n-1; i>-1; i--) cout << arr[i] << '\n';
    return 0;
}