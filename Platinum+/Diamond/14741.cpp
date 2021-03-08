#include <bits/stdc++.h>
using namespace std;

int arr[1010101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i, n, zero, maxi;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]==0) zero=i;
        if(arr[i]==n-1) maxi=i;
    }
    bool flag=true;
    int piv=zero;
    int mod=arr[(zero+1)%n]-arr[zero];
    int copr=1;
    for(i=0; i<mod; i++){
        int tmp=i;
        if(i==1){
            copr=arr[piv%n];
            if(copr>=mod){
                flag=false;
            }
        }
        tmp*=copr;
        tmp%=mod;
        while(tmp<n){
            if(tmp!=arr[piv%n]){
                flag=false;
                break;
            }
            piv++;
            tmp+=mod;
        }
    }
    if(flag==true && (__gcd(copr, mod)==1 && copr<mod)) cout << "NIE" << '\n';
    else{
        flag=true;
        piv=zero;
        mod=abs(arr[(zero-1+n)%n]-arr[zero]);
        copr=1;
        for(i=0; i<mod; i++){
            int tmp=i;
            if(i==1){
                copr=arr[piv%n];
                if(copr>=mod){
                    flag=false;
                }
            }
            tmp*=copr;
            tmp%=mod;
            while(tmp<n){
                if(tmp!=arr[piv%n]){
                    flag=false;
                    break;
                }
                piv--;
                tmp+=mod;
            }
        }
        if(flag==true && (__gcd(copr, mod)==1 && copr<mod)) cout << "NIE" << '\n';
        else cout << "TAK" << '\n';
    }
    return 0;
}