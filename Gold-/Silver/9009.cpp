#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int arr[50];
    arr[0]=0; arr[1]=1;
    for(int i=2; i<47; i++) arr[i]=arr[i-2]+arr[i-1];
    
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        int piv=0, nn=n;
        stack<int> s;
        while(arr[piv]<=n) piv++;
        while(piv--){
        	if(nn>=arr[piv]){
        		nn-=arr[piv];
        		s.push(arr[piv]);
        	}
        }
        while(!s.empty()){
        	cout << s.top() << ' ';
        	s.pop();
        }
        cout << '\n';
    }

    return 0;
}