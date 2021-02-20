#include <iostream>
using namespace std;
#define ll long long
ll A, B, K, n=1;

int main(){
    cin >> A >> B >> K;
    if(A==0) cout << 0;
    else{
        if(A%2==1 && K%2==0 || K==0) cout << -1;
        else{
            while(n<=A+B){
                if((K*n>=A && (K*n-A)%2==0) && (K*n)<=((((n+1)/2)*2-1)*A+(n/2)*2*B)) break;
                n++;
            }
            if(n>A+B) n=-1;
            cout << n;
        }
    }
}