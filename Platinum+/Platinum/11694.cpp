#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[101];
    int n; cin >> n;
    int one=0, oneii=-1;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]==1){
            one++;
            if(oneii==-1) oneii=i;
        }
    }
    if(one==n)
        cout << ((n%2==0)? "koosaga":"cubelover");
    else{
        if(!one && one%2==0) arr[oneii]=1;
        int nim=0;
        for(int i=0; i<n; i++) nim^=arr[i];
        cout << ((nim!=0)? "koosaga":"cubelover");
    }
    return 0;
}