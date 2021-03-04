#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, t, n;
    long long int arr[101];
    cin >> t;
    arr[1]=arr[2]=arr[3]=1;
    arr[4]=arr[5]=2;
    
    for(i=6; i<101; i++) arr[i]=arr[i-1]+arr[i-5];
    while(t--){
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}