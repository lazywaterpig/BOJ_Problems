#include <bits/stdc++.h>
using namespace std;

int fib[100];

int solve(int N){
    for(int i=1; ; i++){
        if(fib[i]>N) break;

        if(N==fib[i]){
            return N;
        }
    }

    int piv=2;
    while(fib[piv]<N) piv++;
    return solve(N-fib[piv-1]);
}

int main(){
    int n;
    cin >> n;
    fib[0]=1;
    fib[1]=1;
    for(int i=2; ; i++){
        if(fib[i-1]+fib[i-2]>1000000){
            fib[i]=fib[i-1]+fib[i-2];
            break;
        }

        fib[i]=fib[i-1]+fib[i-2];
        if(n==fib[i]){
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << solve(n) << endl;
    return 0;
}