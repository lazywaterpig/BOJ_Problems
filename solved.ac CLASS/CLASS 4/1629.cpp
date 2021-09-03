#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rec(ll a, ll b, ll c){
    if(b==0) return 1%c;

    ll half=rec(a, b/2, c);
    if(b%2==1) return half*half%c*a%c;
    else return half*half%c;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << rec(a, b, c);
}
/*
int main(){
    int a, b, c;
    cin >> a >> b >> c;

    bool binary[33]={0};

    ll arr[33];
    ll tmp;

    arr[0]=1;
    arr[1]=a%c;
    for(int i=2; i<33; i++){
        arr[i]=(arr[i-1]*arr[i-1])%c;
    }

    int binary_piv=1;
    while(b!=0){
        binary[binary_piv]=b%2;
        binary_piv++;
        b/=2;
    }

    ll ans=0;
    bool flag=false;
    for(int i=1; i<binary_piv; i++){
        if(binary[i]==true){
            if(flag==false){ ans=arr[i]; flag=true; }
            else ans=(ans*arr[i])%c;
        }
    }

    cout << ans%c;
    return 0;
}*/