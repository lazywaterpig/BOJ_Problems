#include <stdio.h>
#include <algorithm>
using namespace std;

typedef __int128 i128;
void print(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main(){
	int n, m;
    scanf("%d %d", &n, &m);

    int arr[101];
    for(int i=1; i<=n-m; i++) arr[i]=1;
    for(int i=n-m+1; i<=n; i++) arr[i]=i;
    for(int i=1; i<=m; i++){
        int tmp=i;
        for(int j=n; j>n-m; j--){
            if(tmp==1) break;
            if(__gcd(arr[j], tmp)!=1){
                int val=__gcd(arr[j], tmp);
                arr[j]/=val;
                tmp/=val;
            }
        }
    }

    i128 ans=1;
    for(int i=1; i<=n; i++) ans*=arr[i];
    print(ans);
    printf("\n");

    return 0;
}